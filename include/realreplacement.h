#ifndef REALREPLACEMENT_H_INCLUDED
#define REALREPLACEMENT_H_INCLUDED

#include "stdgen.h"

typedef struct realreplacementmodel realReplacementModel;

typedef enum realreplacementtype
{
    realRepl_type_undef = 0,
    realElitistReplacementType = 1
} realReplacementType;

typedef void realReplacementFunction(realChromosome *dest, realChromosome *src, populationData *population, realReplacementModel *replacement, chromosomeData *chromosome);
typedef int realCompareFunction(const void *a, const void *b);

typedef struct realreplacementmodel
{
    realReplacementType type;
    realReplacementFunction *function;
    realCompareFunction *srcPopOrdFunction;
} realReplacementModel;

void realElitistReplacement(realChromosome *dest, realChromosome *src, populationData *population, realReplacementModel *replacement, chromosomeData *chromosome);
int realMinimizationCompare(const void *a, const void *b);
int realMaximizationCompare(const void *a, const void *b);
void orderSrcPopulation(realChromosome *src, int srcSize, realCompareFunction *srcPopOrdFunticon);

#endif
