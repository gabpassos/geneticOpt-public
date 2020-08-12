#ifndef REALCROSSOVER_H_DEFINED
#define REALCROSSOVER_H_DEFINED

#include "stdgen.h"

typedef void realCrossoverFunction(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen);

typedef struct realcrossovermodel
{
    char type[MAX_TYPE_STRLEN];
    realCrossoverFunction *function;
    double prob;
    unsigned int nPoint;
} realCrossoverModel;

void realOnePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen);
void realTwoPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen);
void realThreePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen);
void realnPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int gen);

#endif