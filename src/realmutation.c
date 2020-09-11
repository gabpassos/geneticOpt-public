#include "stdmath.h"
#include "realmutation.h"
#include "stdgen.h"

void realTotalUniformRandomMutation(realChromosome *totalPopulation, populationData *population, realMutationModel *mutation, chromosomeData *chromosome)
{
    int i, j;
    double prob;

    for(i = 0; i < population->totalChildren; i++)
    {
        prob = uniform(0, 1);
        if(prob < mutation->prob)
        {
            for(j = 0; j < chromosome->length; j++)
            {
                totalPopulation[i].gene[j] = uniform(mutation->limit[j][0], mutation->limit[j][1]);
            }
        }
    }
}

void realUniformRandomMutation(realChromosome *totalPopulation, populationData *population, realMutationModel *mutation, chromosomeData *chromosome)
{
    int i, j;
    double prob;

    for(i = 0; i < population->totalChildren; i++)
    {
        prob = uniform(0, 1);
        if(prob < mutation->prob)
        {
            for(j = 0; j < chromosome->length; j++)
            {
                prob = uniform(0, 1);
                if(prob < mutation->alleleMutProb)
                {
                    totalPopulation[i].gene[j] = totalPopulation[i].gene[j] + uniform(mutation->limit[j][0], mutation->limit[j][1]);
                }
            }
        }
    }
}
