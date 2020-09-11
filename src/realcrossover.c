#include "realcrossover.h"
#include "stdgen.h"
#include "stdmath.h"

void realOnePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation)
{
    int i, j, k1, k2, sep;
    double prob;

    for(i = 0, k1 = 0, k2 = 1; i < population->totalFamilies; i++, k1+=2, k2+=2)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {
            totalPopulation[k1].evaluated = False;
            totalPopulation[k1].generation = generation;

            totalPopulation[k2].evaluated = False;
            totalPopulation[k2].generation = generation;

            sep = (int) uniform(crossover->sepLimits[0][0], crossover->sepLimits[0][1]);
            for(j = 0; j < sep; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][0]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][1]->gene[j];
            }

            for(j = sep; j < chromosome->length; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][1]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][0]->gene[j];
            }
        }

        else
        {
            copyRealChromosome(&totalPopulation[k1], parents[i][0], chromosome);
            copyRealChromosome(&totalPopulation[k2], parents[i][1], chromosome);
        }
    }
}

void realTwoPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation)
{
    int i, j, k1, k2, sep1, sep2;
    double prob;

    for(i = 0, k1 = 0, k2 = 1; i < population->totalFamilies; i++, k1+=2, k2+=2)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {
            totalPopulation[k1].evaluated = False;
            totalPopulation[k1].generation = generation;

            totalPopulation[k2].evaluated = False;
            totalPopulation[k2].generation = generation;

            sep1 = (int) uniform(crossover->sepLimits[0][0], crossover->sepLimits[0][1]);
            sep2 = (int) uniform(crossover->sepLimits[1][0], crossover->sepLimits[1][1]);

            for(j = 0; j < sep1; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][0]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][1]->gene[j];
            }

            for(j = sep1; j < sep2; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][1]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][0]->gene[j];
            }

            for(j = sep2; j < chromosome->length; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][0]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][1]->gene[j];
            }
        }

        else
        {
            copyRealChromosome(&totalPopulation[k1], parents[i][0], chromosome);
            copyRealChromosome(&totalPopulation[k2], parents[i][1], chromosome);
        }
    }
}

void realThreePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation)
{
    int i, j, k1, k2, sep1, sep2, sep3;
    double prob;

    for(i = 0, k1 = 0, k2 = 1; i < population->totalFamilies; i++, k1+=2, k2+=2)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {
            totalPopulation[k1].evaluated = False;
            totalPopulation[k1].generation = generation;

            totalPopulation[k2].evaluated = False;
            totalPopulation[k2].generation = generation;

            sep1 = (int) uniform(crossover->sepLimits[0][0], crossover->sepLimits[0][1]);
            sep2 = (int) uniform(crossover->sepLimits[1][0], crossover->sepLimits[1][1]);
            sep3 = (int) uniform(crossover->sepLimits[2][0], crossover->sepLimits[2][1]);

            for(j = 0; j < sep1; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][0]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][1]->gene[j];
            }

            for(j = sep1; j < sep2; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][1]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][0]->gene[j];
            }

            for(j = sep2; j < sep3; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][0]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][1]->gene[j];
            }

            for(j = sep3; j < chromosome->length; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][1]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][0]->gene[j];
            }
        }

        else
        {
            copyRealChromosome(&totalPopulation[k1], parents[i][0], chromosome);
            copyRealChromosome(&totalPopulation[k2], parents[i][1], chromosome);
        }
    }
}

void realnPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation)
{
    int i, j, n, k1, k2, prtSrc1, prtSrc2, prtSrcAux;
    int sep[crossover->nPoint];
    double prob;

    for(i = 0, k1 = 0, k2 = 1; i < population->totalFamilies; i++, k1+=2, k2+=2)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {
            totalPopulation[k1].evaluated = False;
            totalPopulation[k1].generation = generation;

            totalPopulation[k2].evaluated = False;
            totalPopulation[k2].generation = generation;

            for(n = 1; n <= crossover->nPoint; n++)
            {
                sep[n] = (int) uniform(crossover->sepLimits[n][0], crossover->sepLimits[n][1]);
            }

            prtSrc1 = 0;
            prtSrc2 = 1;
            for(j = 0; j < sep[0]; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][prtSrc1]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][prtSrc2]->gene[j];
            }

            for(n = 0; n < crossover->nPoint - 1; n++)
            {
                prtSrcAux = prtSrc1;
                prtSrc1 = prtSrc2;
                prtSrc2 = prtSrcAux;
                for(j = sep[n]; j < sep[n+1]; j++)
                {
                    totalPopulation[k1].gene[j] = parents[i][prtSrc1]->gene[j];
                    totalPopulation[k2].gene[j] = parents[i][prtSrc2]->gene[j];
                }
            }

            prtSrcAux = prtSrc1;
            prtSrc1 = prtSrc2;
            prtSrc2 = prtSrcAux;
            for(j = sep[crossover->nPoint - 1]; j < chromosome->length; j++)
            {
                totalPopulation[k1].gene[j] = parents[i][prtSrc1]->gene[j];
                totalPopulation[k2].gene[j] = parents[i][prtSrc2]->gene[j];
            }
        }

        else
        {
            copyRealChromosome(&totalPopulation[k1], parents[i][0], chromosome);
            copyRealChromosome(&totalPopulation[k2], parents[i][1], chromosome);
        }
    }
}
