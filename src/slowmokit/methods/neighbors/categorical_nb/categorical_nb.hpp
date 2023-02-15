/**
 * @file methods/neighbors/categorical_nb/categorical_naive_bayes.hpp
 *
 * The header file including the Categorical Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_CATEGORICAL_NB_HPP
#define SLOWMOKIT_CATEGORICAL_NB_HPP

#include "../../../core.hpp"

template<class T> class CategoricalNB
{

  public:
  /**
   * @brief Fitting the training set into instance of class
   * @param xTrain all training 2-d feature x values
   * @param yTrain all training 1-d string y values
   * @return NULL
   */
  void fit(std::vector<std::vector<T>> xTrain, std::vector<std::string> yTrain);

  /**
   * @brief Predicting the class for xTest on the basis of training set
   * @param xTest all testing feature x values
   * @return string denoting the class label of xTest
   */
  std::string predict(std::vector<T> xTest);
private :
    std::map<std::string, double> priors;
    std::map<std::string, std::map<std::pair<T, int>, double>> likelihoods;
    int featureSize;

};

#endif //   SLOWMOKIT_CATEGORICAL_NB_HPP
