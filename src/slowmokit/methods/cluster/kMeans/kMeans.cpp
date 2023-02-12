/**
 * @file methods/cluster/kMeans/kMeans.cpp
 *
 * Implementation of the K-Means main program
 */
#include "kMeans.hpp"

template <class T>
void kMeans<T>::fit(std::vector<std::vector<T>> X)
{
	int n = std::size(X);
	if (std::ssize(centroids) != k)
	{
		auto id = getKDistinctIndices<int>(k, 0, n - 1);
		assert(std::ssize(id) == k);
		centroids.clear();
		for (auto i : id)
		{
			centroids.push_back({1.0 * X[i][0], 1.0 * X[i][1]});
		}
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
				if (euclideanDistance(centroids[i][0], centroids[i][1], p[0],
				                      p[1]) <
				    euclideanDistance(centroids[cluster_num][0],
				                      centroids[cluster_num][1], p[0], p[1]))
				{
					cluster_num = i;
				}
			}

			assert(pos < std::size(clusters));

			if (clusters[pos] != cluster_num)
			{
				changed = true;
			}

			clusters[pos++] = cluster_num;
		}

		// move centroids
		for (auto &centroid : centroids)
		{
			centroid[0] = centroid[1] = 0;
		}

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

template <class T>
std::vector<int> kMeans<T>::predict(std::vector<std::vector<T>> X)
{
	fit(X);
	return clusters;
}

template <class T>
std::vector<int> kMeans<T>::labels() const
{
	return clusters;
}

template <class T>
std::vector<std::vector<long double>> kMeans<T>::getCentroid() const
{
	return centroids;
}