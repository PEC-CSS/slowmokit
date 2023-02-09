/**
 * @file methods/linear_model/logistic_regression/logistic_regression.cpp
 *
 * Implementation of the Logistic Regression main program
 */

#include "logistic_regression.hpp"
#include "../../preprocessing/one_hot_encoder.hpp"

template<class T>
std::vector<double> LogisticRegression<T>::softmax(std::vector<T> x)
{ // Softmax function
  std::vector<double> exps(x.size());
  double sum = 0.0;
  for (int i = 0; i < x.size(); i++)
  { // Iterating over vector to compute sum of all exponential values in vector
    exps[i] = exp(x[i]);
    sum += exps[i];
  }
  for (int i = 0; i < x.size(); i++)
  { // Now computing actual values after applying softmax
    exps[i] /= double(sum);
  }
  return exps;
};

template<class T>
double LogisticRegression<T>::crossEntropy(std::vector<int> y,
                                           std::vector<T> qi)
{ // Gives gradient descent -(d(z)/d(theta))
  double l = 0.0;
  for (int i = 0; i < y.size(); i++)
  {
    l += (y[i] * log(qi[i]));
  }
  return -1 * l;
};

template<class T>
//
double LogisticRegression<T>::EvalL(std::vector<std::vector<T>> x,
                                    std::vector<std::vector<int>> y,
                                    std::vector<std::vector<T>> beta)
{ // Computing overall loss in single epoch
  // Inputs :-
  // x -> all training x values
  // y -> all training y values
  // beta -> weights computed in logRegSgd

  int n = x.size();           // number of x values
  double loss = 0.0;          // initializing loss with 0.0
  for (int i = 0; i < n; i++) // loop over each x value
  {
    std::vector<double> xiHat = x[i]; // particular x value
    std::vector<int> yi = y[i];       // particular y value
    std::vector<double> qi(beta.size(),
                           0.0); // qi is the loss for each class like in output
                                 // we have [0,1,2] so loss for each class
    for (int j = 0; j < beta.size(); j++)
    { // each class iteration
      for (int k = 0; k < xiHat.size(); k++)
      { // in one class each weight iteration
        // qi =   [ __ , __ , __ , __....]
        //          [ __ , __ , __ , __....]  * [ __,__ ,__ ,.....]
        //          [ __ , __ , __ , __....]        xiHat
        //          [ __ , __ , __ , __....]
        //              beta
        qi[j] += beta[j][k] * xiHat[k];
      }
    }
    qi = softmax(qi);             // qi = z[i] = x[i]*beta[i];
    loss += crossEntropy(yi, qi); // Computing loss using z[i](computed values)
                                  // and y[i](actual values)
  }
  return loss; // finally returning loss
};

template<class T>
// This function performs logistic regression stochastic gradient descent
std::vector<std::vector<double>>
LogisticRegression<T>::logRegSgd(std::vector<std::vector<double>> x,
                                 std::vector<std::vector<int>> y, double alpha,
                                 int numEpochs, bool verbose, int batchSize)
{                               // PERFORMS MULTICLASS LOGISTIC REGRESSION
  int n = x.size();             // Rows in training vector
  int d = x[0].size();          // Number of features
  int numClasses = y[0].size(); // Output classes
  std::vector<std::vector<double>> beta(
      numClasses,
      std::vector<double>(
          d)); // Initializing weights (output_classes * features)

  // Initialization of beta with random values between 0-1;
  std::random_device rd;
  std::uniform_real_distribution<double> unif(0, 1);
  std::default_random_engine re(rd());
  for (int i = 0; i < numClasses; i++)
  {
    for (int j = 0; j < d; j++)
    {
      beta[i][j] = unif(re);
    }
  }

  std::vector<double> lVals(numEpochs);
  for (int i = 0; i < numEpochs;
       i++) // loop running for number of epochs specified
  {
    double l = EvalL(x, y, beta); // computes the loss when beta is
    // [__,__,......]
    // [__,__,......]
    // [__,__,......]
    lVals.push_back(l);

    if (verbose) // decides whether to print epoch number and current loss
                 // computed by EvalL
    {
      std::cout << "Epoch: " << i << " "
                << "Loss: " << l << std::endl;
    }

    std::vector<int> prm(n); // Making vector of size 'n' so that we can
                             // randomly shuffle number from 0-(n-1) and choose
                             // values in random order to perform regression
    for (int j = 0; j < n; j++)
    {
      prm[j] = j;
    }

    std::random_shuffle(prm.begin(),
                        prm.end()); // random shuffling of prm vector

    int countCompleted = 0;

    std::vector<std::vector<double>> gradLi( // Initializing gradient descent
        numClasses, std::vector<double>(x[0].size(), 0.0));

    while (!prm.empty()) // till prm not becomes empty keep iterating over the
                         // while loop
    {
      if ((prm.size() + countCompleted) <
          batchSize) // if we left with x values less than batch size then we
                     // will break
      {
        break;
      }

      int frnt = prm.back(); // gives last value of vector "prm"
      std::vector<double> xiHat =
          x[frnt]; // now we take random value of x according to the frnt value
                   // obtained!
      std::vector<int> yi = y[frnt]; //   Gives y value corresponding to xiHat
      std::vector<double> zi(
          numClasses, 0.0); // Initialization of zi vector which contains the
                            // predicted value of xiHat(one hot encoded)
                            //   Formula for z[i] is written below

      // z[i] = weight[ouput class][j-th weight] * x[i-th row][j-th feature]

      for (int j = 0; j < numClasses; j++)
      { // Iterating over classes of output
        for (int k = 0; k < xiHat.size(); k++)
        { // Iterating over x[i]
          zi[j] += beta[j][k] *
                   xiHat[k]; // Here we are performing  |  z[i] = weight[ouput
                             // class][j-th weight] * x[i-th row][j-th feature]
        }
      }
      zi = softmax(zi); // Now we are computing here the softmax of all one hot
                        // encoded values obtained for particular xiHat

      for (int j = 0; j < numClasses; j++) // iterating over all classes
      {
        for (int k = 0; k < xiHat.size();
             k++) // iterating over all xiHat values
        {
          gradLi[j][k] +=
              (zi[j] - yi[j]) *
              xiHat[k]; // here we are computing gradient descent of batch
        }
      }

      countCompleted++; // updating countCompleted means we added loss of this
                        // many values

      if (countCompleted == batchSize)
      {
        for (int j = 0; j < numClasses; j++)
        {
          for (int k = 0; k < xiHat.size(); k++)
          {
            gradLi[j][k] /= batchSize;
            beta[j][k] -=
                alpha * gradLi[j][k]; // Changing value of beta
                                      // according to the computed batch loss
          }
        }
        countCompleted = 0;
        for (int j = 0; j < numClasses; j++)
        {
          for (int k = 0; k < x[0].size(); k++)
          {
            gradLi[j][k] = 0.0; // again set value of loss to 0.0
          }
        }
      }

      prm.pop_back(); // deleting prm last value to take next random value for
                      // xiHat
    }
  }
  return beta; // finally return weights computed after all the epochs
};

template<class T>
// training function
// x -> training 2-d vector double values
// y - > training 1-d int values
// alpha -> double which is going to be multiply with gradient descent
// numEpochs -> number of epochs
// verbose -> whether to show which epoch is going on
void LogisticRegression<T>::fit(std::vector<std::vector<T>> x,
                                std::vector<int> y, double alpha, int numEpochs,
                                bool verbose, int batchSize)
{
  this->batchSize = batchSize;
  std::set<int> uniqueYValues;
  for (int i = 0; i < y.size(); i++)
  {
    uniqueYValues.insert(y[i]);
  }

  std::vector<std::vector<int>> oneHotEncodedY;
  oneHotEncodedY = oneHotEncoder(y, uniqueYValues.size());

  this->beta =
      logRegSgd(x, oneHotEncodedY, alpha, numEpochs, verbose, batchSize);
};

template<class T>
std::vector<double> LogisticRegression<T>::predict(std::vector<T> x)
{ // Predict probabilities of each class
  std::vector<double> probs(beta.size(), 0.0);
  // probs =  [ __ , __ , __ , __....]
  //          [ __ , __ , __ , __....]   * [ __ , __ ,__ ,....]
  //          [ __ , __ , __ , __....]        x(testing value)
  //          [ __ , __ , __ , __....]
  //              beta
  for (int i = 0; i < beta.size(); i++)
  {
    for (int j = 0; j < x.size(); j++)
    {
      probs[i] += beta[i][j] * x[j];
    }
  }
  probs = softmax(probs);
  return probs;
};