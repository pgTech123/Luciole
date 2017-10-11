#include "mapping.h"

Mapping::Mapping()
{
    m_uartReadingFrame = false;
    m_uartFrameIndex = 0;
    m_frameReady = false;
}

void Mapping::append(QByteArray data)
{
    for(int i = 0; i < data.size(); i++) {
        // Detect begin of frame
        if (!m_uartReadingFrame && data[i] == BEGIN_KEY) {
            m_uartReadingFrame = true;
            m_uartFrameIndex = 0;
            continue;
        }

        if (!m_uartReadingFrame) {
            // We're reading scrap
            continue;
        }

        // At the end of the frame, we expect the end marker
        if (m_uartFrameIndex == UART_FRAME_LENGTH && data[i] == END_KEY) {
            doneReadingUartBuffer();
            m_uartReadingFrame = false;
            m_uartFrameIndex = 0;
        }
        // If we think we're at the end but don't see the end marker, start over
        else if (m_uartFrameIndex >= UART_FRAME_LENGTH) {
            m_uartReadingFrame = false;
            m_uartFrameIndex = 0;
        }
        // Read actual data
        else {
            m_uartBuffer[m_uartFrameIndex] = data[i];
            m_uartFrameIndex++;
        }
    }
}

bool Mapping::frameReady()
{
    return m_frameReady;
}

Frame Mapping::readFrame()
{
    Frame frame;
    if (!m_frameReady) {
        //TODO: Log error
        return frame;
    }

    frame.values[VOLTAGE_GLOBAL] = bytesToDroneVoltage(m_uartFrame.vCellPhoto_H, m_uartFrame.vCellPhoto_L) * DRONE_VOLTAGE_GAIN;

    frame.values[TEMPERATURE_CELL1] = bytesToDroneTemp(m_uartFrame.tempCell1_H, m_uartFrame.tempCell1_L);
    frame.values[TEMPERATURE_CELL2] = bytesToDroneTemp(m_uartFrame.tempCell2_H, m_uartFrame.tempCell2_L);
    frame.values[TEMPERATURE_CELL3] = bytesToDroneTemp(m_uartFrame.tempCell3_H, m_uartFrame.tempCell3_L);
    frame.values[TEMPERATURE_CELL4] = bytesToDroneTemp(m_uartFrame.tempCell4_H, m_uartFrame.tempCell4_L);

    frame.values[CURRENT_CELL1] = bytesToDroneCurrent(m_uartFrame.curCell1_H, m_uartFrame.curCell1_L);
    frame.values[CURRENT_CELL2] = bytesToDroneCurrent(m_uartFrame.curCell2_H, m_uartFrame.curCell2_L);
    frame.values[CURRENT_CELL3] = bytesToDroneCurrent(m_uartFrame.curCell3_H, m_uartFrame.curCell3_L);
    frame.values[CURRENT_CELL4] = bytesToDroneCurrent(m_uartFrame.curCell4_H, m_uartFrame.curCell4_L);

    frame.values[TEMPERATURE_LASER1] = bytesToLaserTemp(m_uartFrame.tempLaser1_H, m_uartFrame.tempLaser1_L);
    frame.values[TEMPERATURE_LASER2] = bytesToLaserTemp(m_uartFrame.tempLaser2_H, m_uartFrame.tempLaser2_L);
    frame.values[TEMPERATURE_LASER3] = bytesToLaserTemp(m_uartFrame.tempLaser3_H, m_uartFrame.tempLaser3_L);
    frame.values[TEMPERATURE_LASER4] = bytesToLaserTemp(m_uartFrame.tempLaser4_H, m_uartFrame.tempLaser4_L);

    frame.values[BAT_CELL1] = bytesToBMSVoltage(m_uartFrame.vBatCell1_H, m_uartFrame.vBatCell1_L);
    frame.values[BAT_CELL2] = bytesToBMSVoltage(m_uartFrame.vBatCell2_H, m_uartFrame.vBatCell2_L);
    frame.values[BAT_CELL3] =  bytesToBMSVoltage(m_uartFrame.vBatCell3_H, m_uartFrame.vBatCell3_L);
    frame.values[BAT_TOT] =  bytesToBMSVoltage(m_uartFrame.vBat_H, m_uartFrame.vBat_L)  * 4;    //FIXME: *4???
    frame.values[BAT_CURRENT] = bytesToBMSCurrent(m_uartFrame.curBat_H, m_uartFrame.curBat_L);
    frame.values[BAT_TEMPERATURE] = bytesToBMSTemp(m_uartFrame.tempBat_H, m_uartFrame.tempBat_L);
    frame.values[BAT_CELL_BALANCING] = 0;   //TODO
    frame.values[BAT_LEVEL] = (frame.values[BAT_TOT]-10.7) * (12.6-10.7) / 100;   // Maybe not best approx...  10.7V = 0%

    frame.values[BMS_GAIN] = calibrateGain();
    frame.values[BMS_OFFSET] = calibrateOffset();

    // Preset everything to 0.
    for(int i = 0; i < NUM_ITEMS_MONITORED; i++){
        frame.errors[i] = 0;
    }

    // Voltage low or voltage high = error
    frame.errors[VOLTAGE_GLOBAL] = m_uartFrame.errorVoltage & 0x01 || m_uartFrame.errorVoltage & 0x10;

    frame.errors[CURRENT_CELL1] = m_uartFrame.errorCurrent & 0x01 || m_uartFrame.errorCurrent & 0x10;
    frame.errors[CURRENT_CELL2] = m_uartFrame.errorCurrent & 0x02 || m_uartFrame.errorCurrent & 0x20;
    frame.errors[CURRENT_CELL3] = m_uartFrame.errorCurrent & 0x04 || m_uartFrame.errorCurrent & 0x40;
    frame.errors[CURRENT_CELL4] = m_uartFrame.errorCurrent & 0x08 || m_uartFrame.errorCurrent & 0x80;

    frame.errors[TEMPERATURE_CELL1] = m_uartFrame.errorTemperature & 0x01 || m_uartFrame.errorTemperature & 0x10;
    frame.errors[TEMPERATURE_CELL2] = m_uartFrame.errorTemperature & 0x02 || m_uartFrame.errorTemperature & 0x20;
    frame.errors[TEMPERATURE_CELL3] = m_uartFrame.errorTemperature & 0x04 || m_uartFrame.errorTemperature & 0x40;
    frame.errors[TEMPERATURE_CELL4] = m_uartFrame.errorTemperature & 0x08 || m_uartFrame.errorTemperature & 0x80;

    return frame;
}

void Mapping::doneReadingUartBuffer()
{
    m_frameReady = false;

    // Errors
    m_uartFrame.errorCurrent = m_uartBuffer[0];
    m_uartFrame.errorVoltage = m_uartBuffer[1];
    m_uartFrame.errorTemperature = m_uartBuffer[2];
    m_uartFrame.errorReserved1 = m_uartBuffer[3];
    m_uartFrame.errorReserved2 = m_uartBuffer[4];
    m_uartFrame.errorReserved3 = m_uartBuffer[5];

    // Cellules
    m_uartFrame.vCellPhoto_H = m_uartBuffer[6];
    m_uartFrame.vCellPhoto_L = m_uartBuffer[7];
    m_uartFrame.tempCell1_H = m_uartBuffer[8];
    m_uartFrame.tempCell1_L = m_uartBuffer[9];
    m_uartFrame.tempCell2_H = m_uartBuffer[10];
    m_uartFrame.tempCell2_L = m_uartBuffer[11];
    m_uartFrame.tempCell3_H = m_uartBuffer[12];
    m_uartFrame.tempCell3_L = m_uartBuffer[13];
    m_uartFrame.tempCell4_H = m_uartBuffer[14];
    m_uartFrame.tempCell4_L = m_uartBuffer[15];
    m_uartFrame.curCell1_H = m_uartBuffer[16];
    m_uartFrame.curCell1_L = m_uartBuffer[17];
    m_uartFrame.curCell2_H = m_uartBuffer[18];
    m_uartFrame.curCell2_L = m_uartBuffer[19];
    m_uartFrame.curCell3_H = m_uartBuffer[20];
    m_uartFrame.curCell3_L = m_uartBuffer[21];
    m_uartFrame.curCell4_H = m_uartBuffer[22];
    m_uartFrame.curCell4_L = m_uartBuffer[23];

    // Batterie
    m_uartFrame.vBatCell1_H = m_uartBuffer[24];
    m_uartFrame.vBatCell1_L = m_uartBuffer[25];
    m_uartFrame.vBatCell2_H = m_uartBuffer[26];
    m_uartFrame.vBatCell2_L = m_uartBuffer[27];
    m_uartFrame.vBatCell3_H = m_uartBuffer[28];
    m_uartFrame.vBatCell3_L = m_uartBuffer[29];
    m_uartFrame.vBat_H = m_uartBuffer[30];
    m_uartFrame.vBat_L = m_uartBuffer[31];
    m_uartFrame.tempBat_H = m_uartBuffer[32];
    m_uartFrame.tempBat_L = m_uartBuffer[33];
    m_uartFrame.curBat_H = m_uartBuffer[34];
    m_uartFrame.curBat_L = m_uartBuffer[35];

    // BMS internal
    m_uartFrame.sysReg = m_uartBuffer[36];
    m_uartFrame.ctrl1Reg = m_uartBuffer[37];
    m_uartFrame.ctrl2Reg = m_uartBuffer[38];
    m_uartFrame.adcGainReg = m_uartBuffer[39];
    m_uartFrame.offsetReg = m_uartBuffer[40];

    // Lasers
    m_uartFrame.tempLaser1_H = m_uartBuffer[41];
    m_uartFrame.tempLaser1_L = m_uartBuffer[42];
    m_uartFrame.tempLaser2_H = m_uartBuffer[43];
    m_uartFrame.tempLaser2_L = m_uartBuffer[44];
    m_uartFrame.tempLaser3_H = m_uartBuffer[45];
    m_uartFrame.tempLaser3_L = m_uartBuffer[46];
    m_uartFrame.tempLaser4_H = m_uartBuffer[47];
    m_uartFrame.tempLaser4_L = m_uartBuffer[48];

    m_frameReady = true;
}


uint16_t Mapping::to16bits(unsigned char hi, unsigned lo)
{
    return (uint16_t)((hi << 8) | lo);
}

float Mapping::bytesToDroneVoltage(unsigned char hi, unsigned lo)
{
    uint16_t value = to16bits(hi, lo);
    float result = value * VCC / RESOLUTION;
    return result;
}

float Mapping::bytesToBMSVoltage(unsigned char hi, unsigned lo)
{
    uint16_t value = to16bits(hi, lo);
    float gain = calibrateGain();
    float offset = calibrateOffset();
    float result = (gain * (float)value + offset)/1000;
    return result;
}

float Mapping::bytesToDroneCurrent(unsigned char hi, unsigned lo)
{
    float voltage = bytesToDroneVoltage(hi, lo);
    float result = (voltage * 5000) / (RSENSE_CELL * RCUR); //See INA138NA/3K datasheet
    return result;
}

float Mapping::bytesToBMSCurrent(unsigned char hi, unsigned lo)
{
    uint16_t value = to16bits(hi, lo);
    float result = value * 0.00000844/0.005;
    return result;
}

float Mapping::bytesToDroneTemp(unsigned char hi, unsigned lo)
{
    float voltage = bytesToDroneVoltage(hi, lo);
    float rTherm = ((voltage/VCC) * R0_TERM) / (1- voltage/VCC);
    float temperature = B_TERM_CELL/(log(rTherm/(R0_TERM*exp(-B_TERM_CELL/T_AMB))))-273;
    return temperature;
}

float Mapping::bytesToBMSTemp(unsigned char hi, unsigned lo)
{
    float voltage = (float)to16bits(hi, lo) * 0.000382;
    float rTherm = (voltage * R0_TERM) / (3.3 - voltage);
    float k = rTherm / R0_TERM;
    float ln = log(k);
    float temperature = (1 / ((1 / T_AMB) + (1/B_TERM_CELL) * ln)) - 273.15;
    return temperature;
}

float Mapping::bytesToLaserTemp(unsigned char hi, unsigned lo)
{
    float voltage = bytesToDroneVoltage(hi, lo);
    float rTherm = ((voltage/VCC) * R0_TERM) / (1- voltage/VCC);
    float temperature = B_TERM_LASER/(log(rTherm/(R0_TERM*exp(-B_TERM_LASER/T_AMB))))-273;
    return temperature;
}

float Mapping::calibrateGain()
{
    return ((float)m_uartFrame.adcGainReg+365)/1000;
}

float Mapping::calibrateOffset()
{
    float result = 0;
    unsigned char tmpOffset = m_uartFrame.offsetReg;
    uint8_t d = tmpOffset & 1 << 7;
    if(d != 0) {
        tmpOffset = (~tmpOffset) + 1;
        result = -tmpOffset;
    } else {
        result = tmpOffset;
    }
    return result;
}
