/**
 * @file methods/metrics/distance_metric/distance_metric.hpp
 *
 * Easy include to calculate distances
 */

#ifndef SLOWMOKIT_DISTANCE_METRIC_HPP
#define SLOWMOKIT_DISTANCE_METRIC_HPP
#include "../../../core.hpp"

/**
 * Takes predicted and actual values of classes
 * @param x
 * @param y
 * @returns the distance metrics
 * @throws domain_error exception when size of the two vectors is not equal
 */
template<class T> class DistanceMetric
{
  private:
  std::vector<T> x;
  std::vector<T> y;

  public:
  DistanceMetric(std::vector<T> &x, std::vector<T> &y);

  /**
   * @returns euclidean distance between the two vectors
   */
  double euclidean();


  /**
   * @returns manhattan distance between the two vectors
   */
  T manhattan();


  /**
   * @param power The order of the norm
   * @returns minkowski distance between the two vectors
   */
  double minkowski(int);

  /**
   * @brief to find the magnitude of the vector
   * @param x a vector
   * @returns magnitude of x
   */
  double magnitude(std::vector<T> &);

  /**
   * @returns cosine similarity between the two vectors
   */
  double cosineSimilarity();
};

#endif // SLOWMOKIT_DISTANCE_METRIC_HPP