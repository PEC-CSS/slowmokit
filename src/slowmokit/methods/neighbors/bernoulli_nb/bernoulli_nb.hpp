/**
 * @file methods/neighbors/bernoulli_nb/bernoulli_nb.hpp
 *
 * The header file including the Bernoulli Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_BERNOULLI_NB_HPP
#define SLOWMOKIT_BERNOULLI_NB_HPP

#include "../../../core.hpp"

template<class T>
class BernoulliNB{  
private:
    double prior_prob(std::vector<T> yTrain,int label);
    double conditional_prob(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,int featureCol,int featureVal,int label);

public:
    // returns predicted value for each test according to bernoulli naive bayes model
    int fit(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,std::vector<T> xTest);
};

#endif