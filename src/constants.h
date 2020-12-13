
#ifndef UFO_CONSTANTS_H
#define UFO_CONSTANTS_H

enum COST {
    ROTATE_COST = 10,
    TURN_COST = 10,
    SPIN_COST = 10,
    CUT_COST = 5,
    DROP_COST = 2,
    ACCEPT_COST = 2,
};

enum COMMAND {
    // Ingot modifications
    SPIN = 'S',
    TURN = 'T',
    ROTATE = 'R',

    // General commands
    PUT = 'P',
    CUT = 'C',
    ACCEPT = 'A',
    DROP = 'D',
    FLY_AWAY = 'F'
};


// Formulas constants

// Initial temperature of golden ingot
const double F_T0 = 300;
// Cooling by recuperator temperature
const double F_TR = 4;
// Heating temperature
const double F_TM = 1337.58;
// Specific heat of gold
const double F_C = 0.129;
// Specific heat of fusion of gold
const double F_L = 67;
// Efficiency of the recuperator
const double F_EFFICIENCY = 0.4;
// Density of gold
const double F_DENSITY = 19.32;
            


#endif //UFO_CONSTANTS_H
