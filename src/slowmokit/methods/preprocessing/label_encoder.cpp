/**
 * @file methods/preprocessing/label_encoder.hpp
 *
 * Implementation of label encoder
 */

#include "label_encoder.hpp"

template<class T>
std::vector<int> label_encoder(std::vector<T>& input ){
    std::map<T,int> indices;
    int curr_index =0;
    for(auto e : input){
        if(indices.count(e)!=0){
            continue;
        }
        indices[e]=curr_index;
        curr_index++;
    }
    std::vector<int> encoded_data (input.size());
    int i=0;
    for(auto e : input){
        int curr = indices[e];
        encoded_data[i]=curr;
        i++;
    }
    return encoded_data;
}



