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
 * @throws runtime_error when maximum element is equal to minimum element
 */

template <class T>
void normalize(std::vector<T> &);

#endif // SLOWMOKIT_NORMALIZATION_HPP
