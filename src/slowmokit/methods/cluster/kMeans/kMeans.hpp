/**
 * @file methods/cluster/kMeans/kMeans.hpp
 *
 * The header file including the kMeans
 */
#ifndef SLOWMOKIT_KMEANS_HPP
#define SLOWMOKIT_KMEANS_HPP

#include "../../../base.hpp"

template <typename T>
class kMeans
{
    const int k;
    const int epoch;
    std::vector<int> clusters;
    std::vector<std::vector<long double>> centroids;

    /**
      Returns random number between l and r, both inclusive
      @param l: start of range
      @param r: end of range
      @throws assertionError if r > l.
      */
    template <typename G>
    G randomInteger(G l, G r)
    {
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
        assert(l <= r);

        return std::uniform_int_distribution<G>(l, r)(rng);
    }

    /**
      Returns set of k-distinct values
      @param k number of distinct values needed
      @param L start of range
      @param R end of range
     */
    template <typename G>
    std::set<G> getKDistinctIndices(int k, int L, int R)
    {
        if (k < 0)
        {
            throw "k < 0 not allowed!";
        }

        if (R - L + 1 < k)
        {
            throw "Range should be of length atleast k";
        }

        std::set<G> nums;
        while (std::ssize(nums) != k) 
        {
            nums.emplace(randomInteger(L, R));
        }

        return nums;
    }

    template <typename G1 = int, typename G2 = double>
    G2 sqroot(G1 x, double eps = 1e-9)
    {
        G2 left = 0, right = x;

        while (right - left > eps)
        {
            G2 mid = left + (right - left) / 2;

            if (mid >= x / mid)
                right = mid;
            else
                left = mid;
        }

        return left + (right - left) / 2;
    }

    long double euclidean_distance(long double x1, long double y1, long double x2, long double y2)
    {
        return sqroot((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
public:
    kMeans(int k, int epoch) : k(k), epoch(epoch)
    {
        if (k <= 0)
        {
            throw "k should be a positive integer.";
        }
    }

    kMeans(int k) : kMeans(k, 40) {}

    kMeans(int k, std::vector<std::vector<long double>> initial_centroids, int epoch) : kMeans(k, 40) 
    {
        this->centroid = initial_centroids;
    }

    void fit(std::vector<std::vector<T>> X, std::vector<T> Y = {})
    {
        int n = std::size(X);
        if (std::ssize(centroids) != k)
        {
            auto id = getKDistinctIndices<int>(k, 0, n - 1);
            assert(std::ssize(id) == k);
            centroids.clear();
            for (auto i : id)
                centroids.push_back({1.0 * X[i][0], 1.0 * X[i][1]});
        }

        clusters.resize(n, -1);
        bool changed = true;
        for (int __ = 0; __ < epoch and changed; __++)
        {
            int pos = 0;
            changed = false;

            // cluster assignment
            for (auto p : X)
            {
                int cluster_num = 0;
                for (int i = 1; i < k; i++)
                {
                    if (euclidean_distance(centroids[i][0], centroids[i][1], p[0], p[1])
                            < euclidean_distance(centroids[cluster_num][0], centroids[cluster_num][1], p[0], p[1]))
                    {
                        cluster_num = i;
                    }
                }

                assert(pos < std::size(clusters));

                if (clusters[pos] != cluster_num)
                    changed = true;

                clusters[pos++] = cluster_num;
            }

            // move centroids
            for (auto &centroid : centroids)
                centroid[0] = centroid[1] = 0;

            std::vector<int> count(k);
           
            for (int i = 0; i < n; i++)
            {
                centroids[clusters[i]][0] += X[i][0];
                centroids[clusters[i]][1] += X[i][1];
                count[clusters[i]]++;
            }

            for (int i = 0; i < k; i++)
            {
                if (count[i] != 0)
                {
                    centroids[i][0] = centroids[i][0] / count[i];
                    centroids[i][1] = centroids[i][1] / count[i];
                }
            }
        }
    }

    std::vector<int> predict(std::vector<std::vector<T>> X)
    {
        fit(X);
        return clusters;
    }

    std::vector<int> labels()
    {
        return clusters;
    }

    std::vector<std::vector<long double>> getCentroid()
    {
        return centroids;
    }
};

#endif //SLOWMOKIT_KMEANS_HPP
