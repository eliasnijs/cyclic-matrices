#if !defined(TEST_SERVICES_H)


// NOTE (Elias): This struct exists so the ouput of a test will appear
// in the rightplace when printing to the terminal.
struct test
{
  char* Name;
  bool32 (*Run) ();
};

internal bool32 
RunTestSeries(char* name, bool32 *TestResults);

#define TEST_SERVICES_H
#endif
