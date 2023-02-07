/**
 * @file methods/linear_model/logistic_regression/logistic_regression.cpp
 *
 * Implementation of the Logistic Regression main program
 */

#include "logistic_regression.hpp"

template<class T>
    std::vector<double> LogisticRegression<T>::softmax(std::vector<T> x){ // Softmax function
        std::vector<double> exps(x.size());
        double sum = 0.0;
        for(int i=0;i<x.size();i++){  // Iterating over vector to compute sum of all exponential values in vector
            exps[i] = exp(x[i]);
            sum += exps[i];
        }
        std::vector<double> values(x.size());
        for(int i=0;i<x.size();i++){  // Now computing actual values after applying softmax
            values[i] = exps[i]/double(sum);
        }
        return values;
    };

template<class T>
    double LogisticRegression<T>::crossEntropy(std::vector<int> y,std::vector<T> qi){  // Gives gradient descent -(d(z)/d(theta))
        double l = 0.0;
        for(int i=0;i<y.size();i++){
            l += (y[i]*qi[i]);
        }
        return -1*l;
    };

template<class T>
    double LogisticRegression<T>::EvalL(std::vector<std::vector<T>> x,std::vector<std::vector<int>>y,std::vector<std::vector<T>>  beta){  // Computing overall loss in single epoch
        int n = x.size();
        double loss = 0.0;
        for(int i=0;i<n;i++){
            std::vector<double> xiHat = x[i];
            std::vector<int> yi = y[i];
            std::vector<double> qi(beta.size(),0.0);
            for(int j=0;j<beta.size();j++){
                for(int k=0;k<xiHat.size();k++){
                    qi[j] += beta[j][k]*xiHat[k];
                }
            }
            qi = softmax(qi);  // qi = z[i] = x[i]*theta[i];
            loss += crossEntropy(yi,qi);  // Computing loss using z[i](computed values) and y[i](actual values)
        }
        return loss;
    };

template<class T>
    std::vector<std::vector<double>> LogisticRegression<T>::logRegSgd(std::vector<std::vector<double>> x,std::vector<std::vector<int>> y,double alpha,int numEpochs,bool verbose){  // PERFORMS MULTICLASS LOGISTIC REGRESSION
        int n = x.size();  // Rows in training vector
        int d = x[0].size();   // Columns
        int numClasses = y[0].size();  // Output classes
        std::vector<std::vector<double>> beta(numClasses,std::vector<double>(d,0.0));  // Initializing weights (output_classes * features)
        std::vector<double> lVals(numEpochs);
        for(int i=0;i<numEpochs;i++){
            double l = EvalL(x,y,beta);
            lVals.push_back(l);

            if(verbose){
                std::cout<<"Epoch: "<<i<<" "<<"Loss: "<<l<<std::endl;
            }

            std::vector<int> prm(n);  // Making vector of size 'n' so that we can randomly shuffle number from 0-n-1 and choose values in random order to perform regression 
            for(int j=0;j<n;j++){
                prm[j] = j;
            }

            std::random_shuffle(prm.begin(),prm.end()); // random shuffling

            while(!prm.empty()){
                int frnt = prm.back();  // back value of vector
                std::vector<double> xiHat = x[frnt];
                std::vector<int> yi = y[frnt];
                std::vector<double> zi(numClasses,0.0);

                // z[i] = weight[ouput class][j-th weight] * x[i-th row][j-th feature]

                for(int j=0;j<numClasses;j++){  // Iterating over classes of output
                    for(int k=0;k<xiHat.size();k++){  // Iterating over x[i]
                        zi[j] += beta[j][k]*xiHat[k];  
                    }
                }
                zi = softmax(zi);

                std::vector<std::vector<double>> gradLi(numClasses,std::vector<double>(xiHat.size()));
                for(int j=0;j<numClasses;j++){
                    for(int k=0;k<xiHat.size();k++){
                        gradLi[j][k] = (zi[j]-yi[j])*xiHat[k];
                        beta[j][k] -= alpha*gradLi[j][k];  // Altering value of beta according to the computed loss
                    }
                }

                prm.pop_back();
            }
        }
        return beta;
    };

template<class T>
    void LogisticRegression<T>::train(std::vector<std::vector<T>> x,std::vector<std::vector<int>> y,double alpha,int numEpochs,bool verbose){
        this->beta = logRegSgd(x,y,alpha,numEpochs,verbose);
    };
    
template<class T>    
    std::vector<double> LogisticRegression<T>::predict(std::vector<T> x){ //Predict probabilities of each class
        std::vector<double> probs(beta.size(),0.0);
        for(int i=0;i<beta.size();i++){
            for(int j=0;j<x.size();j++){
                probs[i] += beta[i][j]*x[j];
            }
        }
        probs = softmax(probs);
        return probs;
    };