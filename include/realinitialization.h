#ifndef REALINITIALIZATION_H_INCLUDED
#define REALINITIALIZATION_H_INCLUDED

#include "stdgen.h"

typedef void initializationFunction(realChromosome *dest, populationData *population, chromosomeData *chromosome);

typedef struct realinitializationmodel
{
    char *type;
    initializationFunction *function;
} realInitializationModel;
#endif