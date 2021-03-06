#ifndef REALCROSSOVER_H_DEFINED
#define REALCROSSOVER_H_DEFINED

#include "stdgen.h"

typedef struct realcrossovermodel realCrossoverModel;

typedef enum realcrosstype
{
    realCross_type_undef = 0,
    realOnePointCrossoverType = 1,
    realTwoPointCrossoverType = 2,
    realThreePointCrossoverType = 3,
    realnPointCrossoverType = 4,
} realCrossType;

typedef void realCrossoverFunction(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);

typedef struct realcrossovermodel
{
    realCrossType type;
    realCrossoverFunction *function;
    double prob;
    int nPoint;
    int **sepLimits;
} realCrossoverModel;

void realOnePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);
void realTwoPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);
void realThreePointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);
void realnPointCrossover(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);

#endif
