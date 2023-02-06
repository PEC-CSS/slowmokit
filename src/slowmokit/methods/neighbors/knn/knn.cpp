/**
 * @file methods/neighbors/knn/knn.cpp
 *
 * Implementation of the KNN main program
 */
#include "knn.hpp"

template<class T>
double distance(std::vector<T> x1,std::vector<T> x2){
    double dist=0;
    for(int i=0;i<x1.size();i++){
        dist += pow(x1[i]-x2[i],2);
    }
    return pow(dist,0.5);
}

template<class T>
void fit(std::vector<std::vector<T>> x,std::vector<int> y,int k,int classNums){
    this->xTrain = x;
    this->yTrain = y;
    this->k = k;
    this->classNums = classNums;
}

template<class T>
int predict(std::vector<T> test){
    std::vector<int> nearestK(k);
    std::priority_queue<std::vector<double>> pq;
    for(int i=0;i<xTrain.size();i++){
        double dist = distance(xTrain[i],test);
        if(pq.empty()){
            std::vector<double> temp(2);
            temp[0] = dist;
            temp[1] = double(yTrain[i]);
            pq.push(temp);
        }
        else if(pq.size()<5){
            std::vector<double> temp(2);
            temp[0] = dist;
            temp[1] = double(yTrain[i]);
            pq.push(temp);
        }
        else if(pq.top()[0]>dist){
            pq.pop();
            std::vector<double> temp(2);
            temp[0] = dist;
            temp[1] = double(yTrain[i]);
            pq.push(temp);
        }
    }
    std::vector<int> calculatetimes(classNums,0);
    for(int i=0;i<pq.size();i++){
        calculatetimes[int(pq.top()[1])] += 1;
        pq.pop();
    }
    int max=0;
    for(int i=0;i<classNums;i++){
        if(calculatetimes[i]>calculatetimes[max]){
                max=i;
        }
    }
    return max;
}   