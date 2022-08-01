#if !defined(VECTOR_H)

#include "complex_number.h"

struct vector
{
  uint32 Size; 
  complex_number *Elements;
};

internal vector
VectorRandom(uint32 Dim1, uint32 Dim2);

internal complex_number
VectorGetElement(vector *Vector, uint32 Index);

internal vector 
VectorNegative(vector *Vector);

internal vector 
VectorScale(complex_number Scalar, vector *Vector2);

internal vector 
VectorSum(vector *Vector1, vector *Vector2);

internal vector 
VectorSubtract(vector *Vector1, vector *Vector2);

internal bool32 
VectorEqual(vector *Vector1, vector *Vector2);

internal bool32 
VectorIsNull(vector *Vector);

internal std::string 
VectorToString(vector *Vector, uint32 breakPoint);

internal inline vector 
operator-(vector Vector)
{
  return(VectorNegative(&Vector));
}

internal inline vector 
operator*(complex_number Scalar, vector Vector)
{
  return(VectorScale(Scalar, &Vector));
}

internal inline vector 
operator*(vector Vector, complex_number Scalar)
{
  return(VectorScale(Scalar, &Vector));
}

internal inline vector 
operator+(vector Vector1, vector Vector2)
{
  return(VectorSum(&Vector1, &Vector2));
}

internal inline vector 
operator-(vector Vector1, vector Vector2)
{
  return(VectorSubtract(&Vector1, &Vector2));
}

internal inline bool32 
operator==(vector Vector1, vector Vector2)
{
  return(VectorEqual(&Vector1, &Vector2));
}

#define VECTOR_H
#endif

