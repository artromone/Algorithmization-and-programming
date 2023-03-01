#ifndef I4_SMOOTHEDMATRIX_H
#define I4_SMOOTHEDMATRIX_H
#include <cstddef>
int countUpperMainDiagonal(const int * matrix, size_t matrixDim);
void smoothMatrix(const int * matrix, int * smoothedMatrix, size_t matrixDim);
#endif
