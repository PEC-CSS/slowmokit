# Label Encoder

Encode target labels with value between 0 and n_classes-1.

This transformer should be used to encode target values, i.e. y, and not the input X.

## Parameters

| Name         | Definition                                 | Type   |
|--------------|--------------------------------------------|--------|
| targetVector | The target labels which need to be encoded | Vector |


## Example

```
std::vector<std::string> data = {"luffy","zoro","sanji","luffy","law","zoro"};
std::vector<int> labelEncodedData = labelEncoder(data); //  labelEncodedData contains the encoded values
```