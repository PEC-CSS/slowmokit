/**
 * @file methods/activation_functions.cpp
 *
 * Implementation of activation functions
 */
#include "activation_functions.hpp"
// sigmoid
void sigmoid(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    x[i] = 1 / (1 + std::exp(-x[i]));
  }
}
// ReLU
void ReLU(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] <= 0.0)
    {
      x[i] = 0.0;
    }
  }
}
// tanh
void tanh(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    x[i] =
        (std::exp(x[i]) - std::exp(-x[i])) / (std::exp(x[i]) + std::exp(-x[i]));
  }
}
// arctan
void arctan(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    x[i] = std::atan(x[i]);
  }
}

// softmax
void softmax(std::vector<double> &x)
{
  double sum = 0;
  for (double value : x)
  {
    sum += std::exp(value);
  }
  for (int i = 0; i < x.size(); i++)
  {
    x[i] = std::exp(x[i]) / sum;
  }
}
// binarystep
void binaryStep(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] >= 0)
    {
      x[i] = 1;
    } // assuming threshold value to be 0 here
    else
    {
      x[i] = 0;
    }
  }
}
// leakyReLU
void leakyReLU(std::vector<double> &x, double alpha = 0.1)
{
  for (int i = 0; i < x.size(); i++)
  {
    if (x[i] >= 0)
    {
      x[i] = x[i];
    }
    else
    {
      x[i] = alpha * x[i]; // alpha=0.1
    };
  }
}
// binaryToBipolar Conversion
// x= binary numbers entered by the user
// y= bipolar numbers to be produced as output
void binaryToBipolar(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    x[i] = 2 * x[i] - 1;
  }
}
// bipolarToBinary Conversion
// x= bipolar numbers entered by the user
// y= binary numbers to be produced as output
void bipolarToBinary(std::vector<double> &x)
{
  for (int i = 0; i < x.size(); i++)
  {
    x[i] = (x[i] + 1) / 2;
  }
}