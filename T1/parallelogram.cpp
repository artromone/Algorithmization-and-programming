#include "parallelogram.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
Parallelogram::Parallelogram(const point_t &A, const point_t &B, const point_t &C):
  points_{A, B, C}
{
  if (!isGoodParallelogramInput())
  {
    throw std::invalid_argument("Bad parallelogram input.");
  }
}
double Parallelogram::getArea() const
{
  double a = twoPointsDistance(points_[1], points_[2]);
  double b = twoPointsDistance(points_[0], points_[1]);
  double c = twoPointsDistance(points_[0], points_[2]);
  double p = (a + b + c) / 2;
  return 2 * std::sqrt(p * (p - a) * (p - b) * (p - c));
}
rectangle_t Parallelogram::getFrameRect() const
{
  double sup = std::max({points_[0].y, points_[1].y, points_[2].y});
  double inf = std::min({points_[0].y, points_[1].y, points_[2].y});
  double left = std::min({points_[0].x, points_[1].x, points_[2].x});
  double right = std::max({points_[0].x, points_[1].x, points_[2].x});
  return {(right + left) / 2, (sup + inf) / 2, right - left, sup - inf};
}
void Parallelogram::move(double dx, double dy)
{
  for (point_t &point: points_)
  {
    point = addVectorToPoint(point, dx, dy);
  }
}
void Parallelogram::move(const point_t &position)
{
  point_t s = shift(position, getFrameRect().pos);
  move(s.x, s.y);
}
void Parallelogram::unsafeScale(double k) noexcept
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  for (point_t &point: points_)
  {
    point = multiplyVector(center, point, k);
  }
}
Shape *Parallelogram::clone() const
{
  return new Parallelogram(points_[0], points_[1], points_[2]);
}
bool Parallelogram::isGoodParallelogramInput() const
{
  double a_y = points_[0].y;
  double b_y = points_[1].y;
  double c_y = points_[2].y;
  return (((a_y == b_y) || (b_y == c_y)) && (a_y - b_y != c_y - b_y));
}
