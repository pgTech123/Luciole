#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string.h>

// Items Monitored
#define VOLTAGE_GLOBAL      0

#define TEMPERATURE_CELL1   1
#define TEMPERATURE_CELL2   2
#define TEMPERATURE_CELL3   3
#define TEMPERATURE_CELL4   4

#define CURRENT_CELL1       5
#define CURRENT_CELL2       6
#define CURRENT_CELL3       7
#define CURRENT_CELL4       8

#define TEMPERATURE_LASER1  9
#define TEMPERATURE_LASER2  10
#define TEMPERATURE_LASER3  11
#define TEMPERATURE_LASER4  12

#define BAT_CELL1           13
#define BAT_CELL2           14
#define BAT_CELL3           15
#define BAT_TOT             16
#define BAT_CURRENT         17
#define BAT_TEMPERATURE     18
#define BAT_CELL_BALANCING  19
#define BAT_LEVEL           20

#define BMS_OFFSET          21
#define BMS_GAIN            22

#define POWER_SUPPLY_VOLTAGE    23
#define POWER_SUPPLY_VOLTAGE_MEASURED    24
#define POWER_SUPPLY_CURRENT    25
#define POWER_SUPPLY_CURRENT_MEASURED     26

#define NUM_ITEMS_MONITORED 27


#define RUN_MODE_BIT        0x01
#define EMERGENCY_MODE_BIT  0x02



const char*const ITEMS_MONITORED[NUM_ITEMS_MONITORED] = {
    "VOLTAGE_GLOBAL",
    "TEMPERATURE_CELL1",
    "TEMPERATURE_CELL2",
    "TEMPERATURE_CELL3",
    "TEMPERATURE_CELL4",
    "CURRENT_CELL1",
    "CURRENT_CELL2",
    "CURRENT_CELL3",
    "CURRENT_CELL4",
    "TEMPERATURE_LASER1",
    "TEMPERATURE_LASER2",
    "TEMPERATURE_LASER3",
    "TEMPERATURE_LASER4",
    "BAT_CELL1",
    "BAT_CELL2",
    "BAT_CELL3",
    "BAT_TOT",
    "BAT_CURRENT",
    "BAT_TEMPERATURE",
    "BAT_CELL_BALANCING",
    "BAT_LEVEL",
    "POWER_SUPPLY_VOLTAGE",
    "POWER_SUPPLY_VOLTAGE_MEASURED",
    "POWER_SUPPLY_CURRENT",
    "POWER_SUPPLY_CURRENT_MEASURED"
};


#endif // CONSTANTS_H
