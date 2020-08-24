#ifndef PY_SSIZE_T_CLEAN
#define PY_SSIZE_T_CLEAN
#endif
#include <Python.h>
#include "structmember.h"

#include "realCodificationModel.h"
#include "stdmath.h"
#include "stdgen.h"
#include "realinitialization.h"
#include "realselection.h"
#include "realcrossover.h"
#include "realmutation.h"
#include "realreplacement.h"

static PyMethodDef realGeneticModelMethods[] =
{

    {NULL, NULL, 0, NULL},
};

static PyMemberDef realGeneticModelObjectMembers[] =
{

    {NULL},
};

static PyTypeObject realGeneticModelType =
{

};

static PyObject * defaultNewRealGeneticModel(PyTypeObject *type, PyObject *args, PyObject *kwds)
{

}

static int usrInitRealGeneticModel(realGeneticModelObject *self, PyObject *args, PyObject *kwds)
{

}

static PyObject * realGeneticModelSolver(PyObject *self, PyObject *Py_UNUSED(ignored))
{
    
}