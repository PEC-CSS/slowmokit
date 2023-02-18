/**
 * @file methods/linear_model/ridge_regularization.hpp
 *
 * The header file including the ridge regularization model
 */

#ifndef SLOWMOKIT_RIDGE_REGULARIZATION_HPP
#define SLOWMOKIT_RIDGE_REGULARIZATION_HPP

#include "../../core.hpp"

template<class T> class RidgeRegularization
{
  private:
  std::vector<T> coefficients;
  double lambda = 0.01;

  public:
  RidgeRegularization(double = 0.01);


  /**
   * @brief calculates the ridge regularization term
   * @param x training x values for a single feature
   * @param y training output value
   * @return regularized loss function
   */
  double lossFunction(std::vector<T> &, double);


  /**
   * @brief calculates the gradient of the loss function
   * @param x training x values for a single feature
   * @param y training output value
   * @return std::vector<double>
   */
  std::vector<double> gradient(std::vector<T> &, double);


  /**
   * @brief implements the gradient descent optimization algorithm to find the
   * optimal coefficients for the ridge regression model
   * @param x training x values
   * @param y training output values
   * @param alpha
   * @param epochs
   */
  void gradientDescent(std::vector<std::vector<T>> &, std::vector<T> &, double,
                       int);

  /**
   * @param x training x values
   * @param y training output values
   * @param epochs
   * @param alpha
   * @returns std::vector<double>
   */
  std::vector<double> fit(std::vector<std::vector<T>> &, std::vector<T> &, int,
                          double);

  double predict(std::vector<T> &);

  void printCoefficients();
};

#endif // SLOWMOKIT_RIDGE_REGULARIZATION_HPP
