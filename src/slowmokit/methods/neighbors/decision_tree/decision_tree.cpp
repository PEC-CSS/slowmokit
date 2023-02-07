/**
 * @file methods/neighbors/decision_tree/decision_tree.cpp
 *
 * Implementation of the Decsion Tree main program
 */

#include "decision_tree.hpp"

template<class T>
    double DecisionTree<T>::entropy(std::vector<double> col){
        std::set<double> unique;
        for(int i=0;i<col.size();i++){
            unique.insert(col[i]);
        }
        double ent=0.0;
        std::set<double> ::iterator it;
        for(it=unique.begin();it!=unique.end();it++){
            // cout<<*it<<endl;
            double p = *it/double(col.size());
            if(p==0){
                ent += 0.0;
            }
            else{
                ent += (-1)*p*log2(p);
            }
        }
        return ent;
    }

template<class T>
    std::vector<std::vector<std::vector<double>>> DecisionTree<T>::divideData(std::vector<std::vector<double>> xData,int fkey,int fval){
        std::vector<std::vector<double>> xLeft;
        std::vector<std::vector<double>> xRight;
        for(int i=0;i<xData.size();i++){
            double val = xData[i][fkey];
            std::vector<double> temp = xData[i];
            if(val>fval){
                xRight.push_back(temp);
            }
            else{
                xLeft.push_back(temp);
            }
        }
        std::vector<std::vector<std::vector<double>>> output{xLeft,xRight};
        return output;
    }

template<class T>
    double DecisionTree<T>::infoGain(std::vector<std::vector<double>> xData,int fkey,int fval){  // fkey refers to the feature/column index; fval refers to the mean value/splitting value
        // Splitting data
        std::vector<std::vector<double>> left,right;
        std::vector<std::vector<std::vector<double>>> temp = divideData(xData,fkey,fval);
        left = temp[0];
        right = temp[1];
        double l = left.size()/double(xData.size());
        double r = right.size()/double(xData.size());
        if(left.size()==0 or right.size()==0){
            return -1;
        }
        std::vector<double> y_data,lY,rY; 
        int y = xData[0].size()-1;
        for(int i=0;i<xData.size();i++){
            y_data.push_back(xData[i][y]);
        }
        for(int i=0;i<left.size();i++){
            lY.push_back(xData[i][y]);
        }
        for(int i=0;i<right.size();i++){
            rY.push_back(xData[i][y]);
        }
        double iGain = entropy(y_data) - (l*entropy(lY) + r*entropy(rY));
        return iGain;
    }

template<class T>
    DecisionTree<T>::DecisionTree(int maxD,int minSamplesL,int maxF){
        this->maxDepth = maxD;
        this->minSamplesLeaf = minSamplesL;
        this->maxFeatures = maxF;  // maxFeatures is the number of features to be considered to do splitting at each node
    }

template<class T>
    void DecisionTree<T>::train(std::vector<std::vector<double>> xData){
        int max = xData[0].size()-2;
        int range = max+1;

        features.clear();  // clearing features set to select features to be considered 

        while(features.size()!=maxFeatures){
            features.insert(rand()%range);  // Inserting features 
        }

        std::vector<double> infoGains(maxFeatures);
        std::vector<double> mean(maxFeatures);
        int cnt=0;
        for(int i=0;i<xData[0].size()-1;i++){
            if(i==*features.cbegin()){
                features.erase(i);
                for(int j=0;j<xData.size();j++){
                    mean[cnt] += xData[j][i];
                }
                double iGain=infoGain(xData,i,mean[cnt]/double(xData.size()));
                infoGains[cnt] = iGain;
                cnt++;
            }
        }
        max=0;
        for(int i=0;i<maxFeatures;i++){
            if(infoGains[i]>infoGains[max]){
                max=i;
            }
        }
        fkey = max;
        fval = mean[max]/double(xData.size());
        // std::cout<<"Making tree feature is "<<fkey<<std::endl;

        // Split data
        std::vector<std::vector<std::vector<double>>> temp = divideData(xData,fkey,fval);
        std::vector<std::vector<double>> dataLeft = temp[0];
        std::vector<std::vector<double>> dataRight = temp[1];

        if(dataLeft.size()<=minSamplesLeaf or dataRight.size()<=minSamplesLeaf){
            double mean=0.0;
            int y =xData[0].size()-1;
            for(int i=0;i<xData.size();i++){
                mean += xData[i][y];
            }
            if(mean/double(xData.size())>=0.5){
                target = 1;
            }
            else{
                target=0;
            }
            return;
        } 
        if(depth>=maxDepth){
            double mean=0.0;
            int y = xData[0].size()-1;
            for(int i=0;i<xData.size();i++){
                mean += xData[i][y];
            }
            if(mean/double(xData.size())>=0.5){
                target = 1;
            }
            else{
                target=0;
            }
            return;
        }

        left = new DecisionTree(maxDepth,minSamplesLeaf,maxFeatures);
        left->depth = depth+1;
        left->train(dataLeft);
        right = new DecisionTree(maxDepth,minSamplesLeaf,maxFeatures);
        right->depth = depth+1;
        right->train(dataRight);

        double mea=0.0;
        int y = xData[0].size()-1;
        for(int i=0;i<xData.size();i++){
            mea += xData[i][y];
        }
        if((mea/double(xData.size()))>=0.5){
            target = 1;
        }
        else{
            target = 0;
        }
        return;
    }

template<class T>
    int DecisionTree<T>::predict(std::vector<double> test){
        if(test[fkey]>fval){
            if(right==NULL){
                return target;
            }
            return right->predict(test);
        }
        else{
            if(left==NULL){
                return target;
            }
            return left->predict(test);
        }
    }