/**
 * @file methods/metrics/metrics.hpp
 *
 * Easy include to execute all the functions of class metrics
 */

#include "metrics.hpp"


template<class T>
double Metrics<T>::accuracy(const std::vector<T> &pred,
                            const std::vector<T> &trueLabels)
{
  if (pred.size() != trueLabels.size())
  {
    throw std ::invalid_argument("pred and true_labels must have same size");
  }
  int correct = 0;
  int total = pred.size();
  for (int i = 0; i < total; i++)
  {
    if (pred[i] == trueLabels[i])
    {
      correct++;
    }
  }
  return (double) correct / total;
}

template<class T>
double Metrics<T>::meanSquaredError(const std::vector<T> &actual,
                                    const std::vector<T> &pred)
{
  if (actual.size() != pred.size())
  {
    throw std::invalid_argument(
        "Actual and Predicted vectors must have same size");
  }

  double sum = 0.0;
  for (int i = 0; i < actual.size(); i++)
  {
    sum += (actual[i] - pred[i]) * (actual[i] - pred[i]);
  }
  return sum / actual.size();
}

template<class T>
std::map<T, double> Metrics<T>::precision(const std::vector<T> &pred,
                                          const std::vector<T> &actual)
{
  if (pred.size() != actual.size())
  {
    throw std::invalid_argument(
        "Predicted and actual vectors must have same size");
  }
  int n = actual.size();
  std::set<T> s;
  for (int i = 0; i < n; i++)
  {
    s.insert(actual[i]);
  }
  int numClasses = s.size();
  std::map<T, double> precisionMap;
  std::map<T, int> truePosMap, falsePosMap;

  for (int i = 0; i < n; i++)
  {
    if (pred[i] == actual[i])
    {
      truePosMap[actual[i]]++;
    }
    else
    {
      falsePosMap[pred[i]]++;
    }
  }

  for (int i = 0; i < numClasses; i++)
  {
    if (truePosMap[i] > 0 || falsePosMap[i] > 0)
    {
      precisionMap[i] =
          (double) (truePosMap[i] / (double) (truePosMap[i] + falsePosMap[i]));
    }
    else
    {
      precisionMap[i] = 1.0;
    }

    double x = precisionMap[i];
    float value = (int) (x * 100 + .5);
    precisionMap[i] = (float) value / 100;
  }

  return precisionMap;
}


template<class T>
std::map<T, double> Metrics<T>::recall(const std::vector<T> &pred,
                                       const std::vector<T> &actual)
{
  if (pred.size() != actual.size())
  {
    throw std::invalid_argument(
        "Predicted and actual vectors must have same size");
  }
  int n = actual.size();
  std::set<T> s;
  for (int i = 0; i < n; i++)
  {
    s.insert(actual[i]);
  }
  int numClasses = s.size();
  std::map<T, double> recallMap;
  std::map<T, int> truePosMap, falseNegMap;
  for (int i = 0; i < n; i++)
  {
    if (pred[i] == actual[i])
    {
      truePosMap[actual[i]]++;
    }
    else
    {
      falseNegMap[actual[i]]++;
    }
  }

  for (int i = 0; i < numClasses; i++)
  {
    if (truePosMap[i] > 0 || falseNegMap[i] > 0)
    {
      recallMap[i] =
          (double) (truePosMap[i] / (double) (truePosMap[i] + falseNegMap[i]));
    }
    else
    {
      recallMap[i] = 1.0;
    }

    double x = recallMap[i];
    float value = (int) (x * 100 + .5);
    recallMap[i] = (float) value / 100;
  }


  return recallMap;
}

template<class T>
std::map<T, double> Metrics<T>::f1Score(const std::vector<T> &pred,
                                        const std::vector<T> &actual)
{
  // 2 * Precision * Recall / (Precision + Recall)
  std::map<T, double> precisionMap, recallMap;
  precisionMap = precision(pred, actual);
  recallMap = recall(pred, actual);
  std::map<T, double> f1ScoreMap;
  for (int i = 0; i < precisionMap.size(); i++)
  {
    T classNumber = i;
    if (precisionMap[classNumber] == 0 || recallMap[classNumber] == 0)
    {
      f1ScoreMap[classNumber] = 0;
    }
    else
    {
      f1ScoreMap[classNumber] = (2 * (double) precisionMap[classNumber] *
                                 (double) recallMap[classNumber]) /
                                ((double) precisionMap[classNumber] +
                                 (double) recallMap[classNumber]);

      double x = f1ScoreMap[classNumber];
      float value = (int) (x * 100 + .5);
      f1ScoreMap[classNumber] = (float) value / 100;
    }
  }
  return f1ScoreMap;
}

template<class T>
double Metrics<T>::silhouetteScore(const std::vector<std::vector<T>> x,
                                   const std::vector<int> y, int numClusters,
                                   std::string typeDist)
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
}