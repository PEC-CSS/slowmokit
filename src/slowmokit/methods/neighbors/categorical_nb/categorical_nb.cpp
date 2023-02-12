/**
 * @file methods/neighbors/gaussian_nb/categorical_nb.cpp
 *
 * Implementation of the Categorical Naive Bayes main program
 */

#include "categorical_nb.hpp"

template<class T>

std::string fitPredict(std::vector<std::vector<T>> xTrain,
                       std::vector<std::string> yTrain, std::vector<T> xTest)
{
  // posterior = (prior * likelihood)/evidence
  // since, evidence is same among all instances -> we can ignore it

  if (xTrain.size() == 0 || yTrain.size() == 0)
    throw "Make sure that you have atleast one train example";
  if (xTrain.size() != yTrain.size())
    throw "Number of features and target must be equal";

  std::map<std::string, double> priors;
  std::map<std::string, int> occurences;

  for (auto category : yTrain)
  {
    occurences[category]++;
  }
  for (auto current : occurences)
  {
    priors[current.first] = double(current.second) / yTrain.size();
  }
  // priors calculated

  std::map<std::string, std::map<T, double>> likelihoods;
  // for any ith label -> n instances -> for each differ probability
  std::map<std::string, std::map<T, int>> counts;

  for (int i = 0; i < xTrain.size(); i++)
  {
    std::vector<T> current = xTrain[i]; // current row
    for (auto curr : current)
    {
      counts[yTrain[i]][curr]++;
      // inc count of curr instance corresponding to ith label
    }
  }
  for (auto current : counts)
  {
    for (auto e : current.second)
    {
      likelihoods[current.first][e.first] =
          ((double(e.second)) / (occurences[current.first]));
      // likelihood[label][current feature]=occ in current/total no of occ
    }
  }
  // likelihoods done

  std::map<std::string, double> probs;
  for (auto curr : priors)
  {
    probs[curr.first] = curr.second;
    for (auto feature : xTest)
    {
      // if(likelihoods[curr.first][feature]==0){ continue;}
      probs[curr.first] *= likelihoods[curr.first][feature];
    }
  }
  double maxProb = 0;
  std::string out = "";
  for (auto prob : probs)
  {
    if (prob.second > maxProb)
    {
      maxProb = prob.second;
      out = prob.first;
    }
  }

  return out;
}