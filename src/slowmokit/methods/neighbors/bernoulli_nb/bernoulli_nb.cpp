/**
 * @file methods/neighbors/bernoulli_nb/nernoulli_nb.cpp
 *
 * Implementation of the Bernoulli Naive Bayes main program
 */
#include "bernoulli_nb.hpp"

template<class T>
    double prior_prob(std::vector<T> y_train,int label){   // Prior-Probability P(y)
        int sum=0;
        for(int i=0;i<y_train.size();i++){
            if(y_train[i]==label){
                sum += 1;
            }
        }
        return sum/double(y_train.size());
    }

template<class T>
    double conditional_prob(std::vector<std::vector<T>> x_train,std::vector<T> y_train,int feature_col,int feature_val,int label){ // Conditional Probability
    // P(x=f1 / y=class) 
        int denominator=0,numerator=0;
        for(int i=0;i<y_train.size();i++){
            if(y_train[i]==label){
                denominator++;
                if(x_train[i][feature_col]==feature_val){
                    numerator++;
                }
            }
        }
        return numerator/double(denominator);
    }

template<class T>
    int predict(std::vector<std::vector<T>> x_train,std::vector<T> y_train,std::vector<T> x_test){
        int n_features = x_train[0].size();

        std::vector<double> post_probs;

        for(int label=0;label<2;label++){  // bernoulli Nb so labels will only be 0/1.
            double likelihood=1.0;
            for(int i=0;i<n_features;i++){
                double cond = conditional_prob(x_train,y_train,i,x_test[i],label);
                int b;
                likelihood *= ((cond)*x_test[i] + (1-cond)*(1-x_test[i]));   // P(x=f1 / y=class)*(x[i]) + (1-P(x=f1 / y=class))*(1-x[i])
            }

            double prior = prior_prob(y_train,label);
            double post = prior*likelihood;
            post_probs.push_back(post);
        }
        double sumprop_probs = 0.0;
        int max=0;
        for(int i=0;i<post_probs.size();i++){
            sumprop_probs += post_probs[i];
        }
        for(int i=0;i<post_probs.size();i++){
            post_probs[i] /= sumprop_probs;
            if(post_probs[i]>post_probs[max]){
                max = i;
            }
        }
        return max;
    };
