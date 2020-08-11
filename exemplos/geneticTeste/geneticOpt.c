#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif

#include <Python.h>
#include <stdio.h>
#include "structmember.h"

typedef struct population
{
    int popSize;
    int numGenerations;
    //int parentsNumber;
} populationData;

/*********************************/
/*** Chromosome ***/
typedef struct chromosome
{
    char *chromosomeType; //"bin", "int", "real"
    int chromosomeLength; //Numero de variaveis no cromosomo
} chromosomeData;

typedef struct binChrom
{   
    int *gene;
    double fit;
} binChromosome;

typedef struct intChrom
{
    double fit;
    int *gene;
} intChromosome;

typedef struct realChrom
{
    double fit;
    double *gene;
} realChromosome;

typedef void crossoverFunction(realChromosome *pai1, realChromosome *pai2, realChromosome *filho1, realChromosome *filho2, int chromosomeLength, double crossProb);
typedef void mutationFunction(realChromosome *ind, int chromosomeLength, double mutationProb);

/*********************************/
/*** Crossover ***/
typedef struct crossover
{
    char *crossModelStr;
    crossoverFunction *function;
    double prob;
    int numPoints;
    double *pointProb;
} crossoverModel;

/*********************************/
/*** Mutation ***/
typedef struct mutation
{
    char *mutationModelStr;
    mutationFunction *function;
    double prob;
} mutationModel;

/*********************************/
/*** Models ***/
typedef struct binMonoObj
{
    PyObject_HEAD
    //PyObject *objectiveFunction;  //Analisar posteriormente como importar funcao do interpretador

    populationData popData;
    chromosomeData chromData;

    binChromosome *population;

    crossoverModel crossModel;
    mutationModel mutModel;

} binMonoObjModelObject;

typedef struct intMonoObj
{
    PyObject_HEAD
    //PyObject *objectiveFunction;  //Analisar posteriormente como importar funcao do interpretador

    populationData popData;
    chromosomeData chromData;

    intChromosome *population;

    crossoverModel crossModel;
    mutationModel mutModel;

} intMonoObjModelObject;

typedef struct realMonoObj
{
    PyObject_HEAD
    //PyObject *objectiveFunction;  //Analisar posteriormente como importar funcao do interpretador

    populationData popData;
    chromosomeData chromData;

    realChromosome *population;

    crossoverModel crossModel;
    mutationModel mutModel;

} realCodificationObject;

void realCrossover1Pt(realChromosome *pai1, realChromosome *pai2, realChromosome *filho1, realChromosome *filho2, int chromosomeLength, double crossProb);
void realRandomMutation(realChromosome *ind, int chromosomeLength, double mutationProb);
realChromosome * torneio(realChromosome *ind1, realChromosome *ind2);
static PyObject * realCodificationModelSolver(PyObject *self, PyObject *Py_UNUSED(ignored));
int getBestFit(const void *i, const void *j);
void fitEval(realChromosome *ind);
double uniform(double a, double b);
static PyObject * getSolution(PyObject *self, PyObject *Py_UNUSED(ignored));

static PyObject * defaultNewRealCodificationModel(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    realCodificationObject *self;

    self = (realCodificationObject *) type->tp_alloc(type, 0);
    if(self != NULL)
    {
        self->popData.numGenerations = 0;
        self->popData.popSize = 0;

        self->chromData.chromosomeLength = 0;
        self->chromData.chromosomeType = NULL; //Iniciar com Real

        self->population = NULL;

        self->crossModel.crossModelStr = NULL;
        self->crossModel.function = NULL;
        self->crossModel.numPoints = 0;
        self->crossModel.prob = 0;
        self->crossModel.pointProb = NULL;

        self->mutModel.function = NULL;
        self->mutModel.mutationModelStr = NULL;
        self->mutModel.prob = 0;
    }

    return (PyObject *) self;
}

static int userSetInitRealCodificationModel(realCodificationObject *self, PyObject *args, PyObject *kwds)
{
    int i;
    static char *kwlist[] = {"popSize", "numGenerations", "chromosomeLenght", "crossoverProb", "mutationProb", NULL};

    if(!PyArg_ParseTupleAndKeywords(args, kwds, "|iiidd", kwlist,
                                    &(self->popData.popSize), &(self->popData.numGenerations),
                                    &(self->chromData.chromosomeLength),
                                    &(self->crossModel.prob), &(self->mutModel.prob)))
    {
        return -1;
    }

    self->crossModel.function = realCrossover1Pt;
    self->mutModel.function = realRandomMutation;

    self->population = (realChromosome *) malloc((self->popData.popSize)*sizeof(realChromosome));
    for(i = 0; i<self->popData.popSize; i++)
    {
        self->population[i].fit = 0;
        self->population[i].gene = (double *) malloc((self->chromData.chromosomeLength)*sizeof(double));
    }

    return 0;
}

static PyMethodDef realCodificationMethods[] =
{
    {"Solve", (PyCFunction) realCodificationModelSolver, METH_NOARGS, "Solves the user defined genetic real model."},
    {"getSolution", (PyCFunction) getSolution, METH_NOARGS, "Print the current population gene and fitness value."},
    {NULL, NULL, 0, NULL},
};

static PyMemberDef realCodificationMembers[] =
{
    {"popData", T_NONE, offsetof(realCodificationObject, popData), 0, 
    "Population Settings"},
    
    {"chromData", T_NONE, offsetof(realCodificationObject, chromData), 0,
    "Chromosome Settings"},
    
    {"population", T_NONE, offsetof(realCodificationObject, population), 0,
    "Complete Population"},
    
    {"crossModel", T_NONE, offsetof(realCodificationObject, popData), 0,
    "Crossover Settings"},
    
    {"mutModel", T_NONE, offsetof(realCodificationObject, popData), 0,
    "Mutation Settings"},

    {NULL}
};

static PyTypeObject realMonoObjModelType =
{
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "geneticOpt.realCodificationModel",
    .tp_doc = "Genetic Algorithm with real number codification.",
    .tp_basicsize = sizeof(realCodificationObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = defaultNewRealCodificationModel,
    .tp_init = (initproc) userSetInitRealCodificationModel,
    //.tp_dealloc = ,
    .tp_methods = realCodificationMethods,
    .tp_members = realCodificationMembers,
};

static PyModuleDef geneticOptModule =
{
    PyModuleDef_HEAD_INIT,
    .m_name = "geneticOpt",
    .m_doc = "Genetic Optimization",
    .m_size = -1,
};

PyMODINIT_FUNC PyInit_geneticOpt(void)
{
    PyObject *m;

    if(PyType_Ready(&realMonoObjModelType) < 0)
    {
        return NULL;
    }

    m = PyModule_Create(&geneticOptModule);
    if(m == NULL)
    {
        return NULL;
    }

    Py_INCREF(&realMonoObjModelType);
    if(PyModule_AddObject(m, "realCodificationModel", (PyObject *) &realMonoObjModelType) < 0)
    {
        Py_DECREF(&realMonoObjModelType);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}

/********************************************************************************************/
void realCrossover1Pt(realChromosome *pai1, realChromosome *pai2, realChromosome *filho1, realChromosome *filho2, int chromosomeLength, double crossProb)
{
    double prob;
    int parte, i;

    prob = uniform(0, 1);
    if(prob < crossProb)
    {
        parte = (int) uniform(0, chromosomeLength);
        for(i = 0; i < parte; i++)
        {
            (filho1->gene)[i] = (pai1->gene)[i];
            (filho2->gene)[i] = (pai2->gene)[i];
        }

        for(i = parte; i < chromosomeLength; i++)
        {
            (filho1->gene)[i] = (pai2->gene)[i];
            (filho2->gene)[i] = (pai1->gene)[i];
        }
    }

    else
    {
        for(i = 0; i < chromosomeLength; i++)
        {
            (filho1->gene)[i] = (pai1->gene)[i];
            (filho2->gene)[i] = (pai2->gene)[i];
        }
    }    
}

void realRandomMutation(realChromosome *ind, int chromosomeLength, double mutationProb)
{
    double prob;
    int i;

    prob = uniform(0, 1);
    if(prob < mutationProb)
    {
        for(i = 0; i < chromosomeLength; i++)
        {
            prob = uniform(0, 1);
            if(prob < 0.01)
            {
                (ind->gene)[i] = uniform(-100,-100);
            }
        }

    }

}

realChromosome * torneio(realChromosome *ind1, realChromosome *ind2)
{
    if(ind1->fit < ind2->fit)
    {
        return ind1;
    }

    else if(ind2->fit < ind1->fit)
    {
        return ind2;
    }

    else
    {
        if(uniform(0,1) < 0.5)
        {
            return ind1;
        }
    }

    return ind2;    
}

void fitEval(realChromosome *ind)
{
    double s;
    int i;

    s = 0;
    for(i=0; i<4; i++)
    {
        s = s + ind->gene[i]*ind->gene[i];
    }

    ind->fit = s;
}

void ordena(realChromosome *population, int popSize)
{
    qsort(population, popSize, sizeof(realChromosome), getBestFit);
}

int getBestFit(const void *i, const void *j)
{
	realChromosome *a,*b;
	a = (realChromosome *)i;
	b = (realChromosome *)j;

	if(a->fit < b->fit)    // crescente
		return -1;

	else if(a->fit > b->fit)
		return 1;

	else
		return 0;
}

static PyObject * realCodificationModelSolver(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    realCodificationObject *genMod;
    int i, g, j, k;
    int a, b;
    realChromosome *mista, *pai1, *pai2;

    srand(time(0));
    genMod = (realCodificationObject *) self;

    mista = (realChromosome *) malloc(2*(genMod->popData.popSize)*sizeof(realChromosome));
    for(i = 0; i < 2*genMod->popData.popSize; i++)
    {
        mista[i].gene = (double *) malloc((genMod->chromData.chromosomeLength)*sizeof(double));
    }

    for(i=0; i<genMod->popData.popSize; i++)
    {
        for(k=0; k<genMod->chromData.chromosomeLength; k++)
        {
            genMod->population[i].gene[k] = uniform(-100,100);
        }

        fitEval(&(genMod->population[i]));
    }

    for(g = 0; g < genMod->popData.numGenerations; g++)
    {
        ordena(genMod->population, genMod->popData.popSize);
        
        for(i = 0; i < genMod->popData.popSize/2; i++)
        {
            a = (int) uniform(0, (genMod->popData.popSize)-1);
            b = (int) uniform(0, (genMod->popData.popSize)-1);
            pai1 = torneio(&(genMod->population[a]),&(genMod->population[b]));

            a = (int) uniform(0, (genMod->popData.popSize)-1);
            b = (int) uniform(0, (genMod->popData.popSize)-1);
            pai2 = torneio(&(genMod->population[a]),&(genMod->population[b]));

            genMod->crossModel.function(pai1, pai2, &(mista[2*i]), &(mista[2*i+1]), genMod->chromData.chromosomeLength, genMod->crossModel.prob);

            genMod->mutModel.function(&(mista[2*i]), genMod->chromData.chromosomeLength, genMod->mutModel.prob);
            genMod->mutModel.function(&(mista[2*i+1]), genMod->chromData.chromosomeLength, genMod->mutModel.prob);

            fitEval(&(mista[2*i]));
            fitEval(&(mista[2*i+1]));
        }
        
        j = genMod->popData.popSize;

        for(i = 0; i < genMod->popData.popSize; i++)
        {
            mista[j].fit = genMod->population[i].fit;
            for(k=0; k<genMod->chromData.chromosomeLength; k++)
            {
                mista[j].gene[k] = genMod->population[i].gene[k];
            }

            j++;
        }

        ordena(mista, 2*genMod->popData.popSize);

        for(i = 0; i < genMod->popData.popSize; i++)
        {
            genMod->population[i].fit = mista[i].fit;
            for(k = 0; k<genMod->chromData.chromosomeLength; k++)
            {
                genMod->population[i].gene[k] = mista[i].gene[k];
            }
        }
    }

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject * getSolution(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    realCodificationObject *genMod;
    int i, j;

    genMod = (realCodificationObject *) self;

    for(i=0; i<genMod->popData.popSize; i++)
    {
        printf("\nInd %d\n", i + 1);
        printf("Fit: %lf\n", genMod->population[i].fit);
        printf("SolutionValue:");
        for(j=0; j < genMod->chromData.chromosomeLength; j++ )
        {
            printf(" %lf", genMod->population[i].gene[j]);
        }
        printf("\n");
    }

    Py_INCREF(Py_None);
    return Py_None;
}

double uniform(double a, double b)
{
    return (b - a)*rand()/RAND_MAX + a;
}