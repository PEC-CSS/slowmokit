/**
 * @file methods/metrics/silhouette_score.cpp
 *
 * Implementation of the silhouette Score main program
 */

#include "silhouette_score.hpp"
template<class T>
double silhouetteScore(std::vector<std::vector<T>> x, std::vector<int> y,
                       int numClusters, std::string typeDist)
{
  if (x.size() != y.size())
  {
    throw std::invalid_argument("Size of x and y values are not same");
    return -1;
  }

  if (numClusters < 2 or x.size() - 1 < numClusters)
  {
    throw std::invalid_argument("Invalid arguments sizes of x or numClusters");
    return -1;
  }

  std::transform(typeDist.begin(), typeDist.end(), typeDist.begin(),
                 [](unsigned char c) { return std::tolower(c); });

  std::vector<std::vector<double>> distances(x.size(),
                                             std::vector<double>(x.size()));
  for (int i = 0; i < x.size(); i++)
  { // iterating over each x[i]
    for (int j = 0; j < x.size(); j++)
    { // iterating over each x[i]
      if (i == j)
      {
        distances[i][j] = 0.0; // initialize distance=0 if computing
                               // distance between same values
      }
      else
      {
        if (typeDist == "euclidean")
        { // euclidean distance
          for (int k = 0; k < x[0].size(); k++)
          {
            distances[i][j] +=
                (x[i][k] - x[j][k]) *
                (x[i][k] - x[j][k]); // x[i][k]-> i=point,k=1-d value of point
          }
          const double HALF = 0.5;
          distances[i][j] = pow(distances[i][j], HALF);
        }
        else if (typeDist == "manhattan")
        {
          for (int k = 0; k < x[0].size(); k++)
          {
            distances[i][j] += abs(x[i][k] - x[j][k]);
          }
        }
      }
    }
  }

  std::vector<double> intraClusters(
      x.size(), 0.0); // Computing intraclusters distances of each point
  std::vector<double> crossClusters(
      x.size()); // Minimum Distance of each point to other clusters
  for (int i = 0; i < x.size(); i++)
  {
    int sumNum = 0;
    std::vector<double> interClusters(
        numClusters,
        0.0); // values of point to each cluster points
    std::vector<int> sumsOfParticular(numClusters, 0);
    for (int j = 0; j < x.size(); j++)
    {
      if (y[j] == y[i])
      {
        intraClusters[i] += distances[i][j]; // Sum of distance of point to each
                                             // other point in same cluster
        sumNum++;
      }
      else
      {
        interClusters[y[j]] += distances[i][j]; // Sum of distance of point to
                                                // points in different clusters
        sumsOfParticular[y[j]]++; // computes points in that cluster
      }
    }
    intraClusters[i] /= sumNum; // Mean of sum values of distances b/w
                                // points of same cluster
    double minimumOfall = std::numeric_limits<double>::max();
    ;
    for (int j = 0; j < numClusters; j++)
    {
      if (j != y[i])
      {
        interClusters[j] /= sumsOfParticular[j]; // Mean of values of
                                                 // interclusters distances
        if (interClusters[j] < minimumOfall)
        { // computing minimum value of means of intercluster distances
          minimumOfall = interClusters[j];
        }
      }
    }
    crossClusters[i] = minimumOfall;
  }
  double si = 0.0;
  for (int i = 0; i < x.size(); i++)
  {
    si += ((crossClusters[i] - intraClusters[i]) /
           std::max(intraClusters[i],
                    crossClusters[i])); // s = b[i]-a[i] / max(b[i],a[i])
  }
  return si / double(x.size());
};