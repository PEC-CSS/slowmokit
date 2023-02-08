/**
 * @file ducks/random/random.hpp
 *
 * Header file including the trin class of ducks.
 */

#ifndef SLOWMOKIT_TRAIN_TEST_SPLIT_HPP
#define SLOWMOKIT_TRAIN_TEST_SPLIT_HPP

#include "../../core.hpp"

/**
 * @brief Function to split any iterable into random train and test subsets.
 * @param X: Independent feature Data to split
 * @param Y: Dependent feature to split
 * @param testSize: proportion of the dataset to be included in the test split.
 * Default value: 0.3
 * @param trainSize: proportion of the dataset to be included in the test split.
 * Default value: 0.7
 * @returns Array of size 4 denoting { xTrain, xTest, yTrain, yTest }
 * @throws std::domain_error if T is not an iterable d
 */
template<class T, class G>
std::tuple<std::vector<T>, std::vector<G>, std::vector<T>, std::vector<G>>
trainTestSplit(const std::vector<T> &, const std::vector<G> &, double = 0.3,
               double = 0.7);

#endif // SLOWMOKIT_TRAIN_TEST_SPLIT_HPP