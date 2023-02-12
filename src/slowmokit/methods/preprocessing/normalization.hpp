/**
 * @file methods/preprocessing/normalization.hpp
 *
 * Easy include to normalize the data
 */

#ifndef SLOWMOKIT_NORMALIZATION_HPP
#define SLOWMOKIT_NORMALIZATION_HPP
#include "../../core.hpp"

/**
 * Takes values to be normalized
 * @param values -> to be normalized
 * @throws warning and sets all values of given column to 1 in case minimum
 * element is equal to maximum element
 */

template <class T>
void normalize(std::vector<T> &);

#endif // SLOWMOKIT_NORMALIZATION_HPP
