#ifndef GENERICMODELDATA_H_INCLUDED
#define GENERICMODELDATA_H_INCLUDED

#define MAX_CHROM_STRLEN 5
#define MAX_TYPE_STRLEN 16

#include "stdmath.h"

typedef enum obj {min = 0, max = 1} objective;

typedef struct population
{
    unsigned int size;
    unsigned int maxGenerations;

    unsigned int totalFamilies;
    unsigned int totalParents;
    unsigned int totalChildren;

    unsigned int maxIndividuals;
} populationData;

typedef struct chromosome
{
    char type[MAX_CHROM_STRLEN]; //"bin", "int", "real"
    unsigned int length;

    double *supLimit;
    double *infLimit;
} chromosomeData;

/********************************************************************************************************************************************/
/**************
 * REAL MODEL *
 * ************/

typedef struct realchromosome
{
    double fit;
    double *gene;

    unsigned int generation;

    boolean evaluated;
} realChromosome;

void copyRealChromosome(realChromosome *dest, realChromosome *src, chromosomeData *chromosome);

#endif