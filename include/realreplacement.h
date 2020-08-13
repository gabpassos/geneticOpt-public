#ifndef REALREPLACEMENT_H_INCLUDED
#define REALREPLACEMENT_H_INCLUDED

#include "stdgen.h"

typedef void realReplacementFunction(realChromosome *dest, realChromosome *src, populationData *population, realReplacementModel *replacement, chromosomeData *chromosome);
typedef int realCompareFunction(const void *a, const void *b);

typedef struct realreplacementmodel
{
    char type[MAX_TYPE_STRLEN];
    realReplacementFunction *function;
    realCompareFunction *srcPopOrdFunction;
} realReplacementModel;

void realElitistReplacement(realChromosome *dest, realChromosome *src, populationData *population, realReplacementModel *replacement, chromosomeData *chromosome);
int realMinimizationCompare(const void *a, const void *b);
int realMaximizationCompare(const void *a, const void *b);
void orderSrcPopulation(realChromosome *src, int srcSize, realCompareFunction *srcPopOrdFunticon);

#endif