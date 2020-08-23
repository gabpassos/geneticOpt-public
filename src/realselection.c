#include "realselection.h"
#include "stdmath.h"

realChromosome* minTournament(tournamentModel *model, realChromosome *srcPopulation)
{
    int i, ind;

    ind = 0;
    for(i = 1; i < model->tourSize; i++)
    {
        if(srcPopulation[model->tourGroup[i]].fit < srcPopulation[model->tourGroup[ind]].fit)
        {
            ind = i;
        }
    }

    return &srcPopulation[ind];
}

realChromosome* maxTournament(tournamentModel *model, realChromosome *srcPopulation)
{
    int i, ind;

    ind = 0;
    for(i = 1; i < model->tourSize; i++)
    {
        if(srcPopulation[model->tourGroup[i]].fit > srcPopulation[model->tourGroup[ind]].fit)
        {
            ind = i;
        }
    }

    return &srcPopulation[ind];
}

void realTwoParentsTournamentSelection(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model)
{
    int i, j;

    for(i = 0; i < population->totalFamilies; i++)
    {
        for(j = 0; j < model->tourModel.tourSize; j++)
        {
            model->tourModel.tourGroup[j] = (int) uniform(0, population->size - 1);
        }

        parents[i][0] = model->tourModel.function(&model->tourModel, srcPopulation);

        for(j = 0; j < model->tourModel.tourSize; j++)
        {
            model->tourModel.tourGroup[j] = (int) uniform(0, population->size - 1);
        }

        parents[i][1] = model->tourModel.function(&model->tourModel, srcPopulation);
    }
}

void realnParentsTournamentSelection(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model)
{
    int i, j, k;

    for(i = 0; i < population->totalFamilies; i++)
    {
        for(k = 0; k < population->totalParents; k++)
        {
            for(j = 0; j < model->tourModel.tourSize; j++)
            {
                model->tourModel.tourGroup[j] = (int) uniform(0, population->size - 1);
            }

            parents[i][k] = model->tourModel.function(&model->tourModel, srcPopulation);
        }
    }
}