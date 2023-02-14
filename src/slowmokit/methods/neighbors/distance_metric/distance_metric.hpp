/**
 * @file methods/neighbors/distance_metric/distance_metric.hpp
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
   * @param x An array where each row is a sample and each column is a feature.
   * @param y An array where each row is a sample and each column is a feature.
   * @throws domain_error exception when size of the two vectors is not equal
   * @returns euclidean distance between the two vectors
   */
  double euclidean(std::vector<T> &, std::vector<T> &);


  /**
   *@param x An array where each row is a sample and each column is a feature.
   * @param y An array where each row is a sample and each column is a feature.
   * @throws domain_error exception when size of the two vectors is not equal
   * @returns manhattan distance between the two vectors
   */
  double manhattan(std::vector<T> &, std::vector<T> &);


  /**
   * @param x An array where each row is a sample and each column is a feature.
   * @param y An array where each row is a sample and each column is a feature.
   * @throws domain_error exception when size of the two vectors is not equal
   * @returns minkowski distance between the two vectors
   */
  double minkowski(std::vector<T> &, std::vector<T> &, int);

  /**
   * @brief to find the magnitude of the vector
   * @param x a vector
   * @returns magnitude of x
   */
  double magnitude(std::vector<T> &);

  /**
   * @param x An array where each row is a sample and each column is a feature.
   * @param y An array where each row is a sample and each column is a feature.
   * @throws domain_error exception when size of the two vectors is not equal
   * @returns cosine similarity between the two vectors
   */
  double cosineSimilarity(std::vector<T> &, std::vector<T> &);
};

#endif // SLOWMOKIT_DISTANCE_METRIC_HPP