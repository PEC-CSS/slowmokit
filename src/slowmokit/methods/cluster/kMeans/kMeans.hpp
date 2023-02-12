/**
 * @file methods/cluster/kMeans/kMeans.hpp
 *
 * The header file including the kMeans
 */

#ifndef SLOWMOKIT_KMEANS_HPP
#define SLOWMOKIT_KMEANS_HPP

#include "../../../core.hpp"

template<class T>
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
	template<class G>
	G randomInteger(G l, G r)
	{
		std::mt19937 rng(
		    std::chrono::steady_clock::now().time_since_epoch().count());
		assert(l <= r);

		return std::uniform_int_distribution<G>(l, r)(rng);
	}

	/**
	 * Returns set of k-distinct values
	 * @param k number of distinct values needed
	 * @param L start of range
	 * @param R end of range
	 */
	template<class G>
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

	template<class G1 = int, class G2 = double>
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

	long double euclideanDistance(long double x1, long double y1,
	                              long double x2, long double y2)
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

	kMeans(int k) : kMeans(k, 40)
	{
	}

	kMeans(int k, std::vector<std::vector<long double>> initial_centroids,
	       int epoch)
	    : kMeans(k, 40)
	{
		this->centroids = initial_centroids;
	}

	void fit(std::vector<std::vector<T>>);

	std::vector<int> predict(std::vector<std::vector<T>>);

	/**
	 * Returns which cluster point-i belongs to
	 */
	std::vector<int> labels() const;

	/**
	 * Returns the final centroid for each cluster.
	 */
	std::vector<std::vector<long double>> getCentroid() const;
};

#endif // SLOWMOKIT_KMEANS_HPP
