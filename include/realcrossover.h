#ifndef REALCROSSOVER_H_DEFINED
#define REALCROSSOVER_H_DEFINED

#include "genericmodeldata.h"

typedef void realCrossoverFunction(realChromosome ***parents, realChromosome **totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome);

typedef struct realcrossovermodel
{
    char type[MAX_TYPE_STRLEN];
    realCrossoverFunction *function;
    double prob;
    unsigned int nPoint;
} realCrossoverModel;

void realOnePointCrossover(realChromosome ***parents, realChromosome **totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome);
void realTwoPointCrossover(realChromosome ***parents, realChromosome **totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome);
void realThreePointCrossover(realChromosome ***parents, realChromosome **totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome);
void realnPointCrossover(realChromosome ***parents, realChromosome **totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome);

#endif