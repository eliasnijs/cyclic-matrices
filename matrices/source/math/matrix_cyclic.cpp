
#include "fourier.h"
#include "complex_number.h"
#include "matrix_cyclic.h"

internal complex_number 
MatrixCyclicGetElement(matrix_cyclic *A, uint32 i, uint32 j)
{
  uint32 Size = A->Vector.Size;
  complex_number *Elements = A->Vector.Elements;
  complex_number Element = Elements[(Size + j - i) % Size];
  return(Element);
}

internal std::string
MatrixCyclicToString(matrix_cyclic *A)
{
  std::string String = "[\n";
  uint32 Size = A->Vector.Size;
  complex_number *Elements = A->Vector.Elements;
  for (int32 x = 0; 
       x < (int32) Size;
       ++x)
  {
    String += "   [";
    for (int32 y = 0; 
         y < (int32) Size;
         ++y)
    {
      complex_number Element = Elements[(Size + y - x) % Size];
      std::string ElementString = ComplexNumberToString(Element);
      String += (" " + ElementString + ",");
    }
    String += "],\n";
  }
  String += "]";
  return(String);
}

internal bool32 
MatrixCyclicEquals(matrix_cyclic *A, matrix_cyclic *B)
{
  Assert(A->Vector.Size == B->Vector.Size);
  bool32 Result = true;
  uint32 SizeA = A->Vector.Size;
  uint32 SizeB = B->Vector.Size;
  complex_number *ElementsA = A->Vector.Elements;
  complex_number *ElementsB = B->Vector.Elements;
  if (SizeA != SizeB)
  {
    Result = false;
  }
  for (int32 x = 0; 
      ((x < ((int32) SizeA)) && Result);
       ++x)
  {
    for (int32 y = 0; 
         ((y < ((int32) SizeA)) && Result);
         ++y)
    {
      Result = (ElementsA[(SizeA + y - x) % SizeA] == 
                 ElementsB[(SizeA + y - x) % SizeA]);
    }
  }
  return(Result);
}

internal matrix_cyclic 
MatrixCyclicSum(matrix_cyclic *A, matrix_cyclic *B)
{
  Assert(A->Vector.Size == B->Vector.Size);
  matrix_cyclic Result = {(A->Vector + B->Vector)};
  return(Result);
}

internal matrix_cyclic 
MatrixCyclicSubtract(matrix_cyclic *A, matrix_cyclic *B)
{
  Assert(A->Vector.Size == B->Vector.Size);
  matrix_cyclic Result = {(A->Vector - B->Vector)};
  return(Result);
}

internal matrix_cyclic 
MatrixCyclicMultiply(matrix_cyclic *A, matrix_cyclic *B)
{
  Assert(A->Vector.Size == B->Vector.Size);
  vector *Vector1 = &A->Vector;
  vector *Vector2 = &B->Vector;
  vector VectorR = VectorInit(A->Vector.Size);
  for (uint32 ResultIndex = 0;
       ResultIndex < VectorR.Size;
       ++ResultIndex)
  {
    for (uint32 Index = 0;
         Index < VectorR.Size;
         ++Index)
    {
      VectorR.Elements[ResultIndex] = VectorR.Elements[ResultIndex] + 
        (Vector1->Elements[((-1 * (int32) Index) + Vector1->Size) % Vector1->Size] * 
         Vector2->Elements[(Index + ResultIndex) % Vector2->Size]);
    }
  }
  matrix_cyclic Result = {VectorR};
  return(Result);
}


internal vector 
MatrixCyclicMultiply(matrix_cyclic *A, vector *B)
{
  Assert(A->Vector.Size == B->Size);
  vector *Vector1 = &A->Vector;
  vector *Vector2 = B;
  vector VectorR = VectorInit(A->Vector.Size);
  for (uint32 ResultIndex = 0;
       ResultIndex < VectorR.Size;
       ++ResultIndex)
  {
    for (uint32 Index = 0;
         Index < VectorR.Size;
         ++Index)
    {
      VectorR.Elements[ResultIndex] = VectorR.Elements[ResultIndex] + 
        (Vector1->Elements[(Vector1->Size + Index - ResultIndex) % Vector1->Size] 
         * Vector2->Elements[Index]);
    }
  }
  return(VectorR);
}

//  COMPLEX OPERATIONS /////////////////////////////////////////////////////
internal matrix_cyclic 
MatrixCyclicPower(matrix_cyclic *A, int32 Power)
{
  uint32 Length = A->Vector.Size;


  vector DTemp = VectorInit(Length * Length);
  for (uint32 i = 0;
       i < Length;
       ++i)
  {
    for (uint32 j = 0;
         j < Length;
         ++j)
    {
      for (uint32 Element = 0;
           Element < Length;
           ++Element)
      {
        complex_number E1 = ComplexNumberConjugate(FourierMatrixNormalizedElement(Length, i, Element));
        complex_number E2 = MatrixCyclicGetElement(A, Element, j);
        DTemp.Elements[(i * Length) + j] = 
          DTemp.Elements[(i * Length) + j] + (E1 * E2);
      }
    }
  }

  vector D = VectorInit(Length * Length);
  for (uint32 i = 0;
       i < Length;
       ++i)
  {
    for (uint32 j = 0;
         j < Length;
         ++j)
    {
      for (uint32 Element = 0;
           Element < Length;
           ++Element)
      {
        complex_number E1 = FourierMatrixNormalizedElement(Length, j, Element);
        complex_number E2 = DTemp.Elements[(i * Length) + Element];
        D.Elements[(i * Length) + j] = D.Elements[(i * Length) + j] +
          (E1 * E2);
      }
    }
  }

  for (uint32 i = 0;
       i < Length;
       ++i)
  {
    D.Elements[(i * Length) + i] = ComplexNumberIntPower(D.Elements[(i * Length) + i], Power);
  }
  
  vector ResultTemp = VectorInit(Length * Length);
  for (uint32 i = 0;
       i < Length;
       ++i)
  {
    for (uint32 j = 0;
         j < Length;
         ++j)
    {
      for (uint32 Element = 0;
           Element < Length;
           ++Element)
      {
        complex_number E1 = FourierMatrixNormalizedElement(Length, i, Element);
        complex_number E2 = D.Elements[(Element * Length) + j];
        ResultTemp.Elements[(i * Length) + j] = ResultTemp.Elements[(i * Length) + j] +
          (E1 * E2);
      }
    }
  }
  

  matrix_cyclic Result = {VectorInit(Length)};
  for (uint32 j = 0;
       j < Length;
       ++j)
  {
    for (uint32 Element = 0;
         Element < Length;
         ++Element)
    {
      complex_number E1 = ResultTemp.Elements[(0 * Length) + Element];
      complex_number E2 = ComplexNumberConjugate(FourierMatrixNormalizedElement(Length, j, Element));
      Result.Vector.Elements[(0 * Length) + j] = Result.Vector.Elements[(0 * Length) + j] +
        (E1 * E2);
    }
  }


  VectorFree(&DTemp);
  VectorFree(&D);
  VectorFree(&ResultTemp);
  return(Result);
}

internal vector
SolveAxEqualsb(matrix_cyclic *A, vector *B)
{
  vector fc = FourierDiscreteTransform(&A->Vector);
  vector b2 = VectorInit(B->Size);
  complex_number b20 = B->Elements[0];
  for (uint32 i = 0;
       i < (B->Size - 1);
       ++i) 
  {
    b2.Elements[i] = B->Elements[i + 1];
  }
  b2.Elements[b2.Size - 1] = b20;
  for (uint32 i = 0;
       i < (B->Size / 2);
       ++i) 
  {
    complex_number t = b2.Elements[i];
    b2.Elements[i] = b2.Elements[b2.Size - 1 - i];
    b2.Elements[b2.Size - 1 - i] = t;
  }
  vector fb = FourierDiscreteTransform(&b2);
  for (uint32 i = 0;
       i < A->Vector.Size;
       ++i) 
  {
    fb.Elements[i] = fb.Elements[i] / fc.Elements[i];
  }
  vector x = FourierDiscreteTransformInverse(&fb);
  VectorFree(&fc);
  VectorFree(&fb);
  return(x);
}


