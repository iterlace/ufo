
#include <type_traits>

#ifndef UFO_UTILS_H
#define UFO_UTILS_H


template<typename T,
         typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type
> T randomNumber(T lBorder, T rBorder);

#endif //UFO_UTILS_H
