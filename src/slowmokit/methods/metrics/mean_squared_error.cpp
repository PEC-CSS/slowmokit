/**
 * @file methods/metrics/mean_squared_error.cpp
 *
 * Implementation of the MSE main program
 */
#include "mean_squared_error.hpp"
template<class T>
double meanSquaredError(std::vector<T> &actual, std::vector<T> &pred)
{
  if (actual.size() != pred.size())
  {
    std::cerr << "Warning: actual and pred must have the same length."
              << std::endl;
    return -1.0;
  }

  double sum = 0.0;
  for (int i = 0; i < actual.size(); i++)
  {
    sum += (actual[i] - pred[i]) * (actual[i] - pred[i]);
  }
  return sum / actual.size();
}
