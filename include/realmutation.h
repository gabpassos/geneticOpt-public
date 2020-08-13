#ifndef REALMUTATION_H_DEFINED
#define REALMUTATION_H_DEFINED

#include "stdgen.h"

typedef void realMutationFunction(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome);

typedef struct realmutationmodel
{
    char type[MAX_TYPE_STRLEN];
    realMutationFunction *function;
    double prob;
    double alleleMutProb;
    double **limit;
} realMutationModel;

void realTotalUniformRandomMutation(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome);
void realUniformRandomMutation(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome);

#endif