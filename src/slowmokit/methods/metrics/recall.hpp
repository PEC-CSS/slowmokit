/**
 * @file methods/metrics/recall.hpp
 *
 * Easy include to find recall
 */

#ifndef SLOWMOKIT_RECALL_HPP
#define SLOWMOKIT_RECALL_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values
 * @param pred -> predicted values
 * @param actual -> actual values
 * @throws exception invalid_argument in case size of the two vectors is not equal
 * @returns map of recall values 
 */

template <class T>
std::map<T, double> recall(std::vector<T> &, std::vector<T> &);
#endif // SLOWMOKIT_RECALL_HPP
