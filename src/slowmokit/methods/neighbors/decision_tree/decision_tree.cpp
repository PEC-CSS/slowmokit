/**
 * @file methods/neighbors/decision_tree/decision_tree.cpp
 *
 * Implementation of the Decsion Tree main program
 */

#include "decision_tree.hpp"

template<class T> double DecisionTree<T>::entropy(std::vector<double> col)
{ // computes the entropy of the data                          entropy = Sum(-
  // p*(log2(p)) ) ; p = prob of each output class
  std::set<double> unique;
  for (int i = 0; i < col.size(); i++)
  {
    unique.insert(col[i]); // computing the unique classes in output
  }
  double ent = 0.0;
  std::set<double>::iterator it;
  for (it = unique.begin(); it != unique.end(); it++)
  {
    // cout<<*it<<endl;
    double p =
        *it / double(col.size()); // for each unique class computing probabilty
    if (p == 0)
    {
      ent += 0.0;
    }
    else // Now adding the entropy of that particular class
    {
      ent += (-1) * p * log2(p);
    }
  }
  return ent;
}

template<class T>
std::vector<std::vector<std::vector<double>>> DecisionTree<T>::divideData(
    std::vector<std::vector<double>> xData, int fkey,
    int fval) // Divide the data on the basis of column(fkey) provided and
              // value(fval) provided.
{
  std::vector<std::vector<double>> xLeft;  // Left data
  std::vector<std::vector<double>> xRight; // Right data
  for (int i = 0; i < xData.size(); i++)
  { // Noq in this loop we divide the data according tofval,fkey
    double val = xData[i][fkey];
    std::vector<double> temp = xData[i];
    if (val > fval) // Compring fval with value of that column data
    {
      xRight.push_back(temp);
    }
    else
    {
      xLeft.push_back(temp);
    }
  }
  std::vector<std::vector<std::vector<double>>> output {xLeft, xRight};
  return output;
}

template<class T>
double DecisionTree<T>::infoGain(std::vector<std::vector<double>> xData,
                                 int fkey, int fval)
{ // fkey refers to the feature/column index; fval refers to the mean
  // value/splitting value
  // Splitting data
  std::vector<std::vector<double>> left, right;
  std::vector<std::vector<std::vector<double>>> temp =
      divideData(xData, fkey, fval); // first dividing data on the basis of
                                     // considered splitting column and value
  left = temp[0];
  right = temp[1];
  double l = left.size() / double(xData.size());
  double r = right.size() / double(xData.size());
  if (left.size() == 0 or
      right.size() == 0) // Checks left and right nodes should not be empty
  {
    return -1;
  }
  std::vector<double> y_data, lY, rY; // y_data = all y values  ; lY = left node
                                      // y values ; rY=right node y values
  int y = xData[0].size() - 1;
  for (int i = 0; i < xData.size(); i++)
  {
    y_data.push_back(xData[i][y]);
  }
  for (int i = 0; i < left.size(); i++)
  {
    lY.push_back(xData[i][y]);
  }
  for (int i = 0; i < right.size(); i++)
  {
    rY.push_back(xData[i][y]);
  }
  double iGain = entropy(y_data) -
                 (l * entropy(lY) + r * entropy(rY)); // computing infoGain
  return iGain;
}

template<class T>
DecisionTree<T>::DecisionTree(int maxD, int minSamplesL, int maxF)
{
  this->maxDepth = maxD;
  this->minSamplesLeaf = minSamplesL;
  this->maxFeatures = maxF; // maxFeatures is the number of features to be
                            // considered to do splitting at each node
}

template<class T>
void DecisionTree<T>::train(
    std::vector<std::vector<double>> xData) // training of model
{
  int max = xData[0].size() - 2;
  int range = max + 1;

  features.clear(); // clearing features set to select features to be considered

  while (features.size() != maxFeatures)
  {
    features.insert(rand() % range); // Inserting features/columns
  }

  std::vector<double> infoGains(
      maxFeatures); // vector for information gain of each column
  std::vector<double> mean(maxFeatures); // mean of each feature
  int cnt = 0;
  for (int i = 0; i < xData[0].size() - 1; i++)
  {
    if (i == *features.cbegin())
    {
      features.erase(i);
      for (int j = 0; j < xData.size(); j++)
      {
        mean[cnt] += xData[j][i];
      }
      double iGain = infoGain(xData, i, mean[cnt] / double(xData.size()));
      infoGains[cnt] = iGain;
      cnt++;
    }
  }
  max = 0;
  for (int i = 0; i < maxFeatures; i++)
  {
    if (infoGains[i] >
        infoGains[max]) // Comparison of info gains of each column. Column
    {
      max = i;
    }
  }
  fkey = max;
  fval = mean[max] / double(xData.size());

  // Split data
  std::vector<std::vector<std::vector<double>>> temp = divideData(
      xData, fkey,
      fval); // dividing data on the basis of computed best information gain
  std::vector<std::vector<double>> dataLeft = temp[0];
  std::vector<std::vector<double>> dataRight = temp[1];

  if (dataLeft.size() <= minSamplesLeaf or
      dataRight.size() <=
          minSamplesLeaf) // Checking conditions like data in each node should
                          // be greater than minSamples leaf
  {
    double mean = 0.0;
    int y = xData[0].size() - 1;
    for (int i = 0; i < xData.size(); i++)
    {
      mean += xData[i][y];
    }
    if (mean / double(xData.size()) >=
        0.5) // checking mean value of all y's, if mean>=0.5 then ouput
             // predicted will be 1
    {
      target = 1;
    }
    else // else if mean<0.5 output will be 0th class
    {
      target = 0;
    }
    return;
  }
  if (depth >= maxDepth) // Second condition we check is for depth. If current
                         // depth is greater than maximum Depth then it will not
                         // form further branches
  {
    double mean = 0.0;
    int y = xData[0].size() - 1;
    for (int i = 0; i < xData.size(); i++)
    {
      mean += xData[i][y];
    }
    if (mean / double(xData.size()) >=
        0.5) // Same as above if mean value of y's >=0.5 predicted output class
             // 1
    {
      target = 1;
    }
    else // Predicted output class 0
    {
      target = 0;
    }
    return;
  }

  left = new DecisionTree(maxDepth, minSamplesLeaf, maxFeatures); // left node
  left->depth = depth + 1;
  left->train(dataLeft);
  right = new DecisionTree(maxDepth, minSamplesLeaf, maxFeatures); // right node
  right->depth = depth + 1;
  right->train(dataRight);

  double mea = 0.0;
  int y = xData[0].size() - 1;
  for (int i = 0; i < xData.size(); i++)
  {
    mea += xData[i][y];
  }
  if ((mea / double(xData.size())) >= 0.5) // Setting ouput class at leaf node.
  {
    target = 1;
  }
  else
  {
    target = 0;
  }
  return;
}

template<class T>
int DecisionTree<T>::predict(
    std::vector<double> test) // predicting ouput class for testing value
{
  if (test[fkey] > fval) // comparing fval to value of testing data column(fkey)
  {
    if (right == NULL)
    {
      return target;
    }
    return right->predict(test);
  }
  else
  {
    if (left == NULL)
    {
      return target;
    }
    return left->predict(test);
  }
}