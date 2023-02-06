/**
 * @file methods/cluster/kMeans/kMeans.hpp
 *
 * The header file including the kMeans
 */

#ifndef SLOWMOKIT_SILHOUTTE_SCORE_HPP
#define SLOWMOKIT_SILHOUTTE_SCORE_HPP

#include "../../../core.hpp"

template<class T>
class SilhoutteScore{
public:
    /**
     * @brief Calculate Silhoutte score for particular number of clusters
     * 
     * @param x all x values
     * @param y cluster to which points belong
     * @param numClusters number of clusters
     * @param typeDist which distance function you required euclidean/else
     * @return double value of silhoutte score
     */
    double calculate(std::vector<std::vector<T>> x,std::vector<int> y,int numClusters,std::string typeDist);
};

#endif //SLOWMOKIT_SILHOUTTE_SCORE_HPP