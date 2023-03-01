#include "shape.h"
#include <stdexcept>
void Shape::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Invalid scaling koeff.");
  }
  unsafeScale(k);
}
