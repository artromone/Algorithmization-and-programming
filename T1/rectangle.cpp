#include "rectangle.h"
#include <stdexcept>
Rectangle::Rectangle(const point_t &A, const point_t &C):
  a_(A),
  c_(C)
{
  if (!isGoodRectangleInput())
  {
    throw std::invalid_argument("Bad rectangle input.");
  }
}
double Rectangle::getArea() const
{
  return getFrameRect().height * getFrameRect().width;
}
rectangle_t Rectangle::getFrameRect() const
{
  return {(c_.x + a_.x) / 2, (c_.y + a_.y) / 2, c_.x - a_.x, c_.y - a_.y};
}
void Rectangle::move(double dx, double dy)
{
  a_ = addVectorToPoint(a_, dx, dy);
  c_ = addVectorToPoint(c_, dx, dy);
}
void Rectangle::move(const point_t &position)
{
  point_t s = shift(position, getFrameRect().pos);
  move(s.x, s.y);
}
void Rectangle::unsafeScale(double k) noexcept
{
  point_t center{getFrameRect().pos.x, getFrameRect().pos.y};
  a_ = multiplyVector(center, a_, k);
  c_ = multiplyVector(center, c_, k);
}
Shape *Rectangle::clone() const
{
  return new Rectangle(a_, c_);
}
bool Rectangle::isGoodRectangleInput() const
{
  return (a_.x < c_.x && a_.y < c_.y);
}
