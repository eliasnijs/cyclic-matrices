#include <stdint.h>
#include <math.h>
#include <string>

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef float real32;
typedef double real64;

#include <stdio.h>
#include <iostream>
#include <cstdlib>


#define internal static 
#define local_persist static
#define global_variable static 

#define Pi64 3.14159265358979323846

#include "matrices.h"

#include "math/complex_number.h"
#include "math/complex_number.cpp"
#include "math/vector.h"
#include "math/vector.cpp"
#include "math/matrix_cyclic.h"
#include "math/matrix_cyclic.cpp"
#include "math/fourier.h"
#include "math/fourier.cpp"

#include "applications/connect_midpoints.h"
#include "applications/connect_midpoints.cpp"
#include "applications/waves.h"
#include "applications/waves.cpp"

#include "tests/test_services.h"
#include "tests/test_services.cpp"
#include "tests.cpp"


int32 main()
{
  RunTests();


#if 0
  uint32 StartSize = 8;
  uint32 MaxSize = 64;
  uint32 StepSize = 16;
  
  uint32 StartRadius = 8;
  uint32 MaxRadius = 40;
  uint32 StepRadius = 10;

  uint32 Steps = 0;
  for (uint32 n = StartSize;
       n <= MaxSize;
       n += StepSize)
  {
    for (uint32 r = StartRadius;
         r <= MaxRadius;
         ++r += StepRadius)
    {
      printf("%2d/%2d\t", Steps,
             ((MaxRadius / StepRadius) *
               (MaxSize / StepSize)));
      vector Start = VectorInit(n);
      for (uint32 x = 0;
           x < Start.Size;
           ++x)
      {
        Start.Elements[x] = {cos(x * 0.3), 0};
      }
      RunWaveSimulation(
/*startvector:  */  &Start, 
/*delta time:   */  0.03, 
/*radius:       */  r, 
/*Steps:        */  10000, 
/*Save?:        */  true, 
/*Name:         */  "wave_" + std::to_string(n) + "_" 
                            + std::to_string(r) + ".gif",
/*SaveStep:     */  100, 
/*MakeGif?:     */  true 
      );
      ++Steps;
    }
  }
#endif

  return(0);
  }







