# Distance Metric

## Euclidean Distance
Euclidean Distance represents the shortest distance between two points.

## Manhattan Distance
Manhattan Distance is the sum of absolute differences between points across all the dimensions.

## Manhattan Distance
Minkowski Distance is the generalized form of Euclidean and Manhattan Distance.

## Cosine Similarity
Cosine similarity is a metric, helpful in determining, how similar the data objects are irrespective of their size.

## Parameters

| Name             | Definition                                                                              | Type |
| -----------------| --------------------------------------------------------------------------------------- | ---- |
| x                | A vector of values                                                                      |   `T`|
| y                | A vector of values                                                                      |   `T`|


## Methods

| Name                            | Definition                                            | Return value      |
| ------------------------------- | ----------------------------------------------------- | ----------------- |
| `euclidean()`                   | To find the euclidean distance                         | `double`         |
| `manhattan()`                   | To find the manhattan distance                         | `int, double`   |
| `minkowski(int p)`              | To find the minkowski distance                         | `double`         |
| `magnitude(vector<T> &x)`       | To find the magnitude of the vector                    | `double`         |
| `cosineSimilarity()`            | To find the cosine similarity                          | `double`         |



## Example

```cpp
std::vector<double> dist1 = {1, 4, 4, 4};
std::vector<double> dist2 = {1, 2, 3, 4};
DistanceMetric Dist(dist1, dist2);
std::cout << "Minkowski Distance is " << Dist.minkowski(3) << std::endl;
std::cout << "Euclidean Distance is " << Dist.euclidean() << std::endl;
std::cout << "Manhattan Distance is " << Dist.manhattan() << std::endl;
std::cout << "Cosine Similarity is  " << Dist.cosineSimilarity() << std::endl;
```


