#ifndef REALSELECTION_H_INCLUDED
#define REALSELECTION_H_INCLUDED

#include "stdgen.h"

typedef void realSelectionFunction(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model);

typedef struct realselectionmodel
{
    char *type;
    realSelectionFunction *function;
    tournamentModel tourModel;   

} realSelectionModel;

typedef struct tournamentmodel
{
    int tourSize;
    int *tourGroup;
    realChromosome* (*function)(tournamentModel *model, realChromosome *srcPopulation); //Function of tournamentFunction type.
} tournamentModel;

typedef realChromosome* tournamentFunction(tournamentModel *model, realChromosome *srcPopulation);

realChromosome* minTournament(tournamentModel *model, realChromosome *srcPopulation);
realChromosome* maxTournament(tournamentModel *model, realChromosome *srcPopulation);
void realTwoParentsTournamentSelection(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model);
void realnParentsTournamentSelection(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model);

#endif