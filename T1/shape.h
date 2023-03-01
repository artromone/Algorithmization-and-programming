#ifndef SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_SHAPE_H
#include "base-types.h"
class Shape
{
public:
  virtual ~Shape() = default;
  virtual double getArea() const = 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(double dx, double dy) = 0;
  virtual void move(const point_t &position) = 0;
  virtual void unsafeScale(double k) noexcept = 0;
  void scale(double k);
  virtual Shape *clone() const = 0;
};
#endif
