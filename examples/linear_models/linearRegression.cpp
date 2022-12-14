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

    vector<double> y_pred = model.predict(x);
    for (int i = 0; i < y.size(); i++)
        cout << "Actural value: " << y[i] << ", Predicted value: " << y_pred[i] << endl;

    return 0;
}