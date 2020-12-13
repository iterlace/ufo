
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

// Initial temperature of golden ingot (K)
const double F_T0 = 300;
// Cooling by recuperator temperature (K)
const double F_TR = 4;
// Heating temperature (K)
const double F_TM = 1337.58;
// Specific heat of gold (kJ/kg)
const double F_C = 0.130;
// Specific heat of fusion of gold (kJ/kg)
const double F_L = 64;
// Efficiency of the recuperator
const double F_EFFICIENCY = 0.4;
// Density of gold
const double F_DENSITY = 19320;



#endif //UFO_CONSTANTS_H
