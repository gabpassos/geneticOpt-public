#ifndef REALMUTATION_H_DEFINED
#define REALMUTATION_H_DEFINED

#include "stdgen.h"

#define DEFAULT_UNIFORMMUT_LIMIT 0.1

typedef struct realmutationmodel realMutationModel;

typedef enum realmutationtype
{
    realMut_type_undef = 0,
    realTotalUniformRandomMutationType = 1,
    realUniformRandomMutationType = 2,
} realMutationType;

typedef void realMutationFunction(realChromosome *totalPopulation, populationData *population, realMutationModel *mutation, chromosomeData *chromosome);

typedef struct realmutationmodel
{
    realMutationType type;
    realMutationFunction *function;
    double prob;
    double alleleMutProb;
    double **limit;
} realMutationModel;

void realTotalUniformRandomMutation(realChromosome *totalPopulation, populationData *population, realMutationModel *mutation, chromosomeData *chromosome);
void realUniformRandomMutation(realChromosome *totalPopulation, populationData *population, realMutationModel *mutation, chromosomeData *chromosome);

#endif
