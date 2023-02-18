/**
 * @file methods/neighbors/multinomial_nb/multinomial_nb.hpp
 *
 * The header file including the Multinomial Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_MULTINOMIAL_NB_HPP
#define SLOWMOKIT_MULTINOMIAL_NB_HPP

#include "../../../core.hpp"

template<class T> class MultinomialNB
{
  private:
  /**
   * @brief Prior probability of multinomial naive bayes
   *
   * @param yTrain All y training values
   * @param label output we are looking in prior probability
   * @return double prior Probability
   */
  double priorProb(std::vector<T> yTrain, int label);
  /**
   * @brief Conditional Probability
   *
   * @param xTrain all x training int values
   * @param yTrain all y training int values
   * @param featureCol column for which we are computing conditional prob
   * @param featureVal value in that column
   * @param label y value
   * @return double conditional probability
   */
  double conditionalProb(std::vector<std::vector<T>> xTrain,
                         std::vector<T> yTrain, int featureCol, int featureVal,
                         int label);

  public:
  /**
   * @brief fit_predict function
   *
   * @param xTrain all x training values
   * @param yTrain all y training values int
   * @param classes classes of y
   * @param xTest testing values int
   * @return int output predicted value
   */
  int fit_predict(std::vector<std::vector<T>> xTrain, std::vector<T> yTrain,
                  std::vector<T> classes, std::vector<T> xTest);
};

#endif