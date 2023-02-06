/**
 * @file methods/linear_models/linear_regression/linear_regression.hpp
 *
 * The header file including the linear regression algorithm
 */

#ifndef SLOWMOKIT_DECISION_TREE_HPP
#define SLOWMOKIT_DECISION_TREE_HPP

#include "../../../core.hpp"

template<class T>
class DecisionTree{
private: 
    DecisionTree* left = NULL;
    DecisionTree* right=NULL;
    int fkey=-1;
    double fval=-1;
    int maxDepth=-1;
    int depth=0;
    int minSamplesLeaf=1;
    int target=-1;
    int max Features;
    std::set<int> features;
    double entropy(std::vector<double> col);
    std::vector<std::vector<std::vector<double>>> divideData(std::vector<std::vector<double>> x_data,int fkey,int fval);
    double infoGain(std::vector<std::vector<double>> x_data,int fkey,int fval);

public:
    DecisionTree(int max_d,int minSamplesL,int max_f);
    void train(std::vector<std::vector<double>> x_data);
    int predict(std::vector<double> test);
};

#endif