#ifndef REALSELECTION_H_INCLUDED
#define REALSELECTION_H_INCLUDED

#include "stdgen.h"

typedef enum realselecttype
{
    realSelect_type_undef = 0,
    realTwoParentsTournamentSelectionType = 1,
    realnParentsTournamentSelectionType = 2
} realSelectType;

typedef struct tournamentmodel tournamentModel;
typedef struct realselectionmodel realSelectionModel;

typedef realChromosome* tournamentFunction(tournamentModel *model, realChromosome *srcPopulation);
typedef void realSelectionFunction(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model);

typedef struct realselectionmodel
{
    realSelectType type;
    realSelectionFunction *function;
    tournamentModel tourModel;
} realSelectionModel;

typedef struct tournamentmodel
{
    int tourSize;
    int *tourGroup;
    tournamentFunction *function;
} tournamentModel;

realChromosome* minTournament(tournamentModel *model, realChromosome *srcPopulation);
realChromosome* maxTournament(tournamentModel *model, realChromosome *srcPopulation);
void realTwoParentsTournamentSelection(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model);
void realnParentsTournamentSelection(realChromosome ***parents, realChromosome *srcPopulation, populationData *population, realSelectionModel *model);

#endif
