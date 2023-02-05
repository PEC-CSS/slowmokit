/**
 * @file methods/preprocessing/normalization.hpp
 *
 * Easy include to normalize the data
 */

#ifndef SLOWMOKIT_STANDARDIZATION_HPP
#define SLOWMOKIT_STANDARDIZATION_HPP
#include "../../core.hpp"

/**
 * Takes values to be standardized
 * @param values -> to be standardized
 * @throws runtime_error when standard deviation is equal to zero 
 */

template <class T>
void standardize(std::vector<T> &);

#endif // SLOWMOKIT_STANDARDIZATION_HPP
