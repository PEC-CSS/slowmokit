/**
 * @file methods/metrics/distance_metric/distance_metric.hpp
 *
 * Easy include to calculate distance metrics
 */

#include "distance_metric.hpp"

template<class T>
DistanceMetric<T>::DistanceMetric(std::vector<T> &x, std::vector<T> &y)
{
  this->x = x;
  this->y = y;
  if (x.size() != y.size())
  {
    throw std::domain_error("Size of the two vectors must be same");
  }
}

template<class T> T DistanceMetric<T>::euclidean()
{
  T distance = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    distance += (x[i] - y[i]) * (x[i] - y[i]);
  }
  return std::sqrt(distance);
}

template<class T> T DistanceMetric<T>::manhattan()
{
  T distance = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    distance += std::abs(x[i] - y[i]);
  }
  return distance;
}
template<class T> T DistanceMetric<T>::minkowski(int power)
{
  T distance = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    distance += std::pow(x[i] - y[i], power);
  }
  return std::pow(distance, 1.0 / power);
}

template<class T> T DistanceMetric<T>::magnitude(std::vector<T> &x)
{
  T result = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    result += std::pow(x[i], 2);
  }
  return std::sqrt(result);
}

template<class T> T DistanceMetric<T>::cosineSimilarity()
{
  T dotProduct = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    dotProduct += x[i] * y[i];
  }
  return dotProduct / (magnitude(x) * magnitude(y));
}
