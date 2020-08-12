#include "stdgen.h"

void copyRealChromosome(realChromosome *dest, realChromosome *src, chromosomeData *chromosome)
{
    int i;

    dest->fit = src->fit;
    dest->evaluated = src->evaluated;
    dest->generation = src->generation;

    for(i = 0; i < chromosome->length; i++)
    {
        dest->gene[i] = src->gene[i];
    }    
}