/**
 * @file methods/linear_models/linear_regression/linear_regression.hpp
 *
 * The header file including the linear regression algorithm
 */

#ifndef SLOWMOKIT_DECISION_TREE_HPP
#define SLOWMOKIT_DECISION_TREE_HPP

#include "../../../core.hpp"

template<class T> class DecisionTree
{
  private:
  DecisionTree *left = NULL;
  DecisionTree *right = NULL;
  int fkey = -1;
  double fval = -1;
  int maxDepth = -1;
  int depth = 0;
  int minSamplesLeaf = 1;
  int target = -1;
  int maxFeatures;
  std::set<int> features;
  /**
   * @brief calculate entropy
   *
   * @param col
   * @return double entropy value
   */
  double entropy(std::vector<double> col);
  /**
   * @brief divides the data according to decided feature
   *
   * @param x_data training data
   * @param fkey column on basis of which data is to be divided
   * @param fval value on basis of which data is to be divided
   * @return std::vector<std::vector<std::vector<double>>>
   */
  std::vector<std::vector<std::vector<double>>>
  divideData(std::vector<std::vector<double>> x_data, int fkey, int fval);
  /**
   * @brief information gain
   *
   * @param x_data training data
   * @param fkey column to check highest info gain
   * @param fval value to check highest info gain
   * @return double value of information gain
   */
  double infoGain(std::vector<std::vector<double>> x_data, int fkey, int fval);

  public:
  /**
   * @brief Construct a new Decision Tree object
   *
   * @param max_d maximum depth
   * @param minSamplesL minimum samples to be in leaf node by default 1
   * @param max_f maximum samples to be in leaf nodes
   */
  DecisionTree(int max_d, int minSamplesL, int max_f);
  /**
   * @brief prepare decision tree
   *
   * @param x_data all training values
   */
  void train(std::vector<std::vector<double>> x_data);
  /**
   * @brief predict the testing values
   *
   * @param test testing values
   * @return int class to which test value belongs
   */
  int predict(std::vector<double> test);
};

#endif