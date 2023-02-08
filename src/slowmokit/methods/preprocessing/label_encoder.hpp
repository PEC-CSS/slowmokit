/**
 * @file methods/preprocessing/label_encoder.hpp
 *
 * Easy include To Return the label encoded data
 */

#ifndef SLOWMOKIT_LABEL_ENCODER_HPP
#define SLOWMOKIT_LABEL_ENCODER_HPP

#include "../../core.hpp"

/**
 * @brief Function to label encode a given vector of categorical data
 * @param input -> The vector that needs to be encoded
 * @returns a vector containing the corresponding encoded data
 */

template<class T> std::vector<int> labelEncoder(std::vector<T> &);

#endif // SLOWMOKIT_LABEL_ENCODER_HPP
