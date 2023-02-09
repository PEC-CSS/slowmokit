# Silhoutte Score

The Silhoutte score is calculated as the average of all points si, where si is the difference of minimum of inter cluster distance to average of intra cluster distance divided by maximum of both.
The silhoutte score reflects how good the value of k is, where k is the number of clusters.

## Parameters

| Name          | Definition                                                                                  | Type            |
| ------------- | ------------------------------------------------------------------------------------------- | ----------------|
| numClusters   | Takes a number of clusters                                                                  | `int`           |
| typeDist      | You require euclidean/manhattan distance to compute silhoutte score                         | `string`        |


## Methods

| Name                                           | Definition                                            | Return value      |
| -----------------------------------------------| ----------------------------------------------------- | ----------------- |
| `SilhoutteScore(vector<vector<T>>x,vector<int> y,int numClusters,string typeDist)`|To find the silhoutte score|  `double`  |

## Example

```cpp

std::vector<std::vector<double>> x{{1,2,3},{1.21,2.32,3.24},{5.56,5.45,5.23},{5.35,5.00,5.78}};
std::vector<int> y{0,0,1,1};
int numClusters=2;
std::string s = "euclidean";
double score = SilhoutteScore(x,y,numClusters,s);
std::cout<<score<<std::endl;

```