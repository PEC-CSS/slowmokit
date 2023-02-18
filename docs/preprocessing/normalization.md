# Normalization

Normalization is a scaling technique in which values are shifted and rescaled so that they end up ranging between 0 and 1. It is also known as Min-Max scaling.

## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| values        | Values to be normalized                                                                     | `int,double`    |

## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `normalize(vector<T> x)`                       | To normalize the data                                 |    `void`         |

## Example

```cpp
     std::vector<double> values={1,2,3,4,5};
     normalize(values);
     for(auto i:values){
         std::cout << i << " ";
     }
     std::cout << std::endl;

```
