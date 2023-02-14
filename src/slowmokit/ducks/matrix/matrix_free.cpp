/**
 * @file ducks/matrix/matrix_free.cpp
 *
 * Implementation of the free functions associated with matrix
 */

#include "matrix.hpp"

template<class T> Matrix<T> operator*(Matrix<T> lhs, const Matrix<T> &rhs)
{
  lhs *= rhs;
  return lhs;
}

template<class T> Matrix<T> operator+(Matrix<T> lhs, const Matrix<T> &rhs)
{
  lhs += rhs;
  return lhs;
}

template<class T> Matrix<T> operator-(Matrix<T> lhs, const Matrix<T> &rhs)
{
  lhs -= rhs;
  return lhs;
}

template<class T, class G> Matrix<T> operator+(G num, const Matrix<T> &matrix)
{
  Matrix<T> res = matrix;
  res += num;
  return res;
}

template<class T, class G> Matrix<T> operator-(G num, const Matrix<T> &matrix)
{
  Matrix<T> res = matrix;
  res -= num;
  return res;
}

template<class T, class G> Matrix<T> operator*(G num, const Matrix<T> &matrix)
{
  Matrix<T> res = matrix;
  res *= num;
  return res;
}

template<class T, class G> Matrix<T> operator+(Matrix<T> matrix, const G &num)
{
  matrix += num;
  return matrix;
}

template<class T, class G> Matrix<T> operator-(Matrix<T> matrix, const G &num)
{
  matrix -= num;
  return matrix;
}

template<class T, class G> Matrix<T> operator*(Matrix<T> matrix, const G &num)
{
  matrix *= num;
  return matrix;
}

template<class T> Matrix<T> Matrix<T>::matmul(const Matrix<T> rhs)
{
  Matrix<T> res = *this;
  res *= rhs;
  return res;
}

template<class T> Matrix<T> Matrix<T>::add(const Matrix<T> rhs)
{
  Matrix<T> res = *this;
  res += rhs;
  return res;
}

template<class T> Matrix<T> Matrix<T>::subtract(const Matrix<T> rhs)
{
  Matrix<T> res = *this;
  res -= rhs;
  return res;
}