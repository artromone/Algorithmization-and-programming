#include "concave.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <array>
Concave::Concave(const point_t &A, const point_t &B, const point_t &C, const point_t &D):
  points_{A, B, C, D}
{
  if (!isGoodConcaveInput())
  {
    throw std::invalid_argument("Bad concave input.");
  }
}
bool Concave::isGoodConcaveInput() const
{
  std::array< double, 3 > arr = {splitIntoTriangles()[0], splitIntoTriangles()[1], splitIntoTriangles()[2]};
  return pointInsideTriangle(triangle_t{points_[0], points_[1], points_[2]}, points_[3]) && isTriangle(arr);
}
std::array< double, 6 > Concave::splitIntoTriangles() const
{
  double a = twoPointsDistance(points_[0], points_[2]);
  double b = twoPointsDistance(points_[2], points_[1]);
  double c = twoPointsDistance(points_[0], points_[1]);
  double a1 = twoPointsDistance(points_[2], points_[3]);
  double b1 = b;
  double c1 = twoPointsDistance(points_[3], points_[1]);
  std::array< double, 6 > arr = {a, b, c, a1, b1, c1};
  return arr;
}
double Concave::getArea() const
{
  std::array< double, 6 > sides = splitIntoTriangles();
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double a1 = sides[3];
  double b1 = sides[4];
  double c1 = sides[5];
  double p = (a + b + c) / 2;
  double p1 = (a1 + b1 + c1) / 2;
  double s = std::sqrt(p * (p - a) * (p - b) * (p - c));
  double s1 = std::sqrt(p1 * (p1 - a1) * (p1 - b1) * (p1 - c1));
  return s - s1;
}
rectangle_t Concave::getFrameRect() const
{
  double sup = std::max({points_[0].y, points_[1].y, points_[2].y});
  double inf = std::min({points_[0].y, points_[1].y, points_[2].y});
  double left = std::min({points_[0].x, points_[1].x, points_[2].x});
  double right = std::max({points_[0].x, points_[1].x, points_[2].x});
  return {(right + left) / 2, (sup + inf) / 2, right - left, sup - inf};
}
void Concave::move(double dx, double dy)
{
  for (point_t &point: points_)
  {
    point = addVectorToPoint(point, dx, dy);
  }
}
void Concave::move(const point_t &position)
{
  point_t s = shift(position, getFrameRect().pos);
  move(s.x, s.y);
}
void Concave::unsafeScale(double k) noexcept
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  for (point_t &point: points_)
  {
    point = multiplyVector(center, point, k);
  }
}
Shape *Concave::clone() const
{
  return new Concave(points_[0], points_[1], points_[2], points_[3]);
}
