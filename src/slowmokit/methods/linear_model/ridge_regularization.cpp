/**
 * @file methods/linear_model/ridge_regularization.cpp
 *
 * Implementation of the Ridge Regularization main program
 */

#include "ridge_regularization.hpp"

template<class T>
RidgeRegularization<T>::RidgeRegularization(double lambda) : lambda(lambda)
{
}

template<class T>
double RidgeRegularization<T>::lossFunction(std::vector<T> &x, double y)
{
  double yPred = predict(x, coefficients);
  double error = yPred - y;
  double loss = error * error;
  for (int i = 1; i < coefficients.size(); ++i)
  {
    loss += lambda * coefficients[i] * coefficients[i];
  }
  return loss;
}
template<class T>
std::vector<double> RidgeRegularization<T>::gradient(std::vector<T> &x,
                                                     double y)
{
  std::vector<double> gradient(coefficients.size());
  double yPred = predict(x);
  double error = yPred - y;
  gradient[0] = 2 * error;
  for (int i = 0; i < x.size(); ++i)
  {
    gradient[i + 1] = 2 * error * x[i] + 2 * lambda * coefficients[i + 1];
  }
  return gradient;
}
template<class T>
void RidgeRegularization<T>::gradientDescent(std::vector<std::vector<T>> &x,
                                             std::vector<T> &y, double alpha,
                                             int epochs)
{
  int m = y.size();
  for (int epoch = 0; epoch < epochs; ++epoch)
  {
    std::vector<double> grad(coefficients.size());
    for (int i = 0; i < m; ++i)
    {
      std::vector<double> exampleGrad = gradient(x[i], y[i]);
      for (int j = 0; j < coefficients.size(); ++j)
      {
        grad[j] += exampleGrad[j];
      }
    }
    for (int j = 0; j < coefficients.size(); ++j)
    {
      coefficients[j] = coefficients[j] - alpha * grad[j] / m;
    }
  }
}
template<class T>
std::vector<double> RidgeRegularization<T>::fit(std::vector<std::vector<T>> &x,
                                                std::vector<T> &y, int epochs,
                                                double alpha)
{
  if (x.size() == 0 || y.size() == 0)
    throw "Make sure that you have atleast one train example";
  if (x.size() != y.size())
    throw "Number of features and target must be equal";
  int trainExampleSize = x.size();
  int featureSize = x[0].size();
  if (featureSize == 0)
    throw "Feature size should be at least 1";
  coefficients.clear();
  coefficients.resize(featureSize + 1);
  int n = x.size();
  int m = x[0].size();
  std::vector<double> coefficients(m, 0.0);
  for (int i = 0; i < epochs; i++)
  {
    gradientDescent(x, y, alpha, epochs);
  }
  return coefficients;
}

template<class T> double RidgeRegularization<T>::predict(std::vector<T> &x)
{
  double yPred = coefficients[0];
  for (int i = 0; i < x.size(); ++i)
  {
    yPred += coefficients[i + 1] * x[i];
  }
  return yPred;
}

template<class T> void RidgeRegularization<T>::printCoefficients()
{
  for (int i = 0; i < coefficients.size(); i++)
    std::cout << "Θ" << i << ": " << coefficients[i] << std::endl;
}
