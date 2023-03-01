#include "smoothedmatrix.h"
int sumClose(const int * matrix, const size_t row, const size_t column, const size_t matrixDim)
{
  int sum_ = 0;
  int count = 0;
  for (size_t k = (row > 0) ? row - 1 : row; k <= row + 1; k++)
  {
    for (size_t l = (column > 0) ? column - 1 : column; l <= column + 1; l++)
    {
      size_t elemIndex = k * matrixDim + l;
      bool elemInMatrixRange = (elemIndex <= matrixDim * matrixDim);
      bool elemNotCenterElem = !(k == row && l == column);
      bool kInRowRange = k < matrixDim;
      bool lInColumnRange = l < matrixDim;
      if (elemInMatrixRange && elemNotCenterElem && lInColumnRange && kInRowRange)
      {
        sum_ += matrix[elemIndex];
        count++;
      }
    }
  }
  return sum_ / count;
}
int countUpperMainDiagonal(const int * matrix, const size_t matrixDim)
{
  int sum_ = 0;
  for (size_t i = 0; i < matrixDim - 1; i++)
  {
    for (size_t j = i + 1; j < matrixDim; j++)
    {
      int value = matrix[i * matrixDim + j];
      sum_ += value * ((value > 0) - (value < 0));
    }
  }
  return sum_;
}
void smoothMatrix(const int * matrix, int * smoothedMatrix, const size_t matrixDim)
{
  for (size_t i = 0; i < matrixDim; i++)
  {
    for (size_t j = 0; j < matrixDim; j++)
    {
      smoothedMatrix[i * matrixDim + j] = sumClose(matrix, i, j, matrixDim);
    }
  }
}
