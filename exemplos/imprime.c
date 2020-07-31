#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <stdio.h>

static PyObject* imprime(PyObject *self, PyObject *args)
{
    char *str;

    if(!PyArg_ParseTuple(args, "s", &str))
    {
        return NULL;
    }

    printf("%s\n", str);

    return Py_None;
}

static PyMethodDef imprimeMethods[] = {
    {"print", imprime, METH_VARARGS, "Imprime algo na tela."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef imprimeModule = {
    PyModuleDef_HEAD_INIT,
    "imprime",
    NULL,
    -1,
    imprimeMethods
};

PyMODINIT_FUNC PyInit_imprime(void)
{
    return PyModule_Create(&imprimeModule);
}