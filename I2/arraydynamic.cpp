#include "arraydynamic.h"
#include <stdexcept>
ArrayDynamic::ArrayDynamic(size_t capacity):
  data(new int[capacity])
{
}
ArrayDynamic::~ArrayDynamic()
{
  delete [] data;
}
