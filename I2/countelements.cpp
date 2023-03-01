#include "countelements.h"
#include <cstddef>
size_t countNegativeRightFromMax(const int *array, size_t size)
{
  size_t countNegativeRightFromMax = 0;
  size_t maxElIndex = 0;
  if (size == 0)
  {
    return 0;
  }
  else
  {
    int maxEl = array[0];
    for (size_t i = 0; i < size; i++)
    {
      if (array[i] > maxEl)
      {
        maxEl = array[i];
        maxElIndex = i;
      }
    }
    for (size_t i = 0; i < size; i++)
    {
      if (i > maxElIndex)
      {
        if (array[i] < 0)
        {
          countNegativeRightFromMax++;
        }
      }
    }
    return countNegativeRightFromMax;
  }
}
bool countRepetitiveInRange(const int *array, const size_t size, const size_t beginIndex, const size_t endIndex)
{
  if (beginIndex >= endIndex || endIndex > size || beginIndex > size)
  {
    return true;
  }
  for (size_t i = beginIndex; i <= endIndex; i++)
  {
    for (size_t j = i + 1; j <= endIndex; j++)
    {
      if (array[i] == array[j])
      {
        return true;
      }
    }
  }
  return false;
}
