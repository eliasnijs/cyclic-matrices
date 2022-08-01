#include "test_services.h"

internal bool32 
RunTestSeries(char* SeriesName, test *TestResults, uint32 Size)
{
  printf("\n____________________________________________________________________\n");
  printf("%s\n\n", SeriesName);
  printf("     %-27s   %s\n\n", "Name", "Status");
  uint32 Failed = 0;
  uint32 Index = 0;
  while(Index < Size)
  {
    test *Test = (TestResults + Index);
    bool32 Result = Test->Run();
    printf("%3d. %-27s   %s\n", Index + 1, Test->Name, 
            (Result) ? "SUCCESS" : "FAILED");
    Failed += (uint32) (!Result);
    ++Index;
  }
  printf("\nTest Series completed, %d test(s) succeeded, %d test(s) failed\n", Index - Failed, Failed);
  return(Failed == 0);
}
