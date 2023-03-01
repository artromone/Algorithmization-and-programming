#include <iostream>
#include "sequence.h"

int main() {

  Counter counter{1, 1, 0};
  LocalMax localMax{0, 0, 0};

  unsigned int currentValue = 0;
  do {
    std::cin >> currentValue;

    if (!std::cin) {
      std::cout << "Error occurred." << std::endl;
      return 1;
    }

    try {
      counter(currentValue);
      localMax(currentValue);
    } catch (const std::overflow_error &e) {
      std::cout << e.what() << std::endl;
      return 2;
    }

  } while (currentValue && std::cin);

  std::cout << "Maximum successive equal elements number: " << counter.countMax << std::endl;
  std::cout << "Strict local maxima number: " << localMax.count << std::endl;

  return 0;
}
