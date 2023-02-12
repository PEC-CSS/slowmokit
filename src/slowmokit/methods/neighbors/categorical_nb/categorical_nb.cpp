/**
 * @file methods/neighbors/gaussian_nb/categorical_nb.cpp
 *
 * Implementation of the Categorical Naive Bayes main program
 */

#include "categorical_nb.hpp"
std::map<std::string, double> priors;
std::map<std::string, std::map<std::string , double>> likelihoods;  // for each label we will store a map , containing n features and their corresponding probability
template<class T>
void fit(std::vector<std::vector<T>> xTrain,
                       std::vector<std::string> yTrain)
{
  // posterior = (prior * likelihood)/evidence
  // since, evidence is same among all instances -> we can ignore it

  if (xTrain.size() == 0 || yTrain.size() == 0)
    throw "Make sure that you have atleast one train example";
  if (xTrain.size() != yTrain.size())
    throw "Number of features and target must be equal";

  std::map<std::string, int> occurences;

  for (auto category : yTrain)
  {
    occurences[category]++;
  }
  for (auto current : occurences)
  {
    priors[current.first] = double(current.second) / yTrain.size();
  }

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


}

template<class T>
std::string predict(std::vector<T> xTest){
    std::map<std::string, double> probs;
    for (auto curr : priors)
    {
        probs[curr.first] = curr.second;
        for (auto feature : xTest)
        {
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