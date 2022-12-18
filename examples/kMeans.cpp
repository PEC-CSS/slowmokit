#include "./../src/slowmokit/methods/cluster/kMeans/kMeans.hpp"

int main()
{
    std::vector<std::vector<int>> X {
        {0, 0},
        {1, 1},
        {-1, -1},
        {1, 0},
        {0, 1},

        {5, 5},
        {6, 6},
        {4, 4},
        {5, 6},
        {6, 5}
    };

    int k = 2;

    auto kmeans = kMeans<int>(k);
    kmeans.fit(X);

    for (auto x : kmeans.labels())
        std::cout << x << " ";
    std::cout << std::endl;

    auto centroid = kmeans.getCentroid();
    int pos = 1;
    int y = 1;
}