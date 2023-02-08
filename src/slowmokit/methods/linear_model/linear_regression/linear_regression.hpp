/**
 * @file methods/linear_models/linear_regression/linear_regression.hpp
 *
 * The header file including the linear regression algorithm
 */

#ifndef SLOWMOKIT_LINEAR_REGRESSION_HPP_1
#define SLOWMOKIT_LINEAR_REGRESSION_HPP_1

#include "../../../core.hpp"

template<class T> class LinearRegression
{
  private:
  std::vector<T> coefficients;
  int epochs = 100;
  double learningRate = 0.01;

  public:
  LinearRegression(int = 100, double = 0.01);

  void fit(std::vector<std::vector<T>>, std::vector<T>);

  std::vector<T> predict(std::vector<std::vector<T>>);

  void printCoefficients();
};

#endif // SLOWMOKIT_LINEAR_REGRESSION_HPP
