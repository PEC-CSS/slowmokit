# Csv Reader

It reads the csv File provided and accordingly set the data type in that particular column double/string

After computing the data type whole file is converted to string vector with their data types in first row of vector. Those values can be then converted to data-type on the runtime whenever required.

## Parameters

| Name         | Definition                                 | Type         |
|--------------|--------------------------------------------|--------------|
| file | Csv file which needs to be read | `ifstream` |


## Methods

| Name                                   | Definition                                    | Return value  |
|----------------------------------------|-----------------------------------------------|---------------|
| `readCsv(string name,bool index)` | To read csv file and allocate which column is double or string | `vector<vector<string>>` |

## Example

```
std::vector<std::vector<std::string>>reader = readCsv("../../lol.csv",1);
```