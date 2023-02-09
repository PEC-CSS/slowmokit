/**
 * @file methods/metrics/silhoutte_score.hpp
 *
 * Easy include to find Silhoutte score
 */

#ifndef SLOWMOKIT_ACCURACY_HPP
#define SLOWMOKIT_ACCURACY_HPP
#include "../../core.hpp"

template<class T>
double SilhoutteScore(std::vector<std::vector<T>> x, std::vector<int> y,
                      int numClusters, std::string typeDist);

#endif // SLOWMOKIT_SILHOUTTE_SCORE_HPP