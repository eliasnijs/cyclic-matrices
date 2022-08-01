#if !defined(FOURIER_H)

#include "vector.h"
#include "complex_number.h"

internal complex_number
FourierMatrixElement(uint32 Length, uint32 I, uint32 J);

internal complex_number
FourierMatrixNormalizedElement(uint32 N, uint32 I, uint32 J);

internal vector 
FourierDiscreteTransform(vector *Vector);

internal vector 
FourierDiscreteTransformInverse(vector *Vector);

#define FOURIER_H
#endif
