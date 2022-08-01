#if !defined(MATRICES_H)

#if MATRICES_SLOW 
#define Assert(Expression) if(!(Expression)) {*(int *) 0 = 0;}
#else
#define Assert(Expression)
#endif

#define ArrayCount(Array) (sizeof(Array) / sizeof((Array)[0]))

internal void
Run();

#define MATRICES_H
#endif
