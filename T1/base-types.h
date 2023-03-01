#ifndef SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#define SPBSPU_LABS_2022_AAP_904_A_BASE_TYPES_H
#include <algorithm>
#include <array>
struct point_t
{
  double x, y;
};
struct triangle_t
{
  point_t a, b, c;
};
struct rectangle_t
{
  point_t pos;
  double width, height;
};
double twoPointsDistance(const point_t &p1, const point_t &p2);
bool isTriangle(std::array< double, 3 > sides);
bool pointInsideTriangle(triangle_t triangle, point_t point);
bool pointLeftToLine(point_t point, point_t l1, point_t l2);
point_t multiplyVector(point_t center, point_t point, double koeff);
point_t shift(point_t position, point_t center);
point_t addVectorToPoint(point_t point, double dx, double dy);
#endif
