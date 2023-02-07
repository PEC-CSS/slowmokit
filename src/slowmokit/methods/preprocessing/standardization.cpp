/**
 * @file methods/preprocessing/standardization.CPP
 *
 * Implementation of the Accuracy score main program
 */
#include "standardization.hpp"
template<class T> void standardize(std::vector<T> &values)
{
  double mean = 0.0;
  double stdDev = 0.0;
  double sum = accumulate(values.begin(), values.end(), 0.0);
  int n = values.size();
  mean = sum / (double) n;

  for (int i = 0; i < n; i++)
  {
    stdDev += (values[i] - mean) * (values[i] - mean);
  }
  stdDev = sqrt(stdDev / n);
  if (stdDev == 0.0)
  {
    for (int i = 0; i < n; i++)
    {
      values[i] = 1;
    }
    std::cerr << "Warning: Standard Deviation is zero" << std::endl;
    return;
  }
  for (int i = 0; i < n; i++)
  {
    values[i] = (values[i] - mean) / stdDev;
  }
}
