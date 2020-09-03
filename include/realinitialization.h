#ifndef REALINITIALIZATION_H_INCLUDED
#define REALINITIALIZATION_H_INCLUDED

#include "stdgen.h"

typedef enum realinittype
{
    realInit_type_undef = 0,
    realUniformRandomInitType = 1,
    userSetInitType = 2
} realInitType;

typedef void initializationFunction(realChromosome *dest, populationData *population, chromosomeData *chromosome);

typedef struct realinitializationmodel
{
    realInitType type;
    initializationFunction *function;
} realInitializationModel;

void realUniformRandomInit(realChromosome *dest, populationData *population, chromosomeData *chromosome);
#endif
