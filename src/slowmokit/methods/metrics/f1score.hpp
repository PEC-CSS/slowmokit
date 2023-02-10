/**
 * @file methods/metrics/f1score.hpp
 *
 * Easy include to find f1score
 */

#ifndef SLOWMOKIT_F1SCORE_HPP
#define SLOWMOKIT_F1SCORE_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values
 * @param pred -> predicted values
 * @param trueLabels -> true values
 * @returns f1score score
 */

template<class T>
std::map<T, double> f1Score(std::vector<T> &, std::vector<T> &);

#endif // SLOWMOKIT_F1SCORE_HPP
