#ifndef REALMUTATION_H_DEFINED
#define REALMUTATION_H_DEFINED

#include "stdgen.h"

typedef enum realmutationtype
{
    realMut_type_undef = 0,
    realTotalUniformRandom = 1,
    realUniformRandom = 2,
} realMutationType;

typedef void realMutationFunction(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome);

typedef struct realmutationmodel
{
    char *type;
    realMutationFunction *function;
    double prob;
    double alleleMutProb;
    double **limit;
} realMutationModel;

void realTotalUniformRandomMutation(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome);
void realUniformRandomMutation(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome);

#endif
