/**
 * @file methods/preprocessing/one_hot_encoder.hpp
 *
 * Easy include To Return the one hot encoded data
 */

#ifndef ONE_HOT_ENCODER_HPP
#define ONE_HOT_ENCODER_HPP
#include "../../core.hpp"

/**
 * oneHotEncoder 
 * @template T
 * @param data {const std::vector<T> &} - vector that contains the data that has to be one hot encoded
 * @param nClasses {int} - integer that indicates the number of classes in the data.
 * @return {std::vector<std::vector<int>>} - oneHotEncoded data is returned. 
 */

template<class T>
std::vector<std::vector<int>> one_hot_encoder(const std::vector<int> &data, int n_classes);

#endif // ONE_HOT_ENCODER_HPP
