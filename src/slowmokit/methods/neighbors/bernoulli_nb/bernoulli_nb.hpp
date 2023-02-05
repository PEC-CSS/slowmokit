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
    double prior_prob(std::vector<T> y_train,int label);
    double conditional_prob(std::vector<std::vector<T>> x_train,std::vector<T> y_train,int feature_col,int feature_val,int label);

public:
    int predict(std::vector<std::vector<T>> x_train,std::vector<T> y_train,std::vector<T> x_test);
};

#endif