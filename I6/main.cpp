#include <iostream>
#include "printtable.h"
#include "sinh.h"
int main()
{
  double left = 0;
  double right = 0;
  size_t numberMax = 0;
  double absError = 1e-6;
  double step = 1e-2;
  std::cin >> left >> right >> numberMax;
  if (!std::cin)
  {
    std::cerr << "Error while input.\n";
    return 2;
  }
  if (left > right)
  {
    std::cerr << "Invalid interval.\n";
    return 2;
  }
  try
  {
    printTable(std::cout, left, right, step, absError, numberMax);
  }
  catch (...)
  {
    std::cerr << "Error while printing table.\n";
    return 2;
  }
}
