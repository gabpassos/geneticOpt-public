#ifndef GENERICMODELDATA_H_INCLUDED
#define GENERICMODELDATA_H_INCLUDED

#include "stdmath.h"

#define MAX_CHROM_STRLEN 5
#define MAX_TYPE_STRLEN 16
#define DEFAULT_CHROM_LIMIT 1000

typedef enum obj
{
    obj_type_undef = 0,
    min = 1,
    max = 2
} objective;

typedef enum chrom_type
{
    chrom_type_undef = 0,
    bin = 1,
    integer = 2,
    real = 3
} chromosomeType;

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
    chromosomeType type;
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
