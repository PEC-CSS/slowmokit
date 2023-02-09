# Label Encoder

Encodes the target labels into numeric form, ranging between 0 and the number of unique labels in the target vector.

This transformer should be used to encode target values, i.e. y, and not the input X.

## Parameters

| Name         | Definition                                 | Type         |
|--------------|--------------------------------------------|--------------|
| targetVector | The target labels which need to be encoded | `vector<int>` |


## Methods

| Name                                   | Definition                                    | Return value  |
|----------------------------------------|-----------------------------------------------|---------------|
| `labelEncoder(vector<T> targetVector)` | To encode the target labels into numeric form | `vector<int>` |

## Example

```
std::vector<std::string> data = {"luffy","zoro","sanji","luffy","law","zoro"};
std::vector<int> labelEncodedData = labelEncoder(data); //  labelEncodedData contains the encoded values
```