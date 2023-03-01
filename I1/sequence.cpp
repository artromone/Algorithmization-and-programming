#include "sequence.h"
#include <stdexcept>
#include <limits>

void Counter::operator()(unsigned int currentValue)
{
  const unsigned int maxUnsignedInt = std::numeric_limits< unsigned int >::max();

  if (previousValue == currentValue && currentValue != 0) {
    if (count == maxUnsignedInt) {
      throw std::overflow_error("Sequence too long. Error occurred.");
    }
    count += 1;

  } else {
    count = 1;
  }

  if (count > countMax) {
    countMax = count;
  }

  previousValue = currentValue;
}

void LocalMax::operator()(unsigned int currentValue)
{
  const unsigned int maxUnsignedInt = std::numeric_limits< unsigned int >::max();

  if (currentValue != 0 && previousValue != 0 && beforePreviousValue != 0) {
    if (count == maxUnsignedInt) {
      throw std::overflow_error("Sequence too long. Error occurred.");
    }

    count += (previousValue > currentValue && previousValue > beforePreviousValue);
  }

  beforePreviousValue = previousValue;
  previousValue = currentValue;
}

