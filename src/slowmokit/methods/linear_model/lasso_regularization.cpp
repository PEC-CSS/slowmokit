/**
 * @file methods/linear_model/lasso_regularization.cpp
 *
 * Implementation of the Lasso Regularization main program
 */

#include "lasso_regularization.hpp"

template<class T>
LassoRegularization<T>::LassoRegularization(double lambda) : lambda(lambda)
{
}

template<class T>
double LassoRegularization<T>::lossFunction(std::vector<std::vector<T>> &x,
                                            std::vector<T> &y)
{
  int trainingSampleSize = x.size();
  double loss = 0.0;
  for (int i = 0; i < trainingSampleSize; i++)
  {
    double yPred = 0.0;
    for (int j = 0; j < coefficients.size(); j++)
    {
      yPred += coefficients[j] * coefficients[i][j];
    }
    loss += pow(y[i] - yPred, 2);
  }
  loss /= 2 * trainingSampleSize;
  double regularization = 0.0;
  for (int i = 0; i < coefficients.size(); i++)
  {
    regularization += fabs(coefficients[i]);
  }
  regularization *= lambda;
  return loss + regularization;
}
template<class T>
std::vector<double>
LassoRegularization<T>::gradient(std::vector<std::vector<T>> &x,
                                 std::vector<T> &y)
{
  int trainingSampleSize = x.size();
  int m = coefficients.size();
  std::vector<double> grad(m);
  for (int j = 0; j < m; j++)
  {
    double sum = 0.0;
    for (int i = 0; i < trainingSampleSize; i++)
    {
      sum += (coefficients[j] * x[i][j] - y[i]) * x[i][j];
    }
    grad[j] = sum / trainingSampleSize;
    if (coefficients[j] > 0)
    {
      grad[j] += lambda;
    }
    else if (coefficients[j] < 0)
    {
      grad[j] -= lambda;
    }
  }
  return grad;
}
template<class T>
void LassoRegularization<T>::gradientDescent(std::vector<std::vector<T>> &x,
                                             std::vector<T> &y, double alpha)
{
  std::vector<double> grad = gradient(x, y);
  int m = coefficients.size();
  for (int j = 0; j < m; j++)
  {
    coefficients[j] -= alpha * grad[j];
  }
}
template<class T>
std::vector<double> LassoRegularization<T>::fit(std::vector<std::vector<T>> &x,
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
    gradientDescent(x, y, alpha);
  }
  return coefficients;
}

template<class T>
std::vector<T> LassoRegularization<T>::predict(std::vector<std::vector<T>> x)
{
  std::vector<T> yPred;
  int trainExampleSize = x.size(), featureSize = x[0].size();
  for (int example = 0; example < trainExampleSize; example++)
  {
    T currentY = coefficients[0];
    for (int feature = 0; feature < featureSize; feature++)
      currentY += coefficients[feature + 1] * x[example][feature];
    yPred.push_back(currentY);
  }
  return yPred;
}

template<class T> void LassoRegularization<T>::printCoefficients()
{
  for (int i = 0; i < coefficients.size(); i++)
    std::cout << "Θ" << i << ": " << coefficients[i] << std::endl;
}
