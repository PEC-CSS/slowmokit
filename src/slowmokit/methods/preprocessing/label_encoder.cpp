/**
 * @file methods/preprocessing/label_encoder.cpp
 *
 * Implementation of label encoder
 */

#include "label_encoder.hpp"
template<class T>
std::vector<int> labelEncoder(std::vector<T>& input ){
    std::map<T,int> indices;
    int currIndex =0;
    for(auto e : input){
        if(indices.count(e)!=0){
            continue;
        }
        indices[e]=currIndex;
        currIndex++;
    }
    std::vector<int> encodedData (input.size());
    int i=0;
    for(auto e : input){
        int curr = indices[e];
        encodedData[i]=curr;
        i++;
    }
    return encodedData;
}



