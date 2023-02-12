/**
 * @file methods/neighbors/knn/knn.cpp
 *
 * Implementation of the KNN main program
 */
#include "knn.hpp"

template<class T>
double KNN<T>::distance(std::vector<T> x1, std::vector<T> x2)
{
	double dist = 0;
	for (int i = 0; i < x1.size(); i++)
	{
		if (distType == "euclidean")
		{
			dist += (x1[i] - x2[i]) * (x1[i] - x2[i]);
		}
		else if (distType == "manhattan")
		{
			dist += abs(x1[i] - x2[i]);
		}
	}
	if (distType == "euclidean")
	{
		return pow(dist, 0.5);
	}
	else
	{
		return dist;
	}
}

template<class T>
void KNN<T>::fit(std::vector<std::vector<T>> x, std::vector<int> y,
                 int classNums)
{
	this->xTrain = x;
	this->yTrain = y;
	this->classNums = classNums;
}

template<class T>
int KNN<T>::predict(std::vector<T> test, int k, std::string distType)
{
	this->distType = distType;
	std::priority_queue<std::vector<double>>
	    pq; // Here we are inserting pair of {distance, class number} in pq
	for (int i = 0; i < xTrain.size(); i++)
	{
		double dist = distance(xTrain[i], test);
		if (pq.size() < k)
		{
			std::vector<double> temp(2);
			temp[0] = dist;
			temp[1] = double(yTrain[i]);
			pq.push(temp);
		}
		else if (pq.top()[0] > dist)
		{
			pq.pop();
			std::vector<double> temp(2);
			temp[0] = dist;
			temp[1] = double(yTrain[i]);
			pq.push(temp);
		}
	}
	std::vector<int> calculatetimes(classNums,
	                                0); // number of points in particular class
	for (int i = 0; i < pq.size(); i++)
	{
		calculatetimes[int(pq.top()[1])] += 1;
		pq.pop();
	}
	int max = 0;
	for (int i = 0; i < classNums; i++)
	{
		if (calculatetimes[i] > calculatetimes[max])
		{
			max = i;
		}
	}
	return max;
}
