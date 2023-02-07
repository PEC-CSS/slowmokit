/**
 * @file ducks/matrix/matrix.cpp
 *
 * Implementation of the matrix main program
 */

#include "matrix.hpp"

template <class T>
Matrix<T>::Matrix(int n, int m) : n(n), m(m)
{
    if (n <= 0 or m <= 0)
        throw std::out_of_range("\nCannot have non-positive dimension.");

    mat.resize(n, std::vector<T>(m, T(0)));
}

template <class T>
Matrix<T>::Matrix(const std::vector<std::vector<T>> in)
{
    if (std::size(in) <= 0 or std::size(in[0]) <= 0)
        throw std::out_of_range("\nCannot have non-positive dimension.");

    n = std::size(in);
    m = std::size(in[0]);
    mat.resize(n, std::vector<T>(m));

    for (int i = 0; i < n; i++)
    {
        if (std::size(in[i]) != m)
            throw std::invalid_argument("\nAll rows must have same dimension");

        for (int j = 0; j < m; j++)
            this->mat[i][j] = in[i][j];
    }
}

template <class T>
template <class G>
Matrix<T> &Matrix<T>::operator*=(const G &scalar)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            mat[i][j] *= scalar;
    }

    return *this;
}

template <class T>
template <class G>
Matrix<T> &Matrix<T>::operator+=(const G &scalar)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            mat[i][j] += scalar;
    }

    return *this;
}

template <class T>
template <class G>
Matrix<T> &Matrix<T>::operator-=(const G &scalar)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            mat[i][j] -= scalar;
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &rhs)
{
    auto [n2, m2] = rhs.getShape();

    if (n2 <= 0 or m2 <= 0)
        throw std::out_of_range("\nCannot have non-positive dimension.");

    if (m != n2)
        throw std::invalid_argument("\nColumn dimension of matrix-1 must be equal to row dimension of matrix-2");

    auto lhs = this->mat;
    std::vector res(n, std::vector<T>(m2, T(0)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m2; j++)
        {
            for (int k = 0; k < m; k++)
                res[i][j] += lhs[i][k] * rhs[k][j];
        }
    }

    this->mat = res;
    updateShape();

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    auto [n2, m2] = rhs.getShape();

    if (n2 <= 0 or m2 <= 0)
        throw std::out_of_range("\nCannot have non-positive dimension.");

    if (n != n2 or m != m2)
        throw std::invalid_argument("\nBoth Dimension of matrix-1 must be equal to that of matrix-2");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            this->mat[i][j] += rhs[i][j];
    }

    return *this;
}

template <class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{
    auto [n2, m2] = rhs.getShape();

    if (n2 <= 0 or m2 <= 0)
        throw std::out_of_range("\nCannot have non-positive dimension.");

    if (n != n2 or m != m2)
        throw std::invalid_argument("\nBoth Dimension of matrix-1 must be equal to that of matrix-2");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            this->mat[i][j] -= rhs[i][j];
    }

    return *this;
}

template <class T>
std::array<int, 2> Matrix<T>::getShape() const
{
    return {this->n, this->m};
}

template <class T>
T &Matrix<T>::operator()(int i, int j)
{
    if (i >= n or i < 0)
        throw std::out_of_range("\ni should be between 0 and " + std::to_string(n - 1) + " inclusive");
    if (j >= m or j < 0)
        throw std::out_of_range("\nj should be between 0 and " + std::to_string(m - 1) + " inclusive");

    return mat[i][j];
}

template <class T>
const std::vector<T> &Matrix<T>::operator[](int i) const
{
    if (i >= n or i < 0)
        throw std::out_of_range("\ni should be between 0 and " + std::to_string(n - 1) + " inclusive");

    return this->mat[i];
}

template <class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix)
{
    auto [n, m] = matrix.getShape();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > 0)
                os << " ";
            os << matrix[i][j];
        }

        if (i != n - 1)
            os << "\n";
    }

    return os;
}

template <class T>
Matrix<T> operator*(Matrix<T> lhs, const Matrix<T> &rhs)
{
    lhs *= rhs;
    return lhs;
}

template <class T>
Matrix<T> operator+(Matrix<T> lhs, const Matrix<T> &rhs)
{
    lhs += rhs;
    return lhs;
}

template <class T>
Matrix<T> operator-(Matrix<T> lhs, const Matrix<T> &rhs)
{
    lhs -= rhs;
    return lhs;
}

template <class T, class G>
Matrix<T> operator+(G num, const Matrix<T> &matrix)
{
    Matrix<T> res = matrix;
    res += num;
    return res;
}

template <class T, class G>
Matrix<T> operator-(G num, const Matrix<T> &matrix)
{
    Matrix<T> res = matrix;
    res -= num;
    return res;
}

template <class T, class G>
Matrix<T> operator*(G num, const Matrix<T> &matrix)
{
    Matrix<T> res = matrix;
    res *= num;
    return res;
}

template <class T, class G>
Matrix<T> operator+(Matrix<T> matrix, const G &num)
{
    matrix += num;
    return matrix;
}

template <class T, class G>
Matrix<T> operator-(Matrix<T> matrix, const G &num)
{
    matrix -= num;
    return matrix;
}

template <class T, class G>
Matrix<T> operator*(Matrix<T> matrix, const G &num)
{
    matrix *= num;
    return matrix;
}

template <class T>
Matrix<T> Matrix<T>::matmul(const Matrix<T> rhs)
{
    Matrix<T> res = *this;
    res *= rhs;
    return res;
}

template <class T>
Matrix<T> Matrix<T>::add(const Matrix<T> rhs)
{
    Matrix<T> res = *this;
    res += rhs;
    return res;
}

template <class T>
Matrix<T> Matrix<T>::subtract(const Matrix<T> rhs)
{
    Matrix<T> res = *this;
    res -= rhs;
    return res;
}
