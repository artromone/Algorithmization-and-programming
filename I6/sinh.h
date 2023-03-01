#ifndef I6_SINH_H
#define I6_SINH_H
#include <cstddef>
class NextSinhElMultiplier
{
public:
  explicit NextSinhElMultiplier(double x);
  double operator()();
private:
  double x;
  size_t numberSummand;
};
double countSinh(double x, double absError, size_t numberMax);
#endif
