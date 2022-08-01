
#include "../math/vector.h"
#include "../math/fourier.h"

internal vector
WaveSimulationStep(vector *hc, vector *hp);
internal vector 
RunWaveSimulation(vector *Origin, 
                  real64 DeltaT, real64 Radius, uint32 Steps,
                  bool32 Save, std::string Name,
                  uint32 SaveStep, bool32 MakeGIF);


