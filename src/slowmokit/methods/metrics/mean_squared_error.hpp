/**
 * @file methods/metrics/mean_squared_error.hpp
 *
 * Easy include to find MSE
 */

#ifndef SLOWMOKIT_MEAN_SQUARED_ERROR_HPP
#define SLOWMOKIT_MEAN_SQUARED_ERROR_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values
 * @param pred -> predicted values
 * @param actual -> true values
 * @returns mean squared error
 * @throws exception invalid_argument in case size of the two vectors is not
 * equal
 */

template <class T>
double meanSquaredError(std::vector<T> &, std::vector<T> &);

#endif // SLOWMOKIT_MEAN_SQUARED_ERROR_HPP
