#include <type_traits>
#include <random>


template<typename T>
T randomNumber(T lBorder, T rBorder) {
    T number = (T)rand() / RAND_MAX;
    return lBorder + number * (rBorder - lBorder);
}
