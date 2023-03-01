#include "hasRepeatingElements.h"
#include <cstddef>
#include <cctype>
bool hasRepeatingElements(const char *source)
{
  const char* p1 = source;
  const char* p2 = source + 1;

  while (*p1 != '\0')
  {
    while (*p2 != '\0')
    {
      if (*p1 == *p2)
      {
        return true;
      }
      p2++;
    }
    p1++;
    p2 = p1 + 1;
  }
  return false;
}
bool hasRepeatingElements(const char *source1, const char *source2)
{
  const char* p1 = source1;
  const char* p2 = source2;

  while (*p1 != '\0')
  {
    while (*p2 != '\0')
    {
      if (*p1 == *p2)
      {
        return true;
      }
      p2++;
    }
    p1++;
    p2 = source2;
  }
  return false;
}
