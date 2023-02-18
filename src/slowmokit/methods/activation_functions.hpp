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
 * @param x {vector<double>} - vector containing 'double' values of x whose
 * sigmoid values have to be calculated.
 *
 */

void sigmoid(std::vector<double> &);

/**
 * @brief To calculate ReLU(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose ReLU
 * values have to be calculated.
 *
 */

void ReLU(std::vector<double> &);

/**
 * @brief To calculate tanh(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose tanh
 * values have to be calculated.
 *
 */

void tanh(std::vector<double> &);

/**
 * @brief To calculate arctan(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose
 * arctan values have to be calculated.
 *
 */

void arctan(std::vector<double> &);

/**
 * @brief To calculate softmax(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose
 * softmax values have to be calculated.
 *
 */

void softmax(std::vector<double> &);

/**
 * @brief To calculate binaryStep(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose
 * binaryStep values have to be calculated.
 *
 */

void binaryStep(std::vector<double> &);

/**
 * @brief To calculate leakyReLU(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose
 * leakyReLU values have to be calculated.
 *
 */

void leakyReLU(std::vector<double> &, double = 0.1);

/**
 * @brief To convert binaryToBipolar(x)
 * @param x {vector<double>} - vector containing 'double' values of x who have
 * to be converted to bipolar numbers.
 *
 */

void binaryToBipolar(std::vector<double> &);

/**
 * @brief To convert bipolarToBinary(x)
 * @param x {vector<double>} -  vector containing 'double' values of x who have
 * to be converted to binary numbers.
 *
 */

void bipolarToBinary(std::vector<double> &);

#endif // ACTIVATION_FUNCTIONS_HPP