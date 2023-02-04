/**
 * @file methods/metrics/accuracy.hpp
 *
 * Easy include to find accuracy score
 */

#ifndef SLOWMOKIT_ACCURACY_HPP
#define SLOWMOKIT_ACCURACY_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values
 * @param pred -> predicted values
 * @param trueLabels -> true values
 * @returns accuracy score
 * @throws domain_error exception when size of the two vectors is not equal
 */

template <class T>
double accuracy(const std::vector<T> &, const std::vector<T> &);

#endif // SLOWMOKIT_ACCURACY_HPP
