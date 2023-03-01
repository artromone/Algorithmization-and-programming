#include "countsuitablerows.h"
size_t countDiverseElements(const int * array, const size_t rows, const size_t columns)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      bool foundSimilar = false;
      int currentEl = array[i * rows + j];
      for (size_t k = j + 1; k < columns; k++)
      {
        if (currentEl == array[i * rows + k])
        {
          foundSimilar = true;
          break;
        }
      }
      count += size_t(foundSimilar);
    }
  }
  return count;
}
size_t countEqualSum(const int * array, const size_t rows, const size_t columns)
{
  size_t count = 0;
  int arraySums[rows];
  for (size_t i = 0; i < rows; i++)
  {
    arraySums[i] = 0;
    for (size_t j = 0; j < columns; j++)
    {
      arraySums[i] += array[i * rows + j];
    }
  }
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = i + 1; j < rows; j++)
    {
      if (arraySums[i] == arraySums[j])
      {
        count++;
      }
    }
  }
  return count;
}
size_t countSuccessionEqualElements(const int * matrix, const size_t matrixDim)
{
  size_t count = 0;
  for (size_t i = 0; i < matrixDim; i++)
  {
    bool foundSuccessionEqual = false;
    for (size_t j = 0; j < matrixDim - 1; j++)
    {
      if (matrix[i * matrixDim + j] == matrix[i * matrixDim + j + 1])
      {
        foundSuccessionEqual = true;
        break;
      }
      if (!foundSuccessionEqual)
      {
        count++;
      }
    }
  }
  return count;
}
