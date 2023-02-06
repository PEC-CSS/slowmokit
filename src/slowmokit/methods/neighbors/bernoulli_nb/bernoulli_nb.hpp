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
    /*
    @brief Function Prior probability
    @param: yTrain to compute P(y=y1) and label: y1
    @returns double value of prior Probability
    */
    double priorProb(std::vector<T> yTrain,int label);
    /*
    @brief Function conditional Probabilty
    @param: xTrain: all x training values , yTrain: all y training values, featureCol: for which feature column we are finding conditional prob. ; featureVal: for what value in that feature we are looking for conditional prob.; label: y value looking for
    @returns double value of conditional probability
    */
    double conditionalProb(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,int featureCol,int featureVal,int label);

public:
    /*
    brief Function fit and predict the output
    @param: xTrain: training values, yTrain: y training values, xTest: testing values
    @returns returns predicted value for each test according to bernoulli naive bayes model
    */
    int fitPredict(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,std::vector<T> xTest);
};

#endif