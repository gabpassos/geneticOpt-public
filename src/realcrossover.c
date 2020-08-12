#include "realcrossover.h"
#include "stdgen.h"
#include "stdmath.h"

void realOnePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen)
{
    int i, j, allele, div;
    double prob;

    for(i = 0; i < population->totalFamilies; i++)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {
            div = (int) uniform(0, chromosome->length);
            for(j = 0; j < div; j++)
            {
            }
        }

        else
        {
            
        }
    }
}

void realTwoPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen)
{
    int i;
    double prob;

    for(i = 0; i < population->totalFamilies; i++)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {

        }

        else
        {
            
        }
    }

}

void realThreePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen)
{
    int i;
    double prob;

    for(i = 0; i < population->totalFamilies; i++)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {

        }

        else
        {
            
        }
    }

}

void realnPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen)
{
    int i;
    double prob;

    for(i = 0; i < population->totalFamilies; i++)
    {
        prob = uniform(0, 1);
        if(prob < crossover->prob)
        {

        }

        else
        {
            
        }
    }

}