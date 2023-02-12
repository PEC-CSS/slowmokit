/**
 * @file methods/activation_functions.hpp
 *
 * Easy include to add non-linearity into a neural network.
 */

#ifndef ACTIVATION_FUNCTIONS_HPP
#define ACTIVATION_FUNCTIONS_HPP
#include "../core.hpp"


/**
 * @param x {double x} - double value on which the function is applied.
 * 
 * @param x {vector<double>} - vector containing 'double' values of x for softmax activation function implementation.
 * 
 * @return {double value} - double value after putting x in the functions gets returned.  
 */

template<class T>

double sigmoid(double);
double tanh(double);
double ReLU(double);
double leakyReLU(double, double);
std::vector<double> softmax(const std::vector<double> &);
double arctan(double);
double binaryStep(double);

#endif // ACTIVATION_FUNCTIONS_HPP