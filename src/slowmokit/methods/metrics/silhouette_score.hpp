/**
 * @file methods/metrics/silhoutte_score.hpp
 *
 * Easy include to find Silhoutte score
 */

#ifndef SLOWMOKIT_SILHOUETTE_SCORE_HPP
#define SLOWMOKIT_SILHOUETTE_SCORE_HPP
#include "../../core.hpp"

template<class T>
/**
 * @brief Calculates Silhouette Score
 *
 * @param vector<vector<T>> x values
 * @param vector<int> y values
 * @param int number of clusters
 * @param string distance type
 * @return double Silhouette Score
 */
double silhouetteScore(std::vector<std::vector<T>>, std::vector<int>, int,
                       std::string);

#endif // SLOWMOKIT_SILHOUETTE_SCORE_HPP