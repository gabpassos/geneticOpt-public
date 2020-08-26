#ifndef REALCROSSOVER_H_DEFINED
#define REALCROSSOVER_H_DEFINED

#include "stdgen.h"

typedef enum realcrosstype
{
    realCross_type_undef = 0,
    realOnePoint = 1,
    realTwoPoint = 2,
    realThreePoint = 3,
    realnPoint = 4,
} realCrossType;

typedef void realCrossoverFunction(realChromosome ***parents, realChromosome *totalPopulation, realCrossoverModel *crossover, populationData *population, chromosomeData *chromosome, unsigned int generation);

typedef struct realcrossovermodel
{
    realCrossType type;
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
