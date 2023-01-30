/**
 * @file ducks/matrix/matrix.cpp
 *
 * Implementation of the matrix main program
 */

#include "matrix.hpp"

template <class T>
Matrix<T>::Matrix(int n, int m) : n(n), m(m)
{
    assert(n > 0 and m > 0 and "Matrix cannot have empty dimension");
    mat.resize(n, std::vector<T>(m, T(0)));
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> in)
{
    assert(std::size(in) > 0 and std::size(in[0]) > 0 and "Matrix cannot have empty dimension");
    n = std::size(in);
    m = std::size(in[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            assert(std::size(in[0]) == m and "All rows must have same dimension");
            this->mat[i][j] = T(in[i][j]);
        }
    }
}

template <class T>
Matrix<T> &Matrix<T>::operator *=(const T &scalar)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            mat[i][j] *= scalar;
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator *=(const Matrix<T> &rhs)
{
    assert(std::size(rhs) > 0 and std::size(rhs[0]) and "Cannot have empty dimension");

    int n2 = std::size(rhs), m2 = std::size(rhs[0]);

    assert(m == n2 and "column dimension of matrix-1 must be equal to row dimension of matrix-2.");

    std::vector res(n, std::vector<T>(m2, T(0)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m; k++)
                res[i][j] += mat[i][k] * mat[k][j];
        }
    }

    return res;
}

template <class T>
std::array<int, 2> Matrix<T>::getShape()
{
    return {this->n, this->m};
}

template <class T>
void Matrix<T>::print()
{
    auto [n, m] = getShape();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > 0)
                std::cout << " ";
            std::cout << this->mat[i][j];
        }

        if (i != n - 1)
            std::cout << "\n";
    }
}

int main()
{
    
}