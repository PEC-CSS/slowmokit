/**
 * @file methods/metrics/precision.hpp
 *
 * Easy include to find precision
 */

#ifndef SLOWMOKIT_PRECISION_HPP
#define SLOWMOKIT_PRECISION_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values
 * @param pred -> predicted values
 * @param actual -> actual values
 * @throws exception invalid_argument in case size of the two vectors is not
 * equal
 * @returns map of precision values
 */

template<class T>
std::map<T, double> precision(std::vector<T> &, std::vector<T> &);


#endif // SLOWMOKIT_PRECISION_HPP