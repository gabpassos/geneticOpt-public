#include "realinitialization.h"
#include "stdgen.h"

void realUniformRandomInit(realChromosome *dest, populationData *population, chromosomeData *chromosome)
{
    int i, j;

    for(i = 0; i < population->size; i++)
    {
        for(j = 0; j < chromosome->length; j++)
        {
            dest[i].gene[j] = uniform(chromosome->infLimit[j], chromosome->supLimit[j]);
        }

        dest[i].evaluated = False;
        dest[i].generation = 0;
    }
}