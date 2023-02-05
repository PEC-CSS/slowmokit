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
    double prior_prob(std::vector<int> y_train,int label);
    double conditional_prob(int mean,int variance,int feature);

public:
    int predict(std::vector<std::vector<T>> x_train,std::vector<int> y_train,std::vector<T> x_test,std::vector<int> classes);
};

#endif //SLOWMOKIT_GAUSSIAN_NB_HPP