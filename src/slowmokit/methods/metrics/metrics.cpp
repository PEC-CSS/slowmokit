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