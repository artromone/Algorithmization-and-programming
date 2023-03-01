#include "compositeshape.h"
#include <stdexcept>
void CompositeShape::push_back(Shape *shp)
{
  size_t capAdd = 2;
  Shape **newShape = new Shape *[capacity_ + capAdd];
  capacity_ += capAdd;
  for (size_t i = 0; i <= size_; ++i)
  {
    newShape[i] = shape_[i];
  }
  delete[] shape_;
  shape_ = newShape;
  shape_[size_] = shp;
  size_++;
}
void CompositeShape::push_back(const Shape *shp)
{
  Shape *shpCopy = shp->clone();
  try
  {
    push_back(shpCopy);
  }
  catch (...)
  {
    delete shpCopy;
    throw;
  }
}
void CompositeShape::pop_back()
{
  delete shape_[size_];
  size_--;
}
void CompositeShape::isoScale(const point_t &position, double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling koeff.");
  }
  unsafeIsoScale(position, k);
}
void CompositeShape::unsafeIsoScale(const point_t &position, double k) noexcept
{
  for (size_t i = 0; i < size_; i++)
  {
    point_t s = shift(position, shape_[i]->getFrameRect().pos);
    shape_[i]->move(s.x, s.y);
    s.x *= -k;
    s.y *= -k;
    shape_[i]->unsafeScale(k);
    shape_[i]->move(s.x, s.y);
  }
}
CompositeShape::CompositeShape(size_t capacity):
  shape_(new Shape *[capacity]),
  size_(0),
  capacity_(capacity)
{
}
Shape *CompositeShape::operator[](size_t id)
{
  return shape_[id];
}
const Shape *CompositeShape::operator[](size_t id) const
{
  return shape_[id];
}
void CompositeShape::move(point_t position)
{
  move(position.x - getFrameRect().pos.x, position.y - getFrameRect().pos.y);
}
void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}
Shape *CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::invalid_argument("Invalid id provided.");
  }
  return shape_[id];
}
const Shape *CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::invalid_argument("Invalid id provided.");
  }
  return shape_[id];
}
size_t CompositeShape::size() const noexcept
{
  return size_;
}
bool CompositeShape::empty() const noexcept
{
  return (size_ == 0);
}
void CompositeShape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling koeff.");
  }
  unsafeScale(k);
}
void CompositeShape::unsafeScale(double k)
{
  for (size_t i = 0; i < size_; i++)
  {
    shape_[i]->unsafeScale(k);
  }
}
CompositeShape::CompositeShape(const CompositeShape &rhs):
  CompositeShape(rhs.capacity_)
{
  size_ = rhs.size_;
  size_t index = 0;
  try
  {
    while (index < rhs.size_)
    {
      shape_[index] = rhs.shape_[index]->clone();
      ++index;
    }
  }
  catch (...)
  {
    remove(shape_, index);
    throw;
  }
}
CompositeShape::CompositeShape(CompositeShape &&rhs) noexcept:
  shape_(rhs.shape_),
  size_(rhs.size_),
  capacity_(rhs.capacity_)
{
  rhs.size_ = 0;
  rhs.shape_ = nullptr;
}
double CompositeShape::getArea() const
{
  double area = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shape_[i]->getArea();
  }
  return area;
}
rectangle_t CompositeShape::getFrameRect()
{
  rectangle_t firstRectangle = shape_[0]->getFrameRect();
  double minX = firstRectangle.pos.x - firstRectangle.width * 0.5;
  double maxX = firstRectangle.pos.x + firstRectangle.width * 0.5;
  double minY = firstRectangle.pos.y - firstRectangle.height * 0.5;
  double maxY = firstRectangle.pos.y + firstRectangle.height * 0.5;
  for (size_t i = 1; i < size_; i++)
  {
    rectangle_t rectangle = shape_[i]->getFrameRect();
    double left = rectangle.pos.x - rectangle.width * 0.5;
    double right = rectangle.pos.x + rectangle.width * 0.5;
    double inf = rectangle.pos.y - rectangle.height * 0.5;
    double sup = rectangle.pos.y + rectangle.height * 0.5;
    minX = std::min(left, minX);
    maxX = std::max(right, maxX);
    minY = std::min(inf, minY);
    maxY = std::max(sup, maxY);
  }
  point_t pos{(minX + maxX) / 2, (minY + maxY) / 2};
  rectangle_t frame{pos, maxX - minX, maxY - minY};
  return frame;
}
CompositeShape::~CompositeShape()
{
  remove(shape_, size_);
}
CompositeShape &CompositeShape::operator=(const CompositeShape &rhs)
{
  Shape **newShape = new Shape *[rhs.capacity_];
  size_t newSize = 0;
  try
  {
    for (size_t i = 0; i < rhs.size_; ++i)
    {
      newShape[i] = rhs.shape_[i]->clone();
      ++newSize;
    }
  }
  catch (...)
  {
    remove(newShape, newSize);
    throw;
  }
  remove(shape_, size_);
  shape_ = newShape;
  capacity_ = rhs.capacity_;
  size_ = newSize;
  return *this;
}
CompositeShape &CompositeShape::operator=(CompositeShape &&rhs) noexcept
{
  remove(shape_, size_);
  shape_ = rhs.shape_;
  capacity_ = rhs.capacity_;
  size_ = rhs.size_;
  rhs.shape_ = nullptr;
  rhs.size_ = 0;
  return *this;
}
void CompositeShape::remove(Shape **shape, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shape[i];
  }
  delete[] shape;
}
