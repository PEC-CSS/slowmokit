#include "core.hpp"
using namespace std;

class KMeans{
    vector<vector<double>> globalClusters;

    double distance(vector<double> v1,vector<double> v2){
        double dist=0.0;
        for(int i=0;i<v1.size();i++){
            dist += pow(v1[i]-v2[i],2);
        }
        return pow(dist,0.5);
    }

    vector<int> assignPointToClusters(vector<vector<double>> x,vector<vector<double>> clusters){
        vector<int> xClusters(x.size());
        for(int i=0;i<x.size();i++){
            int min=0;
            vector<double> dist(clusters.size());
            for(int j=0;j<clusters.size();j++){
                dist[j] = distance(x[i],clusters[j]);
                if(dist[j]<dist[min]){
                    min = j;
                }
            }
            xClusters[i] = min;
        }
        return xClusters;
    }

    vector<vector<double>> updateClusters(vector<vector<double>> x,vector<int> xCluster,vector<vector<double>> clusters){
        vector<vector<double>> newClusters(clusters.size(),vector<double>(clusters[0].size(),0));
        vector<int> count(clusters.size(),0);
        for(int i=0;i<x.size();i++){
            for(int j=0;j<clusters[0].size();j++){
                newClusters[xCluster[i]][j] += x[i][j];
            }
            count[xCluster[i]] += 1;
        }
        for(int i=0;i<newClusters.size();i++){
            for(int j=0;j<newClusters[i].size();j++){
                if(count[i]!=0){
                    newClusters[i][j] /= count[i];
                }
            }
        }
        return newClusters;
    }

public:
    void train(vector<vector<double>> x,int numClusters,int epochs){
        vector<vector<double>> clusters(numClusters,vector<double>(x[0].size()));
        for(int i=0;i<numClusters;i++){
            for(int j=0;j<clusters[i].size();j++){
                clusters[i][j] = double(i);
            }
        }
        for(int i=0;i<epochs;i++){
            vector<int> xClusters = assignPointToClusters(x,clusters);
            clusters = updateClusters(x,xClusters,clusters);
        }
        globalClusters = clusters;
        return;
    }   

    int predict(vector<double> test){
        int min = 0;
        vector<double> distVector(globalClusters.size());
        for(int i=0;i<globalClusters.size();i++){
            distVector[i] = distance(globalClusters[i],test);
            if(distVector[i]<distVector[min]){
                min = i;
            }
        }
        return min;
    }
    vector<vector<double>> clusters_(){
        return globalClusters;
    }
};