#include "base-types.h"
#include <cmath>
#include <algorithm>
#include <array>
double twoPointsDistance(const point_t &p1, const point_t &p2)
{
  double line_x = p1.x - p2.x;
  double line_y = p1.y - p2.y;
  return std::sqrt(line_x * line_x + line_y * line_y);
}
bool isTriangle(std::array< double, 3 > sides)
{
  double a = sides[0];
  double b = sides[1];
  double c = sides[2];
  double maxSide = std::max({a, b, c});
  double minSide = std::max({a, b, c});
  double midlSide = a + b + c - maxSide - minSide;
  return (maxSide < minSide + midlSide);
}
bool pointLeftToLine(point_t point, point_t l1, point_t l2)
{
  return ((point.x - l1.x) * (l2.y - l1.y) - (point.y - l1.y) * (l2.x - l1.x) > 0);
}
bool pointInsideTriangle(triangle_t triangle, point_t point)
{
  point_t a = triangle.a;
  point_t b = triangle.b;
  point_t c = triangle.c;
  bool isLeftAB = pointLeftToLine(point, a, b);
  bool isLeftBC = pointLeftToLine(point, b, c);
  bool isLeftCA = pointLeftToLine(point, c, a);
  return ((isLeftAB && isLeftBC && isLeftCA) || (!isLeftAB && !isLeftBC && !isLeftCA));
}
point_t multiplyVector(point_t center, point_t point, double koeff)
{
  point.x = koeff * (point.x - center.x) + center.x;
  point.y = koeff * (point.y - center.y) + center.y;
  return point;
}
point_t shift(point_t position, point_t center)
{
  double dx = position.x - center.x;
  double dy = position.y - center.y;
  return {dx, dy};
}
point_t addVectorToPoint(point_t point, double dx, double dy)
{
  point.x += dx;
  point.y += dy;
  return point;
}
