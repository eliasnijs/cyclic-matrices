//{TESTCOMPILINGSTART}
//{TESTCOMPILING: COMPLEX NUMBERS}
internal bool32 
TestComplexAddition1()
{
  complex_number A = {3.0, -9.0};
  complex_number B = {1.0, 4.0};
  complex_number C = A + B; 
  complex_number Expected = {4.0, -5.0};
  return(C == Expected);
}

internal bool32 
TestComplexSubtraction1()
{
  complex_number A = {3.0, -9.0};
  complex_number B = {1.0, 4.0};
  complex_number C = A - B; 
  complex_number Expected = {2.0, -13.0};
  return(C == Expected);
}

internal bool32 
TestComplexMultiplication1()
{
  complex_number A = {3.0, -9.0};
  complex_number B = {1.0, 4.0};
  complex_number C = A * B; 
  complex_number Expected = {39.0, 3.0};
  return(C == Expected);
}

internal bool32 
TestComplexDivision1()
{
  complex_number A = {3.0, -9.0};
  complex_number B = {1.0, 4.0};
  complex_number C = A / B; 
  complex_number Expected = {-1.94117647, -1.23529412};
  return(Expected == C);
}

internal bool32 
TestComplexIntPower1()
{
  complex_number A = {3.0, -9.0};
  complex_number Result = ComplexNumberIntPower(A, 3);
  return(true);
}

//{TESTCOMPILING: VECTOR}
internal bool32
TestVectorCreate1()
{
  vector Vector = VectorInit(3);
  Vector.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector.Elements[2] = ComplexNumber(1.0, 4.0);
 
  bool32 Success = (Vector.Elements != 0);
  VectorFree(&Vector);
  return Success; 
}

internal bool32
TestVectorGetElement1()
{
  vector Vector = VectorInit(3);
  Vector.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector.Elements[2] = ComplexNumber(1.0, 4.0);
 
  bool32 Success1 = (ComplexNumber(1.0, 2.0) == VectorGetElement(&Vector, 0));
  bool32 Success2 = (ComplexNumber(3.0, 2.0) == VectorGetElement(&Vector, 1));
  bool32 Success3 = (ComplexNumber(1.0, 4.0) == VectorGetElement(&Vector, 2));
  
  VectorFree(&Vector);
  return(Success1 && Success2 && Success3);
}

internal bool32
TestVectorNegative1()
{
  vector Vector = VectorInit(3);
  Vector.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector.Elements[2] = ComplexNumber(1.0, 4.0);
  vector VectorNegative = -Vector;
  
  bool32 Success1 = (ComplexNumber(-1.0, -2.0) == VectorGetElement(&VectorNegative, 0));
  bool32 Success2 = (ComplexNumber(-3.0, -2.0) == VectorGetElement(&VectorNegative, 1));
  bool32 Success3 = (ComplexNumber(-1.0, -4.0) == VectorGetElement(&VectorNegative, 2));

  VectorFree(&Vector);
  VectorFree(&VectorNegative);
  return(Success1 && Success2 && Success3);
}

internal bool32
TestVectorScale1()
{
  vector Vector1 = VectorInit(3);
  Vector1.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector1.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector1.Elements[2] = ComplexNumber(1.0, 4.0);

  complex_number C = {2.0, 0.0};

  vector Vector2 = C * Vector1;
  
  vector Expected = VectorInit(3);
  Expected.Elements[0] = ComplexNumber(2.0, 4.0);
  Expected.Elements[1] = ComplexNumber(6.0, 4.0);
  Expected.Elements[2] = ComplexNumber(2.0, 8.0);
  
  bool32 Success = (Expected == Vector2);

  VectorFree(&Vector1);
  VectorFree(&Vector2);
  VectorFree(&Expected);
  
  return(Success);
}

internal bool32
TestVectorSum1()
{
  vector Vector1 = VectorInit(3);
  Vector1.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector1.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector1.Elements[2] = ComplexNumber(1.0, 4.0);
  
  vector Vector2 = VectorInit(3);
  Vector2.Elements[0] = ComplexNumber(1.0, 3.0);
  Vector2.Elements[1] = ComplexNumber(3.0, 5.0);
  Vector2.Elements[2] = ComplexNumber(8.0, 4.0);

  vector Vector3 = Vector1 + Vector2;
 
  vector Expected = VectorInit(3);
  Expected.Elements[0] = ComplexNumber(2.0, 5.0);
  Expected.Elements[1] = ComplexNumber(6.0, 7.0);
  Expected.Elements[2] = ComplexNumber(9.0, 8.0);
  
  bool32 Success = (Expected == Vector3);

  VectorFree(&Vector1);
  VectorFree(&Vector2);
  VectorFree(&Vector3);
  VectorFree(&Expected);
  
  return(Success);
}

internal bool32
TestVectorSubtract1()
{
  vector Vector1 = VectorInit(3);
  Vector1.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector1.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector1.Elements[2] = ComplexNumber(1.0, 4.0);
  
  vector Vector2 = VectorInit(3);
  Vector2.Elements[0] = ComplexNumber(1.0, 3.0);
  Vector2.Elements[1] = ComplexNumber(3.0, 5.0);
  Vector2.Elements[2] = ComplexNumber(9.0, 4.0);

  vector Vector3 = Vector1 - Vector2;
 
  vector Expected = VectorInit(3);
  Expected.Elements[0] = ComplexNumber(0.0, -1.0);
  Expected.Elements[1] = ComplexNumber(0.0, -3.0);
  Expected.Elements[2] = ComplexNumber(-8.0, 0.0);
  
  bool32 Success = (Expected == Vector3);

  VectorFree(&Vector1);
  VectorFree(&Vector2);
  VectorFree(&Expected);
  
  return(Success);
}

internal bool32
TestVectorEqual1()
{
  vector Vector1 = VectorInit(3);
  Vector1.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector1.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector1.Elements[2] = ComplexNumber(1.0, 4.0);
  
  vector Vector2 = VectorInit(3);
  Vector2.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector2.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector2.Elements[2] = ComplexNumber(1.0, 4.0);
 
  bool32 Success = (Vector1 == Vector2);

  VectorFree(&Vector1);
  VectorFree(&Vector2);
  return(Success);
}

internal bool32
TestVectorEqual2()
{
  vector Vector1 = VectorInit(3);
  Vector1.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector1.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector1.Elements[2] = ComplexNumber(1.0, 4.0);
  
  vector Vector2 = VectorInit(3);
  Vector2.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector2.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector2.Elements[2] = ComplexNumber(2.0, 4.0);
  
  bool32 Success = !(Vector1 == Vector2);
  
  VectorFree(&Vector1);
  VectorFree(&Vector2);
  return(Success);
}

internal bool32
TestVectorAllNull1()
{
  vector Vector = VectorInit(3);
  bool32 Success = VectorAllNull(&Vector);
  VectorFree(&Vector);
  return(Success);
}

internal bool32
TestVectorAllNull2()
{
  vector Vector = VectorInit(3);
  Vector.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector.Elements[2] = ComplexNumber(1.0, 4.0);
  bool32 Success = !VectorAllNull(&Vector);
  VectorFree(&Vector);
  return(Success);
}

//{TESTCOMPILING: CYCLICMATRIX}
internal bool32
TestCyclicMatrixString()
{
  
  vector Vector = VectorInit(3);
  Vector.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector.Elements[2] = ComplexNumber(1.0, 4.0);
  
  matrix_cyclic Matrix = {Vector};

  std::string String = MatrixCyclicToString(&Matrix);

  std::string Expected = "[\n\
   [ 1.000000 + 2.000000i, 3.000000 + 2.000000i, 1.000000 + 4.000000i,],\n\
   [ 1.000000 + 4.000000i, 1.000000 + 2.000000i, 3.000000 + 2.000000i,],\n\
   [ 3.000000 + 2.000000i, 1.000000 + 4.000000i, 1.000000 + 2.000000i,],\n]";


  VectorFree(&Matrix.Vector);
  return(Expected == String);
}

internal bool32
TestCyclicMatrixGet1()
{
  
  vector Vector = VectorInit(3);
  Vector.Elements[0] = ComplexNumber(1.0, 2.0);
  Vector.Elements[1] = ComplexNumber(3.0, 2.0);
  Vector.Elements[2] = ComplexNumber(1.0, 4.0);
  matrix_cyclic M = {Vector};
  
  complex_number Expected0 = ComplexNumber(1.0, 2.0);
  complex_number Expected1 = ComplexNumber(3.0, 2.0);
  complex_number Expected2 = ComplexNumber(1.0, 4.0);
  
  bool32 Result = (Expected2 ==  MatrixCyclicGetElement(&M, 0, 2));
  Result = Result && (Expected2 ==  MatrixCyclicGetElement(&M, 1, 0));
  Result = Result && (Expected0 ==  MatrixCyclicGetElement(&M, 2, 2));

  VectorFree(&M.Vector);
  return(Result);
}

internal bool32
TestCyclicMatrixEquals1()
{
  vector VecA = VectorInit(3);
  VecA.Elements[0] = ComplexNumber(1.0, 2.0);
  VecA.Elements[1] = ComplexNumber(3.0, 2.0);
  VecA.Elements[2] = ComplexNumber(1.0, 4.0);
  matrix_cyclic A = {VecA};
  
  vector VecB = VectorInit(3);
  VecB.Elements[0] = ComplexNumber(1.0, 2.0);
  VecB.Elements[1] = ComplexNumber(3.0, 2.0);
  VecB.Elements[2] = ComplexNumber(1.0, 4.0);
  matrix_cyclic B = {VecB};
  
  bool32 Result = (A == B);

  VectorFree(&A.Vector);
  VectorFree(&B.Vector);
  return(Result);
}

internal bool32
TestCyclicMatrixEquals2()
{
  vector VecA = VectorInit(3);
  VecA.Elements[0] = ComplexNumber(1.0, 2.0);
  VecA.Elements[1] = ComplexNumber(3.0, 2.0);
  VecA.Elements[2] = ComplexNumber(1.0, 4.0);
  matrix_cyclic A = {VecA};
  
  vector VecB = VectorInit(3);
  VecB.Elements[0] = ComplexNumber(1.0, 2.0);
  VecB.Elements[1] = ComplexNumber(3.0, 2.0);
  VecB.Elements[2] = ComplexNumber(1.0, 100.0);
  matrix_cyclic B = {VecB};

  bool32 Result = (A != B);

  VectorFree(&A.Vector);
  VectorFree(&B.Vector);
  return(Result);
}

internal bool32
TestCyclicMatrixSum1()
{
  vector VecA = VectorInit(3);
  VecA.Elements[0] = ComplexNumber(0.0, 0.0);
  VecA.Elements[1] = ComplexNumber(1.0, 0.0);
  VecA.Elements[2] = ComplexNumber(3.0, 0.0);
  matrix_cyclic A = {VecA};
  
  vector VecB = VectorInit(3);
  VecB.Elements[0] = ComplexNumber(2.0, 0.0);
  VecB.Elements[1] = ComplexNumber(5.0, 0.0);
  VecB.Elements[2] = ComplexNumber(4.0, 0.0);
  matrix_cyclic B = {VecB};
  
  vector VecC = VectorInit(3);
  VecC.Elements[0] = ComplexNumber(2.0, 0.0);
  VecC.Elements[1] = ComplexNumber(6.0, 0.0);
  VecC.Elements[2] = ComplexNumber(7.0, 0.0);
  matrix_cyclic C = {VecC};

  matrix_cyclic D = {(A + B)};

  bool32 Result = (D == C);

  VectorFree(&A.Vector);
  VectorFree(&B.Vector);
  VectorFree(&C.Vector);
  VectorFree(&D.Vector);
  return(Result);
}

internal bool32
TestCyclicMatrixSubtract1()
{
  vector VecA = VectorInit(3);
  VecA.Elements[0] = ComplexNumber(0.0, 0.0);
  VecA.Elements[1] = ComplexNumber(1.0, 0.0);
  VecA.Elements[2] = ComplexNumber(3.0, 0.0);
  matrix_cyclic A = {VecA};
  
  vector VecB = VectorInit(3);
  VecB.Elements[0] = ComplexNumber(2.0, 0.0);
  VecB.Elements[1] = ComplexNumber(5.0, 0.0);
  VecB.Elements[2] = ComplexNumber(4.0, 0.0);
  matrix_cyclic B = {VecB};
  
  vector VecC = VectorInit(3);
  VecC.Elements[0] = ComplexNumber(-2.0, 0.0);
  VecC.Elements[1] = ComplexNumber(-4.0, 0.0);
  VecC.Elements[2] = ComplexNumber(-1.0, 0.0);
  matrix_cyclic C = {VecC};

  matrix_cyclic D = {(A - B)};

  bool32 Result = (D == C);

  VectorFree(&A.Vector);
  VectorFree(&B.Vector);
  VectorFree(&C.Vector);
  VectorFree(&D.Vector);
  return(Result);
}


internal bool32
TestCyclicMatrixMultiply1()
{
  vector VecA = VectorInit(4);
  VecA.Elements[0] = ComplexNumber(0.0, 0.0);
  VecA.Elements[1] = ComplexNumber(1.0, 0.0);
  VecA.Elements[2] = ComplexNumber(3.0, 0.0);
  VecA.Elements[3] = ComplexNumber(1.0, 0.0);
  matrix_cyclic A = {VecA};
  
  vector VecB = VectorInit(4);
  VecB.Elements[0] = ComplexNumber(2.0, 0.0);
  VecB.Elements[1] = ComplexNumber(5.0, 0.0);
  VecB.Elements[2] = ComplexNumber(4.0, 0.0);
  VecB.Elements[3] = ComplexNumber(1.0, 0.0);
  matrix_cyclic B = {VecB};
  
  matrix_cyclic D = {(A * B)};
  
  vector VecC = VectorInit(4);
  VecC.Elements[0] = ComplexNumber(18.0, 0.0);
  VecC.Elements[1] = ComplexNumber(9.0, 0.0);
  VecC.Elements[2] = ComplexNumber(12.0, 0.0);
  VecC.Elements[3] = ComplexNumber(21.0, 0.0);
  matrix_cyclic C = {VecC};

  bool32 Result = D == C;

  VectorFree(&A.Vector);
  VectorFree(&B.Vector);
  VectorFree(&C.Vector);
  VectorFree(&D.Vector);
  return(Result);
}

internal bool32
TestCyclicMatrixMultiplyWithVector1()
{
  vector VecA = VectorInit(4);
  VecA.Elements[0] = ComplexNumber(0.0, 0.0);
  VecA.Elements[1] = ComplexNumber(1.0, 0.0);
  VecA.Elements[2] = ComplexNumber(3.0, 0.0);
  VecA.Elements[3] = ComplexNumber(5.0, 0.0);
  matrix_cyclic A = {VecA};
  
  vector VecB = VectorInit(4);
  VecB.Elements[0] = ComplexNumber(2.0, 0.0);
  VecB.Elements[1] = ComplexNumber(5.0, 0.0);
  VecB.Elements[2] = ComplexNumber(4.0, 0.0);
  VecB.Elements[3] = ComplexNumber(1.0, 0.0);
  
  vector v = (A * VecB);

  vector Expected = VectorInit(4);
  Expected.Elements[0] = ComplexNumber(22.0, 0.0);
  Expected.Elements[1] = ComplexNumber(17.0, 0.0);
  Expected.Elements[2] = ComplexNumber(32.0, 0.0);
  Expected.Elements[3] = ComplexNumber(37.0, 0.0);

  bool32 Result = (v == Expected);

  VectorFree(&VecB);
  VectorFree(&A.Vector);
  VectorFree(&v);
  VectorFree(&Expected);
  return(Result);
}

internal bool32
TestCyclicPower1()
{
  vector VecA = VectorInit(4);
  VecA.Elements[0] = ComplexNumber(4.0, 0.0);
  VecA.Elements[1] = ComplexNumber(1.0, 0.0);
  VecA.Elements[2] = ComplexNumber(3.0, 0.0);
  VecA.Elements[3] = ComplexNumber(1.0, 0.0);
  matrix_cyclic A = {VecA};
 
  matrix_cyclic Result = MatrixCyclicPower(&A, 3);

  vector VecE = VectorInit(4);
  VecE.Elements[0] = ComplexNumber(214.0, 0.0);
  VecE.Elements[1] = ComplexNumber(151.0, 0.0);
  VecE.Elements[2] = ComplexNumber(213.0, 0.0);
  VecE.Elements[3] = ComplexNumber(151.0, 0.0);
  matrix_cyclic Expected = {VecE};

  bool32 OKAY = (Result == Expected);

  VectorFree(&Result.Vector);
  VectorFree(&A.Vector);
  VectorFree(&Expected.Vector);
  return(OKAY);
}

internal bool32
TestCyclicSolveX()
{
  vector VecA = VectorInit(3);
  VecA.Elements[0] = ComplexNumber(1.0, 0.0);
  VecA.Elements[1] = ComplexNumber(2.0, -1.0);
  VecA.Elements[2] = ComplexNumber(3.0, 0.0);
  matrix_cyclic A = {VecA};

  vector V = VectorInit(3);
  V.Elements[0] = ComplexNumber(4.0, 0.0);
  V.Elements[1] = ComplexNumber(5.0, 0.0);
  V.Elements[2] = ComplexNumber(6.0, 4.0);

  vector Result = SolveAxEqualsb(&A, &V);
  vector BCheck = MatrixCyclicMultiply(&A, &Result);

  bool32 OKAY = (BCheck == V);
  
  VectorFree(&V);
  VectorFree(&A.Vector);
  return(OKAY);
}

//{TESTCOMPILINGEND}
bool32 RunTests()
{
  test TestsCyclicMatrix[] = {
    {"TestCyclicMatrixGet1", &TestCyclicMatrixGet1},
    {"TestCyclicMatrixString", &TestCyclicMatrixString},
    {"TestCyclicMatrixEquals1", &TestCyclicMatrixEquals1},
    {"TestCyclicMatrixEquals2", &TestCyclicMatrixEquals2},
    {"TestCyclicMatrixSum1", &TestCyclicMatrixSum1},
    {"TestCyclicMatrixSubtract1", &TestCyclicMatrixSubtract1},
    {"TestCyclicMatrixMultiply1", &TestCyclicMatrixMultiply1},
    {"TestCyclicMatrixMultiplyWithVector1", &TestCyclicMatrixMultiplyWithVector1},
    {"TestCyclicPower1", &TestCyclicPower1},
    {"TestCyclicSolveX", &TestCyclicSolveX},
  };
  
  test TestsComplex[] = {
    {"TestComplexAddition1",       &TestComplexAddition1},
    {"TestComplexSubtraction1",    &TestComplexSubtraction1},
    {"TestComplexMultiplication1", &TestComplexMultiplication1},
    {"TestComplexDivision1",       &TestComplexDivision1},
    {"TestComplexIntPower1",       &TestComplexIntPower1},
  };
  
  test TestsVector[] = {
    {"TestVectorCreate1",     &TestVectorCreate1},
    {"TestVectorGetElement1", &TestVectorGetElement1},
    {"TestVectorNegative1",   &TestVectorNegative1},
    {"TestVectorScale1",      &TestVectorScale1},
    {"TestVectorSum1",        &TestVectorSum1},
    {"TestVectorSubract1",    &TestVectorSubtract1},
    {"TestVectorEqual1",      &TestVectorEqual1},
    {"TestVectorEqual2",      &TestVectorEqual2},
    {"TestVectorAllNull1",    &TestVectorAllNull1},
    {"TestVectorAllNull2",    &TestVectorAllNull2},
  };
  
  bool32 ComplexTestResults = RunTestSeries("Complex Numbers Test Series", TestsComplex, ArrayCount(TestsComplex));
  bool32 VectorTestResults = RunTestSeries("Vector Test Series", TestsVector, ArrayCount(TestsVector));
  bool32 CyclicMatricesTestResults = RunTestSeries("Cyclic Matrix Test Series", TestsCyclicMatrix, ArrayCount(TestsCyclicMatrix));
  return(
      ComplexTestResults && 
      VectorTestResults && 
      CyclicMatricesTestResults);
}
