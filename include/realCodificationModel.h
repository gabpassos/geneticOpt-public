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

static PyObject* geneticError;

typedef struct realgeneticmodel
{
    PyObject_HEAD
    PyObject *fitFunction;
    objective objType;

    realChromosome *individual;

    populationData population;
    chromosomeData chromosome;

    realInitializationModel initialization;
    realSelectionModel selection;
    realCrossoverModel crossover;
    realMutationModel mutation;
    realReplacementModel replacement;

    unsigned int seed;
} realGeneticModelObject;

static PyObject * defaultNewRealGeneticModel(PyTypeObject *type, PyObject *args, PyObject *kwds);
static int usrInitRealGeneticModel(realGeneticModelObject *self, PyObject *args, PyObject *kwds);
static void realGeneticModelDealloc(realGeneticModelObject *self);
static PyObject * realGeneticModelSolver(realGeneticModelObject *self, PyObject *Py_UNUSED(ignored));

static boolean objectiveVerifySettings(realGeneticModelObject *self, char *objTypeStr, PyObject *fitFunction);
static boolean populationModelVerifySettings(populationData *population);
static boolean chromosomeModelVerifySettings(chromosomeData *chromosome);
static boolean realInitializationModelVerifySettings(realInitializationModel *initialization, char *initTypeStr);
static boolean realSelectionModelVerifySettings(realSelectionModel *selection, char *selectionTypeStr, populationData *population, objective obj);
static boolean realCrossoverModelVerifySettings(realCrossoverModel *crossover, chromosomeData *chromosome, char *crossoverTypeStr);
static boolean realMutationModelVerifySettings(realMutationModel *mutation, chromosomeData *chromosome, char *mutationTypeStr);
static boolean realReplacementModelVerifySettings(realReplacementModel *replacement, char *replacementTypeStr, objective obj);

static boolean realMemoryAllocSolver(realGeneticModelObject *self, realChromosome *totalPopulation, realChromosome ****parents, PyObject **chromosome, PyObject **fitArg);
static boolean realMemoryAllocIndividuals(realGeneticModelObject *self);

static boolean verifyChromLengthWithnPoint(unsigned int chromLength, unsigned int nPoint);

PyMODINIT_FUNC PyInit_geneticOpt(void);

#endif
