#include "hasRepeatingElements.h"
#include <iostream>
#include <extendstring.h>
#include <inputstring.h>
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
  try
  {
    std::cout << std::boolalpha << hasRepeatingElements(cstring) << "\n";
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] cstring;
    return 1;
  }
  try
  {
    const char *stringCompare = "Why did a C++ programmer cross the street? What for? To pick up trash! HAHAHAHAHAHA!";
    std::cout << std::boolalpha << hasRepeatingElements(cstring, stringCompare) << "\n";
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << e.what() << "\n";
    delete [] cstring;
    return 1;
  }
  delete[] cstring;
}
