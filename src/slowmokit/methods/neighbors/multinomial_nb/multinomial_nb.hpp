/**
 * @file methods/neighbors/multinomial_nb/multinomial_nb.hpp
 *
 * The header file including the Multinomial Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_MULTINOMIAL_NB_HPP
#define SLOWMOKIT_MULTINOMIAL_NB_HPP

#include "../../../core.hpp"

template<class T>
class MultinomialNB{
private:
    std::vector<std::vector<T>> xTrain;
    std::vector<T> yTrain;
    std::vector<T> classes;
    double priorProb(std::vector<T> yTrain,int label);
    double conditionalProb(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,int featureCol,int featureVal,int label);
public:
    void fit(std::vector<std::vector<T>> xTrain,std::vector<T> yTrain,std::vector<T> classes);
    int fit_predict(std::vector<T> xTest);
};

#endif