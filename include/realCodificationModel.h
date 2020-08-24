#ifndef REALCODIFICATIONMODEL_H_DEFINED
#define REALCODIFICATIONMODEL_H_DEFINED

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif
#include <Python.h>
#include "structmember.h"

#include "stdgen.h"
#include "realinitialization.h"
#include "realselection.h"
#include "realcrossover.h"
#include "realmutation.h"
#include "realreplacement.h"

typedef struct realgeneticmodel
{
    PyObject_HEAD
    PyObject *fitFunction;
    objective obj;

    realChromosome *indvidual;

    populationData population;
    chromosomeData chromosome;

    realInitializationModel initialization;
    realSelectionModel selection;
    realCrossoverModel crossover;
    realMutationModel mutation;
    realReplacementModel replacement;
} realGeneticModelObject;

#endif