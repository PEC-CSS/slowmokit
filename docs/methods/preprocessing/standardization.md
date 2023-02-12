# Standardization

Standardization is another scaling technique where the values are centered around the mean with a unit standard deviation. This means that the mean of the attribute becomes zero and the resultant distribution has a unit standard deviation.


## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| values        | Values to be standardized                                                                   | `int,double`    |

## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `standardize(vector<T> x)`                     | To standardize the data                               |    `void`       |

## Example

```cpp
     std::vector<double> values={1,2,3,4,5};
     standardize(values);
     for(auto i:values){
         std::cout << i << " ";
     }
     std::cout << std::endl;

```
