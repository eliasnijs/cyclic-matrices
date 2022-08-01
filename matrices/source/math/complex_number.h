#if !defined(COMPLEXNUMBERS_H)

struct complex_number
{
  real64 Real;
  real64 Imaginary;
};

internal complex_number
ComplexNumber(real64 Real, real64 Imaginary);

internal complex_number 
ComplexNumberNegative(complex_number A);

internal complex_number 
ComplexNumberAdd(complex_number A, complex_number B);

internal complex_number 
ComplexNumberSubtract(complex_number A, complex_number B);

internal complex_number 
ComplexNumberMultiply(complex_number A, complex_number B);

internal complex_number 
ComplexNumberDivide(complex_number A, complex_number B);

internal complex_number 
ComplexNumberIntPower(complex_number A, int32 m);

internal bool32 
ComplexNumberEquals(complex_number A, complex_number B, real64 Delta);

internal complex_number
ComplexNumberConjugate(complex_number A);

internal std::string 
ComplexNumberToString(complex_number A);

internal inline complex_number 
operator-(complex_number A)
{
  return(ComplexNumberNegative(A));
}

internal inline complex_number 
operator+(complex_number A, complex_number B)
{
  return(ComplexNumberAdd(A, B));
}

internal inline complex_number 
operator+(real64 A, complex_number B)
{
  complex_number C = {A, 0.0};
  return(ComplexNumberAdd(C, B));
}

internal inline complex_number 
operator-(complex_number A, complex_number B)
{
  return(ComplexNumberSubtract(A, B));
}

internal inline complex_number 
operator*(real64 A, complex_number B)
{
  complex_number C = {A, 0.0};
  return(ComplexNumberMultiply(C, B));
}

internal inline complex_number 
operator*(complex_number A, complex_number B)
{
  return(ComplexNumberMultiply(A, B));
}

internal inline complex_number 
operator/(complex_number A, complex_number B)
{
  return(ComplexNumberDivide(A, B));
}

internal inline complex_number 
operator/(complex_number A, real64 B)
{
  complex_number C = {(real64) B, 0};
  return(ComplexNumberDivide(A, C));
}

internal inline bool32 
operator==(complex_number A, complex_number B)
{
  return(ComplexNumberEquals(A, B, 0.00000001));
}

#define COMPLEXNUMBERS_H
#endif
