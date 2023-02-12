/**
 * @file methods/activation_functions.cpp
 *
 * Implementation of activation functions
 */
#include "activation_functions.hpp"
template<class T>
// sigmoid
std::vector<double> sigmoid(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    y[i] = 1 / (1 + exp(-x[i]));
  }
  return y;
}
// ReLU
std::vector<double> ReLU(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] > 0.0)
    {
      y[i] = x[i];
    }
    else
    {
      y[i] = 0.0;
    }
  }
  return y;
}
// tanh
std::vector<double> tanh(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    y[i] =
        (std::exp(x[i]) - std::exp(-x[i])) / (std::exp(x[i]) + std::exp(-x[i]));
  }
  return y;
}
// arctan
std::vector<double> arctan(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    y[i] = atan(x[i]);
  }
  return y;
}

// softmax
std::vector<double> softmax(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  double sum = 0;
  for (double value : x)
  {
    sum += std::exp(value);
  }
  for (int i = 0; i < x.size(); i++)
  {
    y[i] = std::exp(x[i]) / sum;
  }
  return y;
}
// binarystep
std::vector<double> binaryStep(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] >= 0)
    {
      y[i] = 1;
    } // assuming threshold value to be 0 here
    else
    {
      y[i] = 0;
    }
  }
  return y;
}
// leakyReLU
std::vector<double> leakyReLU(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  double alpha = 0.1;
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] >= 0)
    {
      y[i] = x[i];
    }
    else
    {
      y[i] = alpha * x[i]; // alpha=0.1
    };
  }
  return y;
}
// binaryToBipolar Conversion
// x= binary numbers entered by the user
// y= bipolar numbers to be produced as output
std::vector<double> binaryToBipolar(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    y[i] = 2 * x[i] - 1;
  }
  return y;
}
// bipolarToBinary Conversion
// x= bipolar numbers entered by the user
// y= binary numbers to be produced as output
std::vector<double> bipolarToBinary(const std::vector<double> &x)
{
  std::vector<double> y(x.size());
  for (int i = 0; i < x.size(); i++)
  {
    y[i] = (x[i] + 1) / 2;
  }
  return y;
}