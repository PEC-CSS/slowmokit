/**
 * @file methods/neighbors/gaussian_nb/gaussian_nb.hpp
 *
 * The header file including the Gaussian Naive Bayes algorithm
 */

#ifndef SLOWMOKIT_GAUSSIAN_NB_HPP
#define SLOWMOKIT_GAUSSIAN_NB_HPP

#include "../../../core.hpp"

template<class T>
class GaussianNB{
private:
    T priorProb(std::vector<int> yTrain,int label);
    T conditionalProb(int mean,int variance,int feature);

public:
    int fitPredict(std::vector<std::vector<T>> xTrain,std::vector<int> yTrain,std::vector<T> xTest,std::vector<int> classes);
};

#endif //SLOWMOKIT_GAUSSIAN_NB_HPP