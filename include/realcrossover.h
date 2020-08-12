#ifndef REALCROSSOVER_H_DEFINED
#define REALCROSSOVER_H_DEFINED

#include "stdgen.h"

typedef void realCrossoverFunction(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);

typedef struct realcrossovermodel
{
    char type[MAX_TYPE_STRLEN];
    realCrossoverFunction *function;
    double prob;
    unsigned int nPoint;
    unsigned int **sepLimits;
} realCrossoverModel;

void realOnePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);
void realTwoPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);
void realThreePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);
void realnPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);

#endif