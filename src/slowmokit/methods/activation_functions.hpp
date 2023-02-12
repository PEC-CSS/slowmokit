/**
 * @file methods/activation_functions.hpp
 *
 * Easy include to add non-linearity into a neural network.
 */

#ifndef ACTIVATION_FUNCTIONS_HPP
#define ACTIVATION_FUNCTIONS_HPP
#include "../core.hpp"
template<class T>

/**
 * @brief To calculate sigmoid(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose sigmoid values have to be calculated.
 * 
 * @return vector containing 'double' values representing sigmoid(x)
 */

std::vector<double> sigmoid(const std::vector<double> &);

/**
 * @brief To calculate ReLU(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose ReLU values have to be calculated.
 * 
 * @return vector containing 'double' values representing ReLU(x)
 */

std::vector<double> ReLU(const std::vector<double> &);

/**
 * @brief To calculate tanh(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose tanh values have to be calculated.
 * 
 * @return vector containing 'double' values representing tanh(x)
 */

std::vector<double> tanh(const std::vector<double> &);

/**
 * @brief To calculate arctan(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose arctan values have to be calculated.
 * 
 * @return vector containing 'double' values representing arctan(x)
 */

std::vector<double> arctan(const std::vector<double> &);

/**
 * @brief To calculate softmax(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose softmax values have to be calculated.
 * 
 * @return vector containing 'double' values representing softmax(x)
 */

std::vector<double> softmax(const std::vector<double> &);

/**
 * @brief To calculate binaryStep(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose binaryStep values have to be calculated.
 * 
 * @return vector containing 'double' values representing binaryStep(x)
 */

std::vector<double> binaryStep(const std::vector<double> &);

/**
 * @brief To calculate leakyReLU(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose leakyReLU values have to be calculated.
 * 
 * @return vector containing 'double' values representing leakyReLU(x)
 */

std::vector<double> leakyReLU(const std::vector<double> &);

/**
 * @brief To convert binaryToBipolar(x)
 * @param x {vector<double>} - vector containing 'double' values of x who have to be converted to bipolar numbers.
 * 
 * @return vector containing 'double' values representing binaryToBipolar(x)
*/

std::vector<double> binaryToBipolar(const std::vector<double> &);

/**
 * @brief To convert bipolarToBinary(x)
 * @param x {vector<double>} -  vector containing 'double' values of x who have to be converted to binary numbers.
 * 
 * @return vector containing 'double' values representing bipolarToBinary(x)
 */

std::vector<double> bipolarToBinary(const std::vector<double> &);

#endif // ACTIVATION_FUNCTIONS_HPP