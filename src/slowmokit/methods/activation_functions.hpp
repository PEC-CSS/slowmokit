/**
 * @file methods/activation_functions.hpp
 *
 * Easy include to add non-linearity into a neural network.
 */

#ifndef ACTIVATION_FUNCTIONS_HPP
#define ACTIVATION_FUNCTIONS_HPP
#include "../../core.hpp"
#include <math.h>

/**
 * @param x {double x} - double value on which the function is applied.
 * 
 * @param x {vector<double>} - vector containing 'double' values of x for softmax activation function implementation.
 * 
 * @return {double value} - double value after putting x in the functions gets returned.  
 */

template<class T>

double sigmoid(double x);
double tanh(double x);
double ReLU(double x);
double leakyReLU(double x, double alpha);
std::vector<double> softmax(const std::vector<double> &x);
double arctan(double x);
double binaryStep(double x);

#endif // ACTIVATION_FUNCTIONS_HPP