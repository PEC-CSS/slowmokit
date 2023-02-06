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
    // returns prior probability
    double priorProb(std::vector<T> yTrain,int label);
    // return conditional probability
    double conditionalProb(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,int featureCol,int featureVal,int label);

public:
    // returns predicted value for each test according to bernoulli naive bayes model
    int fitPredict(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,std::vector<T> xTest);
};

#endif