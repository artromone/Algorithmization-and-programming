#include "comparedoubles.h"
#include <cmath>
#include <limits>
bool isSmaller(double a, double b, double epsilon)
{
  double absA = std::abs(a);
  double absB = std::abs(b);
  double diff = std::abs(a - b);
  double minDouble = std::numeric_limits< double >::min();
  if (a < b)
  {
    return true;
  }
  if (a == 0 || b == 0 || diff < minDouble)
  {
    return diff < (epsilon * minDouble);
  }
  else
  {
    return diff / (absA + absB) < epsilon;
  }
}
