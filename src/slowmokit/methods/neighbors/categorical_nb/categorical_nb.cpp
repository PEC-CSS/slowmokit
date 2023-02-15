/**
 * @file methods/neighbors/gaussian_nb/categorical_nb.cpp
 *
 * Implementation of the Categorical Naive Bayes main program
 */

#include "categorical_nb.hpp"
template<class T>
void CategoricalNB<T>::fit(std::vector<std::vector<T>> xTrain,
                           std::vector<std::string> yTrain)
{
  // posterior = (prior * likelihood)/evidence
  // since, evidence is same among all instances -> we can ignore it

  if (xTrain.size() == 0 || yTrain.size() == 0)
  {
    throw "Make sure that you have atleast one train example";
  }
  if (xTrain.size() != yTrain.size())
  {
    throw "Number of instances and target values must be equal";
  }
  featureSize = xTrain[0].size();
  std::map<std::string, int>
      occurences; // to store the occurences of each label in the training set
                  // and then use it in finding the priors

  for (auto category : yTrain)
  {
    occurences[category]++; // incrementing the occurence of each label
  }
  for (auto current : occurences)
  {
    priors[current.first] =
        double(current.second) /
        yTrain.size(); // calculating the priors of each label, dividing the
                       // occurence by the size of the total set
  }

  std::map<std::string, std::map<std::pair<T, int>, int>>
      counts; // to store the count of each cell corresponding to it's label,
              // it's row and it's category

  for (int i = 0; i < (int) (xTrain.size());
       i++) // iterating over the training data grid
  {
    std::vector<T> current = xTrain[i]; // current row
    int j = 0; // to keep track of the current column for each cell
    for (auto curr : current) // iterating over current row
    {
      counts[yTrain[i]]
            [{curr, j}]++; // incrementing the value based on it's label , it's
                           // category and it's column(denoting it's feature)
      j++;
    }
  }
  for (auto current :
       counts) // iterating over the counts map , to calculate likelihoods
  {
    for (auto e :
         current.second) // iterating over the map corresponding to each label
                         // to find the likelihood of each entry
    {
      likelihoods[current.first][{e.first.first, e.first.second}] =
          ((double(e.second)) / (occurences[current.first]));
      // likelihood[label][current feature]=occ in current/total no of occ
    }
  }
}

template<class T>

std::string CategoricalNB<T>::predict(
    std::vector<T> xTest) // predicting the label on the basis of training set
{
  if (((int) (xTest.size())) != featureSize)
  {
    throw "The number of features in training and testing set must be same";
  }
  std::map<std::string, double> probs;
  for (auto curr : priors) // since, posterior = prior*likelihood , we will
                           // calculate the same for each label to give the
                           // label with highest probability as the output
  {
    probs[curr.first] = curr.second;
    int j = 0;
    for (auto feature : xTest)
    {
      probs[curr.first] *=
          likelihoods[curr.first][{feature, j}]; // calculating posterior for
                                                 // each feature in Testing data
      j++;
    }
  }
  double maxProb = 0;
  std::string out;
  for (auto prob : probs)
  {
    if (prob.second >
        maxProb) // finding the highest probability among all options
    {
      maxProb = prob.second;
      out = prob.first;
    }
  }
  for (auto e : probs)
  {
    std::cout << e.first << " " << e.second << std::endl;
  }
  return out;
}