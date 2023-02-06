/**
 * @file methods/neighbors/gaussian_nb/gaussian_nb.cpp
 *
 * Implementation of the Gaussian Naive Bayes main program
 */

#include "gaussian_nb.hpp"

template<class T>
    T priorProb(std::vector<int> yTrain,int label){  //Prior Probability
        int sum=0;
        for(int i=0;i<yTrain.size();i++){
            if(yTrain[i]==label){
                sum += 1;
            }
        }
        return sum/T(yTrain.size());
    }

template<class T>
    T conditionalProb(int mean,int variance,int feature){ 
        //Conditional probabilty  P(x=f1 / y=class) = __________1____________ * e^( -_____(feature-mean)^2_____)
        //                                           ((2*pi*variance^2)^(1/2))    (        2 * variance^2      )
        T den = pow((2*3.14*variance*variance),0.5);
        T insideExp = -1*pow((feature-mean),2);
        insideExp /= (2*variance*variance);
        T num = exp(insideExp);
        return num/den;
    }

template<class T>
    int fitPredict(std::vector<std::vector<T> > xTrain,std::vector<int> yTrain,std::vector<T> xTest,std::vector<int> classes){
        int nFeatures = xTrain[0].size();

        std::vector<T> postProbs;

        std::vector<T> means(xTrain[0].size());
        std::vector<T> variances(xTrain[0].size());

        T sum=0.0;

        for(int i=0;i<xTrain[0].size();i++){
            for(int j=0;j<xTrain.size();j++){
                sum += xTrain[j][i];
            }
            means[i] = sum/T(xTrain.size()); // Computing means
            sum=0.0;
        }

        sum=0.0;

        for(int i=0;i<xTrain[0].size();i++){
            for(int j=0;j<xTrain.size();j++){
                sum += pow((xTrain[j][i]-means[i]),2);
            }
            variances[i] = pow((sum/T(xTrain.size())),0.5);  // Computing variances of each column
            sum = 0.0;
        }

        std::vector<int> ::iterator label;
        T sumpropProbs = 0.0;
        for(label=classes.begin();label!=classes.end();label++){
            T likelihood=1.0;
            for(int i=0;i<nFeatures;i++){
                T cond = conditionalProb(means[i],variances[i],xTest[i]);  // Conditional prob of each column
                likelihood *= cond;
            }

            T prior = priorProb(yTrain,*label);
            T post = prior*likelihood;
            postProbs.push_back(post);
            sumpropProbs += post;
        }
        int max=0;
        for(int i=0;i<postProbs.size();i++){
            postProbs[i] /= sumpropProbs;
            if(postProbs[i]>postProbs[max]){
                max = i;
            }
        }
        return max;
    };