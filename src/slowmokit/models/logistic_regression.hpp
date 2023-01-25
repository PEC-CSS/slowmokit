#include "core.hpp"
using namespace std;

class LogisticRegression{
    double sigmoid(double x){
        return 1.0/(1.0+exp(-x));
    }

    vector<double> hypothesis(vector<vector<double>> x,vector<double> theta){
        vector<double> toReturn(x.size(),0);
        for(int i=0;i<x.size();i++){
            for(int j=0;j<x[i].size();j++){
                toReturn[i] += x[i][j]*theta[j];
            }
            toReturn[i] = sigmoid(toReturn[i]);
        }
        return toReturn;
    }

    double error(vector<vector<double>> x,vector<int> y,vector<double> theta){
        vector<double> hi = hypothesis(x,theta);
        double err;
        for(int i=0;i<y.size();i++){
            err += (y[i]*log10(hi[i]) + (1-y[i])*(log10(1-hi[i])));
        }
        return -1*(err/y.size());
    }

    vector<double> gradient(vector<vector<double>> x,vector<int> y,vector<double> theta){
        vector<double> hi = hypothesis(x,theta);
        vector<double> grad(theta.size(),0);
        for(int i=0;i<theta.size();i++){
            for(int j=0;j<y.size();j++){
                grad[i] += x[j][i]*(y[j]-hi[j]);
            }
            grad[i] /= y.size();
        }
        return grad;
    } 

public:

    vector<double> train(vector<vector<double>> x,vector<int> y,double lr,int itr){
        vector<double> theta(y.size(),0);
        for(int i=0;i<itr;i++){
            double err = error(x,y,theta);
            vector<double> grad = gradient(x,y,theta);
            for(int j=0;j<grad.size();j++){
                theta[j] += lr*grad[j];
            }
        }
        return theta;
    }

    vector<int> predict(vector<vector<double>> x,vector<double> theta){
        vector<double> hi = hypothesis(x,theta);
        vector<int> output(hi.size());
        for(int i=0;i<hi.size();i++){
            if(hi[i]>=0.5){
                output[i] = 1;
            }
            else{
                output[i] = 0;
            }
        }
        return output;
    }
};