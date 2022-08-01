
#include <stdio.h>
#include "complex_number.h"


internal vector
VectorInit(uint32 Size)
{
  vector Vector = {};
  Vector.Size = Size;
  Vector.Elements = (complex_number *) calloc(Size, sizeof(complex_number));
  if (!Vector.Elements)
  {
    Vector.Elements = 0;
  }
  return Vector;
}

internal void 
VectorFree(vector *Vector)
{
  free(Vector->Elements);
}

internal vector
VectorRandom(uint32 Dim1, uint32 Dim2)
{
  // TODO (Elias): make size a parameter
  vector Vector = VectorInit(420);
  for (uint32 i = 0;
       i < Vector.Size; 
       ++i)
  {
    real64 v1 = ((real64) (rand() % Dim1 + 1));
    real64 v2 = ((real64) (rand() % Dim2 + 1));
    Vector.Elements[i] = {v1, v2};
  }
  return(Vector);
}

internal complex_number 
VectorGetElement(vector *Vector, uint32 Index)
{
  Assert(Index < Vector->Size);
  return Vector->Elements[Index];
}

internal vector
VectorNegative(vector *Vector)
{
  vector ResultVector = VectorInit(Vector->Size);
  
  complex_number *ResultElement = (complex_number *) ResultVector.Elements;
  complex_number *VectorElement = (complex_number *) Vector->Elements;
  for (uint32 i = 0; 
       i < Vector->Size;
       ++i) 
  {
    *ResultElement++ = -(*VectorElement++);
  }

  return(ResultVector);
}

internal vector 
VectorScale(complex_number Scalar, vector *Vector)
{
  vector ResultVector = VectorInit(Vector->Size);
  
  complex_number *ResultElement = (complex_number *) ResultVector.Elements;
  complex_number *VectorElement = (complex_number *) Vector->Elements;
  for (uint32 i = 0; 
       i < Vector->Size;
       ++i) 
  {
    *ResultElement++ = Scalar * (*VectorElement++); 
  }

  return(ResultVector);
}

internal vector 
VectorSum(vector *Vector1, vector *Vector2)
{
  vector ResultVector = VectorInit(Vector1->Size);
  
  complex_number *ResultElement = (complex_number *) ResultVector.Elements;
  complex_number *Vector1Element = (complex_number *) Vector1->Elements;
  complex_number *Vector2Element = (complex_number *) Vector2->Elements;
  for (uint32 i = 0; 
       i < ResultVector.Size;
       ++i) 
  {
    *ResultElement = Vector1Element[i] + Vector2Element[i];
    ResultElement++;
  }
  
  return(ResultVector);
}

// TODO (Elias): Change behaviour to take larges or give an error
internal vector 
VectorSubtract(vector *Vector1, vector *Vector2)
{
  vector ResultVector = VectorInit(Vector1->Size);
  
  complex_number *ResultElement = (complex_number *) ResultVector.Elements;
  complex_number *Vector1Element = (complex_number *) Vector1->Elements;
  complex_number *Vector2Element = (complex_number *) Vector2->Elements;
  for (uint32 i = 0; 
       i < ResultVector.Size;
       ++i) 
  {
    *ResultElement++ = (*Vector1Element++) - (*Vector2Element++);
  }

  return(ResultVector);
}

internal bool32
VectorEqual(vector *Vector1, vector *Vector2)
{
  bool32 Result = true;
  if (Vector1->Size == Vector2->Size)
  {
    for (uint32 i = 0; 
         Result && i < Vector1->Size;
         ++i ) 
    {
      Result = (Vector1->Elements[i] == Vector2->Elements[i]);
    }
  } 
  else 
  {
    Result = false;
  }
  return(Result);
}

internal bool32 
VectorAllNull(vector *Vector)
{
  complex_number ZeroComplex = {};
  bool32 Result = true;
  complex_number *VectorElement = (complex_number *) Vector->Elements;
  for (uint32 i = 0; 
       Result && i < Vector->Size;
       ++i) 
  {
    Result = ((*VectorElement++) == ZeroComplex);
  }
  return(Result);
}

internal std::string 
VectorToString(vector *Vector)
{
  std::string String = "[ ";
  for (uint32 i = 0; 
       i < (Vector->Size - 1);
       ++i) 
  {
    String += ComplexNumberToString(Vector->Elements[i]) + ", ";
  }
  String += ComplexNumberToString(Vector->Elements[Vector->Size - 1]) + " ]";
  return(String);
}


internal std::string 
VectorToString(vector *Vector, uint32 breakPoint)
{
  std::string String = "[ ";
  for (uint32 i = 0; 
       i < (Vector->Size);
       ++i) 
  {
    if ((i % (breakPoint)) == 0)
    {
      String += "\n";
    }
    String += ComplexNumberToString(Vector->Elements[i]) + ", ";
  }
  String += ComplexNumberToString(Vector->Elements[Vector->Size - 1]) + " ]";
  return(String);
}

internal void
SaveVector(vector *Vector, std::string Path)
{
  FILE* File = fopen(&Path[0], "wb");
  for (uint32 i = 0;
       i < Vector->Size; 
       ++i)
  {
    complex_number X = Vector->Elements[i];
    fprintf(File, "%f,%f\n", X.Real, X.Imaginary);
  }
  fclose(File);
}




