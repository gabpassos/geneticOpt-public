#include <stdlib.h>
#include "realreplacement.h"

void realElitistReplacement(realChromosome *dest, realChromosome *src, populationData *population, realReplacementModel *replacement, chromosomeData *chromosome)
{
    int i;

    orderSrcPopulation(src, population->maxIndividuals, replacement->srcPopOrdFunction);

    for(i = 0; i < population->size; i++)
    {
        copyRealChromosome(&dest[i], &src[i], chromosome);
    }
}

int realMinimizationCompare(const void *a, const void *b)
{
    realChromosome *ind1, *ind2;

    ind1 = (realChromosome *) a;
    ind1 = (realChromosome *) a;

    if(ind1->fit < ind2->fit)
    {
        return -1;
    }
    
    else if(ind1->fit > ind2->fit)
    {
        return 1;
    }

    return 0;
}

int realMaximizationCompare(const void *a, const void *b)
{
    realChromosome *ind1, *ind2;

    ind1 = (realChromosome *) a;
    ind1 = (realChromosome *) a;

    if(ind1->fit > ind2->fit)
    {
        return -1;
    }
    
    else if(ind1->fit < ind2->fit)
    {
        return 1;
    }

    return 0;
}

void orderSrcPopulation(realChromosome *src, int srcSize, realCompareFunction *srcPopOrdFunticon)
{
    qsort(src, srcSize, sizeof(realChromosome), srcPopOrdFunticon);
}