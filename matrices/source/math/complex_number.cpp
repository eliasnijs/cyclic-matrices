
#include "complex_number.h"

global_variable complex_number ComplexI = {0.0, 0.1};

internal std::string 
ComplexNumberToString(complex_number A)
{
  std::string String = std::to_string(A.Real) + " + " + 
                       std::to_string(A.Imaginary) + "i";
  return(&String[0]);
}

internal complex_number
ComplexNumber(real64 Real, real64 Imaginary)
{
  complex_number C = {Real, Imaginary};
  return(C); 
}

internal complex_number 
ComplexNumberNegative(complex_number A)
{
  complex_number C = {};
  C.Real = -A.Real;
  C.Imaginary = -A.Imaginary;
  return(C);
}

internal complex_number 
ComplexNumberAdd(complex_number A, complex_number B)
{
  complex_number C = {};
  C.Real = (A.Real + B.Real);
  C.Imaginary = (A.Imaginary + B.Imaginary);
  return(C);
}

internal complex_number 
ComplexNumberSubtract(complex_number A, complex_number B)
{
  complex_number C = {};
  C.Real = (A.Real - B.Real);
  C.Imaginary = (A.Imaginary - B.Imaginary);
  return(C);
}

internal complex_number 
ComplexNumberMultiply(complex_number A, complex_number B)
{
  complex_number C = {};
  C.Real = ((A.Real * B.Real) - (A.Imaginary * B.Imaginary));
  C.Imaginary = ((A.Real * B.Imaginary) + (A.Imaginary * B.Real));
  return(C);
}

internal complex_number 
ComplexNumberDivide(complex_number A, complex_number B)
{
  complex_number C = {};
  real64 denominator = (pow(B.Real, 2) + pow(B.Imaginary, 2));
  C.Real = (((A.Real * B.Real) + (A.Imaginary * B.Imaginary)) / (denominator));
  C.Imaginary = (((A.Imaginary * B.Real) - (A.Real * B.Imaginary)) / (denominator));
  return(C);
}

internal inline bool32 
ComplexNumberEquals(complex_number A, complex_number B, real64 Delta)
{
  return((abs(A.Real - B.Real) < Delta) && (abs(A.Imaginary - B.Imaginary) < Delta));
}

internal complex_number 
ComplexNumberIntPower(complex_number A, int32 m)
{
  real64 Rm = pow((sqrt(pow(A.Real, 2) + pow(A.Imaginary, 2))), m);
  real64 Om = (atan(A.Imaginary / A.Real) * m);
  complex_number Result = {Rm * cos(Om), Rm * sin(Om)};
  return(Result);
}

internal complex_number
ComplexNumberConjugate(complex_number A)
{
  complex_number Result = {A.Real, -1.0 * A.Imaginary};
  return(Result);
}

