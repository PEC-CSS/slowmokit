/**
 * @file methods/neighbors/gaussian_nb/gaussian_nb.cpp
 *
 * Implementation of the Gaussian Naive Bayes main program
 */

#include "gaussian_nb.hpp"

template<class T>
    double prior_prob(std::vector<int> y_train,int label){  //Prior Probability
        int sum=0;
        for(int i=0;i<y_train.size();i++){
            if(y_train[i]==label){
                sum += 1;
            }
        }
        return sum/double(y_train.size());
    }

template<class T>
    double conditional_prob(int mean,int variance,int feature){ 
        //Conditional probabilty  P(x=f1 / y=class) = __________1____________ * e^( -_____(feature-mean)^2_____)
        //                                           ((2*pi*variance^2)^(1/2))    (        2 * variance^2      )
        double den = pow((2*3.14*variance*variance),0.5);
        double inside_exp = -1*pow((feature-mean),2);
        inside_exp /= (2*variance*variance);
        double num = exp(inside_exp);
        return num/den;
    }

template<class T>
    int predict(std::vector<std::vector<T>> x_train,std::vector<int> y_train,std::vector<T> x_test,std::vector<int> classes){
        int n_features = x_train[0].size();

        std::vector<double> post_probs;

        std::vector<double> means(x_train[0].size());
        std::vector<double> variances(x_train[0].size());

        double sum=0.0;

        for(int i=0;i<x_train[0].size();i++){
            for(int j=0;j<x_train.size();j++){
                sum += x_train[j][i];
            }
            means[i] = sum/double(x_train.size()); // Computing means
            sum=0.0;
        }

        sum=0.0;

        for(int i=0;i<x_train[0].size();i++){
            for(int j=0;j<x_train.size();j++){
                sum += pow((x_train[j][i]-means[i]),2);
            }
            variances[i] = pow((sum/double(x_train.size())),0.5);  // Computing variances of each column
            sum = 0.0;
        }

        std::vector<int> ::iterator label;
        double sumprop_probs = 0.0;
        for(label=classes.begin();label!=classes.end();label++){
            double likelihood=1.0;
            for(int i=0;i<n_features;i++){
                double cond = conditional_prob(means[i],variances[i],x_test[i]);  // Conditional prob of each column
                likelihood *= cond;
            }

            double prior = prior_prob(y_train,*label);
            double post = prior*likelihood;
            post_probs.push_back(post);
            sumprop_probs += post;
        }
        int max=0;
        for(int i=0;i<post_probs.size();i++){
            post_probs[i] /= sumprop_probs;
            if(post_probs[i]>post_probs[max]){
                max = i;
            }
        }
        return max;
    };

signed main(){
    std::vector<std::vector<double>> x_train{
        {6,180,12},
        {5.92,190,11},
        {5.58,170,12},
        {5.92,165,10},
        {5,100,6},
        {5.5,150,8},
        {5.42,130,7},
        {5.75,150,9},
    };
    std::vector<int> y_train{0,0,0,0,1,1,1,1};
    std::vector<double> x_test{6,130,8};
    std::vector<int> classes{0,1};
    GaussianNB<double> gaussian;
    std::cout<<gaussian.predict(x_train,y_train,x_test,classes);
    return 0;
}