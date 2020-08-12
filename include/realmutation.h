#ifndef REALMUTATION_H_DEFINED
#define REALMUTATION_H_DEFINED

#include "stdgen.h"

typedef void realMutationFunction();

typedef struct realmutationmodel
{
    char type[MAX_TYPE_STRLEN];
    realMutationFunction *function;
    double prob;
}realMutationModel;

#endif