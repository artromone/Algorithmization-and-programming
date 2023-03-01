#ifndef I2_ARRAYDYNAMIC_H
#define I2_ARRAYDYNAMIC_H
#include <cstddef>
struct ArrayDynamic
{
  explicit ArrayDynamic(size_t capacity);
  ~ArrayDynamic();
  int *data;
};
#endif
