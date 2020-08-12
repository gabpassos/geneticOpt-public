#ifndef REALCODIFICATIONMODEL_H_DEFINED
#define REALCODIFICATIONMODEL_H_DEFINED

#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif
#include <Python.h>
#include "structmember.h"

#include "genericmodeldata.h"
#include "realcrossover.h"
#include "realmutation.h"
#include "realreplacement.h"

typedef struct realgeneticmodel
{
    PyObject_HEAD
    PyObject *fitFunction;

    realChromosome *indvidual;

    populationData population;
    chromosomeData chromosome;

    realCrossoverModel crossover;
    realMutationModel mutation;
    realReplacementModel replacement;
} realGeneticModelObject;

#endif