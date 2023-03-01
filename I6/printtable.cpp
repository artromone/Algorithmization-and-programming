#include "printtable.h"
#include <iomanip>
#include <cmath>
#include <cstddef>
#include <ostream>
#include "comparedoubles.h"
#include "sinh.h"
void printTableRow(std::ostream &out, double x, double absError, size_t numberMax)
{
  out << std::setw(5) << x << " ";
  out << std::setw(10) << std::setprecision(5) << countSinh(x, absError, numberMax) << " ";
  out << std::setw(10) << std::setprecision(5) << sinh(x) << "\n";
}
void printTable(std::ostream &out, double left, double right, double step, double absError, size_t numberMax)
{
  int incrementValue = 1;
  int leftBorder = static_cast< int >(left / step);
  int rightBorder = static_cast< int >(right / step);
  for (int i = leftBorder; i <= rightBorder; i += incrementValue)
  {
    double value = i * step;
    if (isSmaller(std::abs(value), step / 10, 1e-6))
    {
      value = 0;
    }
    printTableRow(out, value, absError, numberMax);
  }
}
