#include "core.hpp"
using namespace std;

class KNN{
    float distance(vector<float> x1,vector<float> x2){
        float dist=0;
        for(int i=0;i<x1.size();i++){
            dist += pow(x1[i]-x2[i],2);
        }
        return pow(dist,0.5);
    }

public:
    int predict(vector<vector<float>> x,vector<int> y,vector<float> test,int k,int classNums){
        vector<int> nearestK(k);
        priority_queue<vector<float>> pq;
        for(int i=0;i<x.size();i++){
            float dist = distance(x[i],test);
            if(pq.empty()){
                vector<float> temp(2);
                temp[0] = dist;
                temp[1] = float(y[i]);
                pq.push(temp);
            }
            else if(pq.size()<5){
                vector<float> temp(2);
                temp[0] = dist;
                temp[1] = float(y[i]);
                pq.push(temp);
            }
            else if(pq.top()[0]>dist){
                pq.pop();
                vector<float> temp(2);
                temp[0] = dist;
                temp[1] = float(y[i]);
                pq.push(temp);
            }
        }
        vector<int> calculatetimes(classNums,0);
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
};