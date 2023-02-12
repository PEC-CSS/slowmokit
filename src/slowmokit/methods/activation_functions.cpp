/**
 * @file methods/activation_functions.cpp
 *
 * Implementation of activation functions
 */
#include "activation_functions.hpp"
template<class T>
// sigmoid
double sigmoid(double x)
{
  return 1 / (1 + std::exp(-x));
}
// ReLU
double ReLU(double x)
{
  if (x > 0)
  {
    return x;
  }
  else
  {
    return 0;
  }
}
// tanh
double tanh(double x)
{
  double result = (std::exp(x) - std::exp(-x)) / (std::exp(x) + std::exp(-x));
  return result;
}
// tan inverse
double arctan(double x) { return std::atan(x); }

// softmax
std::vector<double> softmax(const std::vector<double> &x)
{
  std::vector<double> result(x.size());
  double sum = 0;
  for (double value : x)
  {
    sum += std::exp(value);
  }
  for (int i = 0; i < x.size(); i++)
  {
    result[i] = std::exp(x[i]) / sum;
  }
  return result;
}
// binary step
double binaryStep(double x)
{
  if (x >= 0)
  {
    return 1; // assuming threshold value to be 0 here
  }
  else
  {
    return 0;
  }
}
<<<<<<< HEAD
// leaky ReLU
double leakyReLU(double x, double alpha)
{
  if (x >= 0)
  {
    return x;
  }
  else
  {
    return alpha * x;
  }
}
== == == =
             // leaky ReLU
    double leakyReLU(double x, double alpha)
{
  if (x >= 0)
  {
    return x;
  }
  else
  {
    return alpha * x;
  }
}
>>>>>>> 5eebc29054fab6686e728aca29e64e1c53dd7a8c
