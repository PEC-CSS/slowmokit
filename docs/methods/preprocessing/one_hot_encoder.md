# One Hot Encoder

One hot encoding is a technique to represent categorical variables as numerical values.Each unique value of a categorical variable is assigned a binary code, where a "1" in the code represents the presence of that value and a "0" represents its absence.

One hot encoding makes our training data more useful and expressive, and it can be rescaled easily.


## Parameters

| Name         | Definition                                 | Type         |
|--------------|--------------------------------------------|--------------|
|   data       | The data that has to be encoded is passed as the data parameter in the oneHotEncoder function. | `vector<string>` |
|   nClasses      | This parameter is an integer that specifies the number of classes or categories in the input data. | `int` |

## Methods

| Name                                   | Definition                                    | Return value  |
|----------------------------------------|-----------------------------------------------|---------------|
| `oneHotEncoder(vector<T> data, nClasses)` | To encode the data into numerical values. | `vector<vector<int>>` |

## Example

```cpp
int main() {
 std::vector<std::string> data = {"apples", "banana", "mango", "pear", "mango","apples","pear"};
 int nClasses = 4;
  std::vector<std::vector<int>> oneHotEncodedData = oneHotEncoder(data, nClasses);
  for (const auto &row : oneHotEncodedData) {
    for (const auto &column : row) {
      std::cout << column << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
```