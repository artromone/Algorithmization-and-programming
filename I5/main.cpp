#include <iostream>
#include <extendstring.h>
#include <inputstring.h>
#include "floatnumber.h"
int main()
{
  char *cstring = nullptr;
  try
  {
    cstring = inputString(std::cin);
  }
  catch (...)
  {
    std::cerr << "Error occured.\n";
    return 2;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  delete[] cstring;
}
