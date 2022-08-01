
#include "fourier.h"

internal complex_number
FourierMatrixElement(uint32 N, uint32 I, uint32 J) 
{
  real64 Theta = (I * J * ((2 * Pi64) / N));
  complex_number Result = {cos(Theta), sin(Theta)};
  return(Result);
}

internal complex_number
FourierMatrixNormalizedElement(uint32 N, uint32 I, uint32 J) 
{
  real64 theta = ((2 * Pi64 * I * J) / N);
  real64 r = (1 / sqrt(N));
  complex_number Result = {r * cos(theta), r * sin(theta)};
  return(Result);
}

internal vector 
FourierDiscreteTransform(vector *Vector)
{
  vector DFT = VectorInit(Vector->Size);
  for (uint32 k = 0;
       k < Vector->Size;
       ++k)
  {
    for (uint32 j = 0;
         j < Vector->Size;
         ++j)
    {
      DFT.Elements[k] = DFT.Elements[k] + 
        (Vector->Elements[j] * FourierMatrixElement(Vector->Size, k, j));
    }
  }
  return(DFT);
}

internal vector 
FourierDiscreteTransformInverse(vector *Vector)
{
  vector DFT = VectorInit(Vector->Size);
  for (uint32 k = 0;
       k < Vector->Size;
       ++k)
  {
    for (uint32 j = 0;
         j < Vector->Size;
         ++j)
    {
      DFT.Elements[k] = DFT.Elements[k] + 
        (Vector->Elements[j] * FourierMatrixElement(Vector->Size, k, j));
    }
    DFT.Elements[k] = DFT.Elements[k] / Vector->Size;
  }
  return(DFT);
}










