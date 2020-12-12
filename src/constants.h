
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
    SPIN,
    TURN,
    ROTATE,
};


// Formulas constants
const double
    F_T0 = 300,          // initial temperature of golden ingot
    F_TR = 4,            // cooling by recuperator temperature
    F_TM = 1337.58,      // heating temperature
    F_C = 0.129,         // specific heat of gold
    F_L = 67,            // specific heat of fusion of gold
    F_EFFICIENCY = 0.7;  // efficiency of the recuperator


#endif //UFO_CONSTANTS_H
