#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Models
{
public:
    virtual void fit(vector<vector<T>> x, vector<T> y) = 0;

    virtual vector<T> predict(vector<vector<T>> x) = 0;
};