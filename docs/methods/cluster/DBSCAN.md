# DBSCAN

DBSCAN stands for **D**ensity **B**ased **S**patial **C**lustering of **A**pplications with **N**oise

The model clusters the given training set based on density of the given data points i.e. a point belongs to a cluster based on how close it is to its neighbouring points. This model is capable of finding arbitrary shaped clusters and identifying outliers.

## Parameters

| Name        | Definition                                                                                  | Defaults | Type          |
|-------------| ------------------------------------------------------------------------------------------- |----------|---------------|
| `eps`       | Measure of how close a point should be to be considered in the vicinity of another point  | 0.5      | `long double` |
| `minSamples` | Minimum number of points that should lie in the vicinity of a point for it to be considered a core point       | 5        | `int`         |

## Attributes

| Name   | Definition                                                                         | Shape                             |
|--------|------------------------------------------------------------------------------------|-----------------------------------|
| `labels` | Labels assigned to each data point of the training set fitted into the model | No of data points in training set |

## Methods

| Name                                 | Definition                             | Return value  |
|--------------------------------------|----------------------------------------|---------------|
| `fit(std::vector<std::vector<T>> x)` | Fits and clusters the given training set                                       | `void`        |
| `fitPredict(vector<T> x)`            | Fits and clusters the given training set and returns the labels assigned to each data point         | `vector<int>` |
| `getLabels()`                        | Returns the labels assigned to each data point of the training set fitted into the model | `vector<int>` |

## Example

```cpp
DBSCAN<double> db(0.6, 4);
std::vector<std::vector<double>> x = {
            {1, 2},
            {3, 4},
            {2.5, 4},
            {1.5, 2.5},
            {3, 5},
            {2.8, 4.5},
            {2.5, 4.5},
            {1.2, 2.5},
            {1, 3},
            {1, 5},
            {1, 2.5},
            {5, 6},
            {4, 3}
};
std::vector<int> labels = db.fitPredict(x);
std::cout << "X  Y  Cluster\n";
for(int i = 0; i < x.size(); i++) {
    std::cout << x[i][0] << "  " << x[i][1] << "  " << labels[i] << "\n";
}
```
