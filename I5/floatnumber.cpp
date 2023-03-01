#include "floatnumber.h"
#include <cctype>
bool isZero(char c)
{
  return (c == '0');
}
bool isNumberSign(char c)
{
  return (c == '+') || (c == '-');
}
bool isDigit(char c)
{
  return std::isdigit(c);
}
bool isStringEnd(char c)
{
  return (c == '\0');
}
bool isDot(char c)
{
  return (c == '.') || (c == ',');
}
bool isLetterE(char c)
{
  return (c == 'E');
}
bool isBaseUnsignedInteger(const char *data)
{
  return isDigit(*data) && ((isDigit(*data) && isBaseUnsignedInteger(data + 1)) || isStringEnd(*(data + 1)));
}
bool isBase(const char *data)
{
  return isLetterE(*data) && ((isNumberSign(*(data + 1)) && isBaseUnsignedInteger(data + 2)) || isBaseUnsignedInteger(data + 1));
}
bool isSignificandUnsignedInteger(const char *data)
{
  return isDigit(*data) && ((isDigit(*data) && isSignificandUnsignedInteger(data + 1)) || isBase(data + 1));
}
bool isSignificand(const char *data)
{
  return isSignificandUnsignedInteger(data) || (isDot(*data) && isSignificandUnsignedInteger(data + 1));
}
bool isFloat(const char *data)
{
  return (!isZero(*data) && (isSignificand(data))) || ((isNumberSign(*data) && isSignificand(data + 1)));
}
