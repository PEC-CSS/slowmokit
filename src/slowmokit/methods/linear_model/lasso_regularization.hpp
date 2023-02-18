/**
 * @file methods/linear_model/lasso_regularization.hpp
 *
 * The header file including the lasso regularization model
 */

#ifndef SLOWMOKIT_LASSO_REGULARIZATION_HPP
#define SLOWMOKIT_LASSO_REGULARIZATION_HPP

#include "../../core.hpp"

template<class T> class LassoRegularization
{
  private:
  std::vector<T> coefficients;
  double lambda = 0.01;

  public:
  LassoRegularization(double = 0.01);


  /**
   * @brief calculates the lasso regularization term
   * @param x training x values
   * @param y training output values
   * @return regularized loss function
   */
  double lossFunction(std::vector<std::vector<T>> &, std::vector<T> &);


  /**
   * @brief calculates the gradient of the loss function
   * @param x training x values
   * @param y training output values
   * @return std::vector<double>
   */
  std::vector<double> gradient(std::vector<std::vector<T>> &, std::vector<T> &);


  /**
   * @brief implements the gradient descent optimization algorithm to find the
   * optimal coefficients for the lasso regression model
   * @param x training x values
   * @param y training output values
   * @param alpha
   */
  void gradientDescent(std::vector<std::vector<T>> &, std::vector<T> &, double);

  /**
   * @param x training x values
   * @param y training output values
   * @param epochs
   * @returns std::vector<double>
   */
  std::vector<double> fit(std::vector<std::vector<T>> &, std::vector<T> &, int,
                          double);

  std::vector<T> predict(std::vector<std::vector<T>>);

  void printCoefficients();
};

#endif // SLOWMOKIT_LASSO_REGULARIZATION_HPP
