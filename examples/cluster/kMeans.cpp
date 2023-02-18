#include "../../src/slowmokit/methods/cluster/kMeans.hpp"
#include <bits/stdc++.h>

int main()
{
    // Points in 2-D plane.
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

    // Number of cluster to be formed
    int k = 3;

    // Initiate a kMeans object of type int
    auto kmeans = kMeans<int>(k, 20);

    // Other initialisation
    // auto kmeans = kMeans<int>(int k); // epoch = 40
    // auto kmeans = kMeans(int k, std::vector<std::vector<long double>> initial_centroids, int epoch);
    
    // Form clusters. `fit` function expects only one argument a 2D vector which is used to form cluster. 
    kmeans.fit(X);
    auto labels = kmeans.labels();

    // Instead of above two lines one could also use prdict function to get cluster labels directly
    // auto labels = kmeans.predict(X)

    // Print which cluster each point belongs to
    for (int i = 0; i < std::ssize(labels); i++)
    {
        std::cout << "(" << X[i][0] << ", " << X[i][1] << "): cluster-" << labels[i];
        std::cout << std::endl; 
    }

    std::cout << std::endl;

    // get Final centroids coordinate
    auto centroid = kmeans.getCentroid();
    int pos = 0;

    std::cout << std::endl;
    std::cout << "Centroids: " << std::endl;

    for (auto &p : centroid)
        std::cout << "centroid-" << (pos++) << ": (" << p[0] << ", " << p[1] << ")\n";
}
