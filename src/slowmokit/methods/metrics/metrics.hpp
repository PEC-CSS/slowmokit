/**
 * @file methods/metrics/metrics.hpp
 *
 * Easy include to execute all the functions of class metrics
 */

#ifndef SLOWMOKIT_METRICS_HPP
#define SLOWMOKIT_METRICS_HPP
#include "../../core.hpp"

/**
 * Takes predicted and actual values of classes
 * @param predictedValue -> predicted values
 * @param trueValue -> true values
 * @returns the classification report
 * @throws invalid_argument exception when size of the two vectors is not equal
 */

template<class T> class Metrics
{
  public:
  /**
   * Takes predicted and actual values
   * @param pred -> predicted values
   * @param trueLabels -> true values
   * @returns accuracy score
   * @throws invalid_argument exception when size of the two vectors is not equal
   */

  static double accuracy(const std::vector<T> &, const std::vector<T> &);

  /**
   * Takes predicted and actual values
   * @param pred -> predicted values
   * @param actual -> true values
   * @returns mean squared error
   * @throws exception invalid_argument in case size of the two vectors is not
   * equal
   */

  static double meanSquaredError(const std::vector<T> &,
                                 const std::vector<T> &);


  /**
   * Takes predicted and actual values
   * @param pred -> predicted values
   * @param actual -> actual values
   * @throws exception invalid_argument in case size of the two vectors is not
   * equal
   * @returns map of precision values
   */

  
  static std::map<T, double> precision(const std::vector<T> &,
                                       const std::vector<T> &);


  /**
   * Takes predicted and actual values
   * @param pred -> predicted values
   * @param actual -> actual values
   * @throws exception invalid_argument in case size of the two vectors is not
   * equal
   * @returns map of recall values
   */
  
  static std::map<T, double> recall(const std::vector<T> &,const std::vector<T> &);


  /**
   * Takes predicted and actual values
   * @param pred -> predicted values
   * @param trueLabels -> true values
   * @returns f1score score
   * @throws exception invalid_argument in case size of the two vectors is not
   * equal
   */

 
  static std::map<T, double> f1Score(const std::vector<T> &,
                                     const std::vector<T> &);
};

#endif // SLOWMOKIT_METRICS_HPP
