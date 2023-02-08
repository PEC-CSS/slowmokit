/**
 * @file methods/neighbors/bernoulli_nb/nernoulli_nb.cpp
 *
 * Implementation of the Bernoulli Naive Bayes main program
 */
#include "bernoulli_nb.hpp"

template<class T> double priorProb(std::vector<T> yTrain, int label)
{ // Prior-Probability P(y)
  int sum = 0;
  for (int i = 0; i < yTrain.size(); i++)
  {
    if (yTrain[i] == label)
    {
      sum += 1;
    }
  }
  return sum / double(yTrain.size());
}

template<class T>
double conditionalProb(std::vector<std::vector<T>> xTrain,
                       std::vector<T> yTrain, int featureCol, int featureVal,
                       int label)
{ // Conditional Probability
  // P(x=f1 / y=class)
  int denominator = 0, numerator = 0;
  for (int i = 0; i < yTrain.size(); i++)
  {
    if (yTrain[i] == label)
    {
      denominator++;
      if (xTrain[i][featureCol] == featureVal)
      {
        numerator++;
      }
    }
  }
  if (denominator != 0)
  {
    return numerator / double(denominator);
  }
  return numerator;
}

template<class T>
int fitPredict(std::vector<std::vector<T>> xTrain, std::vector<T> yTrain,
               std::vector<T> xTest)
{
  int nFeatures = xTrain[0].size();

  std::vector<double> postProbs;

  for (int label = 0; label < 2; label++)
  { // bernoulli Nb so labels will only be 0/1.
    double likelihood = 1.0;
    for (int i = 0; i < nFeatures; i++)
    {
      double cond = conditionalProb(xTrain, yTrain, i, xTest[i], label);
      int b;
      likelihood *=
          ((cond) *xTest[i] +
           (1 - cond) * (1 - xTest[i])); // P(x=f1 / y=class)*(x[i]) +
                                         // (1-P(x=f1 / y=class))*(1-x[i])
    }

    double prior = priorProb(yTrain, label);
    double post = prior * likelihood;
    postProbs.push_back(post);
  }
  double sumpropProbs = 0.0;
  int max = 0;
  for (int i = 0; i < postProbs.size(); i++)
  {
    sumpropProbs += postProbs[i];
  }
  for (int i = 0; i < postProbs.size(); i++)
  {
    postProbs[i] /= sumpropProbs;
    if (postProbs[i] > postProbs[max])
    {
      max = i;
    }
  }
  return max;
};
