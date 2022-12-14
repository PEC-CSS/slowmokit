#include <bits/stdc++.h>
#include "../models/model.h"
using namespace std;

template <typename T>
class LinearRegression : public Model<T>
{
private:
    vector<T> coefficients;
    int EPOCHS = 100;
    double LEARNING_RATE = 0.01;

public:
    LinearRegression() {}

    LinearRegression(int EPOCHS, double LEARNING_RATE)
    {
        this->EPOCHS = EPOCHS;
        this->LEARNING_RATE = LEARNING_RATE;
    }

    /*
    Takes features and target as value and trains model using those values
    @param x features
    @param y target variables
    @throws Invalid input exception
    */
    void
    fit(vector<vector<T>> x, vector<T> y)
    {
        if (x.size() == 0 || y.size() == 0)
            throw "Make sure that you have atleast one train example";
        if (x.size() != y.size())
            throw "Number of features and target must be equal";
        int trainExampleSize = x.size(), featureSize = x[0].size();
        if (featureSize == 0)
            throw "Feature size should be atleast 1";
        coefficients.clear();
        coefficients.resize(featureSize + 1);

        for (int epoch = 0; epoch < EPOCHS; epoch++)
        {
            vector<T> yPred;
            for (int example = 0; example < trainExampleSize; example++)
            {
                T currentY = coefficients[0];
                for (int feature = 0; feature < featureSize; feature++)
                    currentY += coefficients[feature + 1] * x[example][feature];
                yPred.push_back(currentY);
            }
            for (int example = 0; example < trainExampleSize; example++)
                coefficients[0] -= LEARNING_RATE * (yPred[example] - y[example]) / trainExampleSize;
            for (int feature = 0; feature < featureSize; feature++)
            {
                for (int example = 0; example < trainExampleSize; example++)
                    coefficients[feature + 1] -= LEARNING_RATE * (yPred[example] - y[example]) * x[example][feature] / trainExampleSize;
            }
        }
    }

    /*
    Takes features and predicts target values for trained weights
    @param x features
    @return yPred target variables
    */
    vector<T> predict(vector<vector<T>> x)
    {
        vector<T> yPred;
        int trainExampleSize = x.size(), featureSize = x[0].size();
        for (int example = 0; example < trainExampleSize; example++)
        {
            T currentY = coefficients[0];
            for (int feature = 0; feature < featureSize; feature++)
                currentY += coefficients[feature + 1] * x[example][feature];
            yPred.push_back(currentY);
        }
        return yPred;
    }

    /*
    Prints all the weights
    */
    void printCoefficients()
    {
        for (int i = 0; i < coefficients.size(); i++)
            cout << "Θ" << i << ": " << coefficients[i] << endl;
    }
};