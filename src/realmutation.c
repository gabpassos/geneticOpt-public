#include "stdmath.h"
#include "realmutation.h"
#include "stdgen.h"

void realTotalUniformRandomMutation(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome)
{
    int i;
    double prob;

    prob = uniform(0, 1);
    if(prob < mutation->prob)
    {
        ind->evaluated = False;

        for(i = 0; i < chromosome->length; i++)
        {
            ind->gene[i] = uniform(mutation->limit[i][0], mutation->limit[i][1]);
        }
    }
}

void realUniformRandomMutation(realChromosome *ind, realMutationModel *mutation, chromosomeData *chromosome)
{
    int i;
    double prob;

    prob = uniform(0, 1);
    if(prob < mutation->prob)
    {
        ind->evaluated = False;

        for(i = 0; i < chromosome->length; i++)
        {
            prob = uniform(0, 1);
            if(prob < mutation->alleleMutProb)
            {
                ind->gene[i] = ind->gene[i] + uniform(mutation->limit[i][0], mutation->limit[i][1]);
            }
        }
    }
}