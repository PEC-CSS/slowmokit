#include <bits/stdc++.h>
#include "../../slowmokit/linear_models/linearRegression.h"
using namespace std;

int main()
{
    LinearRegression<double> model;

    vector<vector<double>> x = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    vector<double> y = {2, 3, 4, 5, 6};

    model.fit(x, y);

    model.printCoefficients();

    vector<double> yPred = model.predict(x);
    for (int i = 0; i < y.size(); i++)
        cout << "Actual value: " << y[i] << ", Predicted value: " << yPred[i] << endl;

    return 0;
}