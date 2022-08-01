
#include "waves.h"

internal vector
WaveSimulationStep(vector *hc, vector *hp, matrix_cyclic *A)
{
  vector hn = VectorInit(hc->Size);

  // calculate right side of the equation
  vector b = VectorInit(hc->Size);
  for (uint32 i = 0;
       i < hc->Size; 
       ++i)
  {
    b.Elements[i] = (hp->Elements[i] - (2 * hc->Elements[i]));
  }
  // Use function to calculate Ax = b
  vector x = SolveAxEqualsb(A, &b);
  // printf("b = %s\n", &VectorToString(&b)[0]);

  VectorFree(&b);
  return(x);
}

internal void
SaveWaveState(vector *Wave, std::string Path)
{
  FILE* File = fopen(&Path[0], "wb");
  for (uint32 i = 0;
       i < Wave->Size; 
       ++i)
  {
    complex_number X = Wave->Elements[i];
    fprintf(File, "%d,%f\n", i, X.Real);
  }
  fclose(File);
}


internal vector 
RunWaveSimulation(vector *Origin,
                  real64 dt, real64 r, uint32 Steps,
                  bool32 Save, std::string Name,
                  uint32 SaveStep, bool32 MakeGIF)
{
  Assert(Origin->Size >= 4);
  printf("%s\n", &Name[0]);
  // calculate deltax for radius
  complex_number w = FourierMatrixElement(Origin->Size, 1, 1);
  w.Real = r * w.Real; 
  w.Imaginary = r * w.Imaginary; 
  // printf("w  = %s\n", &ComplexNumberToString(w)[0]);
  real64 dx = sqrt(pow((w.Real - r), 2) + pow((w.Imaginary - 0), 2));
  // calculate g
  real64 g = (pow(dt, 2) / pow(dx, 2));
  // printf("dx = %f\n", dx);
  // printf("dt = %f\n", dt);
  // printf("g  = %f\n", g);
  // make matrix (gA - I)
  vector a = VectorInit(Origin->Size);
  a.Elements[0] = {((g * (-30.0 / 12)) - 1), 0.0};
  a.Elements[1] = {(g * (16.0 / 12)), 0.0};
  a.Elements[2] = {(g * (-1.0 / 12)), 0.0};
  a.Elements[Origin->Size-2] = {(g * (-1.0 / 12)), 0.0};
  a.Elements[Origin->Size-1] = {(g * (16.0 / 12)), 0.0};
  matrix_cyclic A = {a};

  // printf("A = %s\n", &VectorToString(&a)[0]);
  vector hc = VectorInit(Origin->Size);
  if (MakeGIF && (!Save))
  {
    printf("Data has to be saved in order to render a GIF!\n Aborting...");
  }
  else 
  {
    system("del /Q waves\\*");
    system("del /Q ..\\graph_data\\waves\\images\\");
    vector hp = VectorInit(Origin->Size);
    // load start data
    for (uint32 i = 0;
         i < Origin->Size; 
         ++i)
    {
      hc.Elements[i] = Origin->Elements[i];
      hp.Elements[i] = Origin->Elements[i];
    }
    // run simulation
    for (uint32 Step = 0;
         Step < Steps; 
         ++Step)
    {
      // printf("x = %s\n", &VectorToString(&hc)[0]);
      if (((Step % SaveStep) == 0) && Save)
      {
        SaveWaveState(&hc, "waves/" + std::to_string(Step) + ".csv");
      }
      vector hn = WaveSimulationStep(&hc, &hp, &A);
      VectorFree(&hp);
      hp = hc;
      hc = hn;
    }
    if (Save)
    {
      SaveWaveState(&hc, "waves/" + std::to_string(Steps) + ".csv");
    }

    // printf("x = %s\n", &VectorToString(&hc)[0]);
    if (Save && MakeGIF)
    {
      std::string command = "..\\graph_data\\run.bat " 
                          + Name
                          + " waves\\ ..\\graph_data\\waves\\";
      system(&command[0]);
    }
    VectorFree(&hp);
  }

  // calculate mean check

  VectorFree(&a);
  return(hc);
}



