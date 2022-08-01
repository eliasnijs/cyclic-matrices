#if !defined(CONNECT_MIDPOINTS_H)


internal vector 
ConnectMidPoints(vector *A);

internal vector 
RunConnectMidPoints(vector *Origin, uint32 Steps, 
                    uint32 SaveStep, bool32 Save);

#define CONNCECT_MIDPOINTS_H
#endif
