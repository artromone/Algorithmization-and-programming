#ifndef I6_PRINTTABLE_H
#define I6_PRINTTABLE_H
#include <cstddef>
#include <ostream>
void printTable(std::ostream &out, double left, double right, double step, double absError, size_t numberMax);
#endif
