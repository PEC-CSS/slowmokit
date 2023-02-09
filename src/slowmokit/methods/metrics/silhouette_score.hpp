/**
 * @file methods/metrics/silhoutte_score.hpp
 *
 * Easy include to find Silhoutte score
 */

#ifndef SLOWMOKIT_SILHOUETTE_SCORE_HPP
#define SLOWMOKIT_SILHOUETTE_SCORE_HPP
#include "../../core.hpp"

template<class T>
double SilhouetteScore(std::vector<std::vector<T>> x, std::vector<int> y,
                       int numClusters, std::string typeDist);

#endif // SLOWMOKIT_SILHOUETTE_SCORE_HPP