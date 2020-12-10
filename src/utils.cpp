#include <type_traits>
#include <random>

#include "utils.h"


double randomNumber(double lBorder, double rBorder) {
//    static_assert(std::is_arithmetic<T>::value, "Non-numeric type is provided!");
    double number = (double)rand() / RAND_MAX;
    return lBorder + number * (rBorder - lBorder);
}
