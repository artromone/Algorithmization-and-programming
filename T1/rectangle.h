#ifndef SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#include "shape.h"
class Rectangle: public Shape
{
public:
  explicit Rectangle(const point_t &A, const point_t &C);
  ~Rectangle() override = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &position) override;
  void unsafeScale(double k) noexcept override;
  Shape *clone() const override;
private:
  point_t a_, c_;
  bool isGoodRectangleInput() const;
};
#endif
