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
 * @param x: Number whose sigmoid value is to be calculated
 * @return a double value representing sigmoid(x)
 */
double sigmoid(double);

/**
<<<<<<< HEAD
 * @param x {double x} - double value on which the function is applied.
 *
 * @param x {vector<double>} - vector containing 'double' values of x for
 * softmax activation function implementation.
 *
 * @return {double value} - double value after putting x in the functions gets
 * returned.
=======
 * @brief To calculate tan(x)
 * @param x: Number whose tan value is to be calculated
 * @return a double value representing tan(x)
>>>>>>> 5eebc29054fab6686e728aca29e64e1c53dd7a8c
 */

double tanh(double);

/**
 * @brief To calculate ReLU(x)
 * @param x: Number whose ReLU value is to be calculated
 * @return a double value representing ReLU(x)
 */

double ReLU(double);

/**
 * @brief To calculate leakyReLU(x)
 * @param x: Number whose leakyReLU value is to be calculated
 * @return a double value representing leakyReLU(x)
 */

double leakyReLU(double, double);

/**
 * @brief To calculate softmax(x)
 * @param x {vector<double>} - vector containing 'double' values of x whose softmax values have to be calculated.
 * 
 * @return vector containing 'double' values representing softmax(x)
 */

std::vector<double> softmax(const std::vector<double> &);

/**
 * @brief To calculate arctan(x)
 * @param x: Number whose tan inverse value is to be calculated
 * @return a double value representing arctan(x)
 */

double arctan(double);

/**
 * @brief To calculate binaryStep(x)
 * @param x: Number whose binaryStep value is to be calculated
 * @return a double value representing binaryStep(x)
 */

double binaryStep(double);

#endif // ACTIVATION_FUNCTIONS_HPP