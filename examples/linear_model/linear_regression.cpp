#include "../../src/slowmokit/methods/linear_model/linear_regression.hpp"
#include "../../src/slowmokit/core.hpp"

int main()
{
    LinearRegression<double> model;
    std::vector<vector<double>> x = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    std::vector<double> y = {2, 3, 4, 5, 6};

    model.fit(x, y);
    model.printCoefficients();

    std::vector<double> yPred = model.predict(x);
    for (int i = 0; i < y.size(); i++)
        cout << "Actual value: " << y[i] << ", Predicted value: " << yPred[i] << endl;

    return 0;
}
