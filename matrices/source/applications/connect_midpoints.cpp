
#include "connect_midpoints.h"

internal vector 
ConnectMidPoints(vector *A)
{
  vector Result = VectorInit(A->Size);

  for (uint32 i = 0;
       i < A->Size;
       ++i)
  {
    if (i == (A->Size - 1))
    {
      Result.Elements[i] = ((A->Elements[i] + A->Elements[0]) / 2.0);
    }
    else
    {
      Result.Elements[i] = ((A->Elements[i] + A->Elements[i + 1]) / 2.0);
    }
  }

  return(Result);
}

internal vector 
RunConnectMidPoints(vector *Origin, uint32 Steps, 
                    uint32 SaveStep, bool32 Save, bool32 ShowGIF)
{
  vector Vector = VectorInit(Origin->Size);
  if (ShowGIF && (!Save))
  {
    printf("Data has to be saved in order to render a GIF!\n Aborting...");
  }
  else 
  {
    for (uint32 Index = 0;
         Index < Origin->Size; 
         ++Index)
    {
      Vector.Elements[Index] = Origin->Elements[Index];
    }
    for (uint32 Step = 0;
         Step < Steps; 
         ++Step)
    {
      vector Result = ConnectMidPoints(&Vector);
      VectorFree(&Vector);
      Vector = Result;
      if (((Step % SaveStep) == 0) && Save)
      {
        std::string Path = "midpoints/" 
          + std::to_string(Step) + ".csv";
        SaveVector(&Vector, Path);
      }
    }
    if (Save && ShowGIF)
    {
      printf("Rendering GIF, this can take a while...\n");
      system("..\\graph_data\\run.bat midpoints\\ ..\\graph_data\\midpoints\\ true");
    }
  }
  return(Vector);
}


