#if !defined(CYCLIC_MATRIX_H)

#include "vector.h"

struct matrix_cyclic 
{
  vector Vector;
};



//  BASIC OPERATIONS  //////////////////////////////////////////////////////

internal std::string 
MatrixCyclicToString(matrix_cyclic *A);

internal bool32 
MatrixCyclicEquals(matrix_cyclic *A, matrix_cyclic *B);

internal bool32 
MatrixCyclicEquals(matrix_cyclic *A, matrix_cyclic *B);

internal matrix_cyclic 
MatrixCyclicSum(matrix_cyclic *A, matrix_cyclic *B);

internal matrix_cyclic 
MatrixCyclicSubtract(matrix_cyclic *A, matrix_cyclic *B);

internal matrix_cyclic 
MatrixCyclicMultiply(matrix_cyclic *A, matrix_cyclic *B);

internal vector 
MatrixCyclicMultiply(matrix_cyclic *A, vector *B);

internal inline bool32
operator==(matrix_cyclic A, matrix_cyclic B)
{
  return(MatrixCyclicEquals(&A, &B));
}

internal inline bool32
operator!=(matrix_cyclic A, matrix_cyclic B)
{
  return(!MatrixCyclicEquals(&A, &B));
}

internal inline matrix_cyclic 
operator+(matrix_cyclic A, matrix_cyclic B)
{
  return(MatrixCyclicSum(&A, &B));
}

internal inline matrix_cyclic 
operator-(matrix_cyclic A, matrix_cyclic B)
{
  return(MatrixCyclicSubtract(&A, &B));
}

internal inline matrix_cyclic 
operator*(matrix_cyclic A, matrix_cyclic B)
{
  return(MatrixCyclicMultiply(&A, &B));
}

internal inline vector 
operator*(matrix_cyclic A, vector B)
{
  return(MatrixCyclicMultiply(&A, &B));
}

//  COMPLEX OPERATIONS /////////////////////////////////////////////////////

internal matrix_cyclic 
MatrixCyclicPower(matrix_cyclic *A, int32 power);

internal vector
SolveAxEqualsb(matrix_cyclic *A, vector *B);

#define CYCLIC_MATRIX_H
#endif



