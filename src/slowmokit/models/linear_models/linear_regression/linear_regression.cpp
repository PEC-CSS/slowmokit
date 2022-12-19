#include "linear_regression.hpp"
using namespace std;

template <class T>
void LinearRegression<T>::fit(vector<vector<T>> x, vector<T> y)
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

    for (int epoch = 0; epoch < epochs; epoch++)
    {
        vector<T> y_pred;
        for (int example = 0; example < trainExampleSize; example++)
        {
            T currentY = coefficients[0];
            for (int feature = 0; feature < featureSize; feature++)
                currentY += coefficients[feature + 1] * x[example][feature];
            y_pred.push_back(currentY);
        }
        for (int example = 0; example < trainExampleSize; example++)
            coefficients[0] -= learningRate * (y_pred[example] - y[example]) / trainExampleSize;
        for (int feature = 0; feature < featureSize; feature++)
        {
            for (int example = 0; example < trainExampleSize; example++)
                coefficients[feature + 1] -= learningRate * (y_pred[example] - y[example]) * x[example][feature] / trainExampleSize;
        }
    }
}

template <class T>
vector<T> LinearRegression<T>::predict(vector<vector<T>> x)
{
    vector<T> y_pred;
    int trainExampleSize = x.size(), featureSize = x[0].size();
    for (int example = 0; example < trainExampleSize; example++)
    {
        T currentY = coefficients[0];
        for (int feature = 0; feature < featureSize; feature++)
            currentY += coefficients[feature + 1] * x[example][feature];
        y_pred.push_back(currentY);
    }
    return y_pred;
}

template <class T>
void LinearRegression<T>::printCoefficients()
{
    for (int i = 0; i < coefficients.size(); i++)
        cout << "Θ" << i << ": " << coefficients[i] << endl;
}