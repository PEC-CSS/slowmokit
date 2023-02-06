/**
 * @file methods/preprocessing/one_hot_encoder.hpp
 *
 * Easy include To Return the one hot encoded data
 */

#ifndef ONE_HOT_ENCODER_HPP
#define ONE_HOT_ENCODER_HPP
#include "../../core.hpp"
template<class T>
std::vector<std::vector<int>> one_hot_encoder(const std::vector<int> &data, int n_classes);

#endif // ONE_HOT_ENCODER_HPP
