#include "./../src/slowmokit/methods/cluster/kMeans.cpp"

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
        {6, 5},

        {-4, -4},
        {-3, -3},
        {-4, -3},
        {-3, -4}
    };

    int k = 3;

    auto kmeans = kMeans<int>(k, 20);
    kmeans.fit(X);

    auto labels = kmeans.labels();
    for (int i = 0; i < std::ssize(labels); i++)
    {
        std::cout << "(" << X[i][0] << ", " << X[i][1] << "): cluster-" << labels[i];
        std::cout << std::endl; 
    }

    std::cout << std::endl;

    auto centroid = kmeans.getCentroid();
    int pos = 1;

    std::cout << std::endl;
    std::cout << "Centroids: " << std::endl;

    for (auto &p : centroid)
        std::cout << "centroid-" << pos << ": (" << p[0] << ", " << p[1] << ")\n";
}