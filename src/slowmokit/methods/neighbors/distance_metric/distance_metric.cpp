/**
 * @file methods/neighbors/distance_metric/distance_metric.hpp
 *
 * Easy include to calculate distance metrics
 */

#include "distance_metric.hpp"

template<class T>
DistanceMetric<T>::DistanceMetric(std::vector<T> &x, std::vector<T> &t)
{
  this->x = x;
  this->y = y;
}

template<class T>
double DistanceMetric<T>::euclidean(std::vector<T> &x, std::vector<T> &y)
{
  if (x.size() != y.size())
  {
    throw std::domain_error("Size of the two vectors must be same");
  }
  double distance = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    distance += (x[i] - y[i]) * (x[i] - y[i]);
  }
  return sqrt(distance);
}

template<class T>
double DistanceMetric<T>::manhattan(std::vector<T> &x, std::vector<T> &y)
{
  if (x.size() != y.size())
  {
    throw std::domain_error("Size of the two vectors must be same");
  }
  double distance = 0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    distance += abs(x[i] - y[i]);
  }
  return distance;
}
template<class T>
double DistanceMetric<T>::minkowski(std::vector<T> &x, std::vector<T> &y,
                                    int power)
{
  if (x.size() != y.size())
  {
    throw std::domain_error("Size of the two vectors must be same");
  }
  double distance = 0.0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    distance += pow(x[i] - y[i], power);
  }
  return pow(distance, 1.0 / power);
}

template<class T> double DistanceMetric<T>::magnitude(std::vector<T> &x)
{
  double result = 0.0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    result += pow(x[i], 2);
  }
  return sqrt(result);
}

template<class T>
double DistanceMetric<T>::cosineSimilarity(std::vector<T> &x, std::vector<T> &y)
{
  if (x.size() != y.size())
  {
    throw std::domain_error("Size of the two vectors must be same");
  }
  double dotProduct = 0.0;
  int n = x.size();
  for (int i = 0; i < n; i++)
  {
    dotProduct += x[i] * y[i];
  }
  return dotProduct / (magnitude(x) * magnitude(y));
}
