#include "core.hpp"
using namespace std;

class BernoulliNB{
    double prior_prob(vector<int> y_train,int label){
        int sum=0;
        for(int i=0;i<y_train.size();i++){
            if(y_train[i]==label){
                sum += 1;
            }
        }
        return sum/double(y_train.size());
    }

    double conditional_prob(vector<vector<int>> x_train,vector<int> y_train,int feature_col,int feature_val,int label){
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

public:
    int predict(vector<vector<int>> x_train,vector<int> y_train,vector<int> x_test){
        int n_features = x_train[0].size();

        vector<double> post_probs;

        for(int label=0;label<2;label++){
            double likelihood=1.0;
            for(int i=0;i<n_features;i++){
                double cond = conditional_prob(x_train,y_train,i,x_test[i],label);
                int b;
                likelihood *= ((cond)*x_test[i] + (1-cond)*x_test[i]);
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
    }
};