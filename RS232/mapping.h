#ifndef MAPPING_H
#define MAPPING_H

#include <math.h>
#include <QList>
#include <QByteArray>
#include "constants.h"


#define FRAME_READY     0
#define INVALID_FRAME   1
#define FRAME_NOT_READY 2

#define BEGIN_KEY           0xAA
#define END_KEY             0xBB
#define UART_FRAME_LENGTH   58

#define VDD_MCU_BASE_STATION    3.315


#define RESOLUTION          (pow((double)2, 12) - 1)
#define DRONE_VOLTAGE_GAIN  4.87

#define B_TERM_LASER        3478.0
#define B_TERM_CELL         3470.0

#define T_AMB               298.0
#define R0_TERM             10000.0

#define RSENSE_CELL         0.025
#define RCUR                100000.0

struct Frame {
    float values[NUM_ITEMS_MONITORED];
    int errors[NUM_ITEMS_MONITORED];
    unsigned char status;
};


struct UART_Frame {
    // Erreurs
    unsigned char errorCurrent;
    unsigned char errorTemperature;
    unsigned char errorVoltage;
    unsigned char errorLaser;
    unsigned char vddHigh;
    unsigned char vddLow;

    // Cellules
    unsigned char vCellPhoto_H;
    unsigned char vCellPhoto_L;
    unsigned char tempCell1_H;
    unsigned char tempCell1_L;
    unsigned char tempCell2_H;
    unsigned char tempCell2_L;
    unsigned char tempCell3_H;
    unsigned char tempCell3_L;
    unsigned char tempCell4_H;
    unsigned char tempCell4_L;
    unsigned char curCell1_H;
    unsigned char curCell1_L;
    unsigned char curCell2_H;
    unsigned char curCell2_L;
    unsigned char curCell3_H;
    unsigned char curCell3_L;
    unsigned char curCell4_H;
    unsigned char curCell4_L;

    // Batterie
    unsigned char vBatCell1_H;
    unsigned char vBatCell1_L;
    unsigned char vBatCell2_H;
    unsigned char vBatCell2_L;
    unsigned char vBatCell3_H;
    unsigned char vBatCell3_L;
    unsigned char vBat_H;
    unsigned char vBat_L;
    unsigned char tempBat_H;
    unsigned char tempBat_L;
    unsigned char curBat_H;
    unsigned char curBat_L;

    // BMS internal
    unsigned char sysReg;   //tmp: will be removed
    unsigned char ctrl1Reg; //tmp: will be removed
    unsigned char ctrl2Reg; //tmp: will be removed
    unsigned char adcGainReg;
    unsigned char offsetReg;

    // Lasers
    unsigned char tempLaser1_H;
    unsigned char tempLaser1_L;
    unsigned char tempLaser2_H;
    unsigned char tempLaser2_L;
    unsigned char tempLaser3_H;
    unsigned char tempLaser3_L;
    unsigned char tempLaser4_H;
    unsigned char tempLaser4_L;

    //Status
    unsigned char status;

    //Voltage from power supply
    unsigned char voltageSupply_H;
    unsigned char voltageSupply_L;
    unsigned char measuredvoltageSupply_H;
    unsigned char measuredvoltageSupply_L;
    //Current from power supply
    unsigned char currentSupply_H;
    unsigned char currentSupply_L;
    unsigned char measuredcurrentSupply_H;
    unsigned char measuredcurrentSupply_L;

};


/**
 * @brief The Mapping class is !!! NOT !!! thread safe.
 */

class Mapping
{
public:
    Mapping();

    void doneReadingUartBuffer();

    void append(QByteArray data);
    bool frameReady();
    Frame readFrame();


private:
    void setVddMCU();

    bool containError(unsigned char err);

    uint16_t to16bits(unsigned char hi, unsigned lo);

    float bytesToDroneVoltage(unsigned char hi, unsigned lo);
    float bytesToBMSVoltage(unsigned char hi, unsigned lo);
    float bytesToBMSVoltageGlobal(unsigned char hi, unsigned lo);


    float bytesToDroneCurrent(unsigned char hi, unsigned lo);
    float bytesToBMSCurrent(unsigned char hi, unsigned lo);

    float bytesToDroneTemp(unsigned char hi, unsigned lo);
    float bytesToBMSTemp(unsigned char hi, unsigned lo);
    float bytesToLaserTemp(unsigned char hi, unsigned lo);

    float calibrateGain();
    float calibrateOffset();


private:
    unsigned char m_uartBuffer[UART_FRAME_LENGTH];
    bool m_uartReadingFrame;
    int m_uartFrameIndex;

    UART_Frame m_uartFrame;
    bool m_frameReady;

    double m_vddMCU;
};

#endif // MAPPING_H
