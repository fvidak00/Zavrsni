#include <Python.h>
#include <math.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool False = 0;
static const bool True = 1;
#endif

static PyObject* _primes(long n)
{
    bool* could_be_primes=malloc(sizeof(bool)*n);
    PyObject* primes=PyList_New(0);
    long i=0;

    for(i=2; i<n; i++)
    {
        could_be_primes[i]=1;
    }
    could_be_primes[0]=0;
    could_be_primes[1]=0;

    for (i=2; i<(long)sqrt((double)n); i++)
    {
        if (could_be_primes[i]!=0)
        {
            PyList_Append(primes, PyLong_FromLong(i));
            for (long j=i*i; j<n; j=j+i)
            {
                could_be_primes[j]=0;
            }
        }
    }

    for(;i<n;i++)
        if(could_be_primes[i])
            PyList_Append(primes, PyLong_FromLong(i));

    free(could_be_primes);
    return primes;
}

static PyObject *primes_primes_less_than(PyObject* self, PyObject* args)
{
    long n;
    PyObject* primes;

    if(!PyArg_ParseTuple(args, "l", &n))
        return NULL;
    
    primes=_primes(n);
    return primes;
}

static PyMethodDef PrimesMethods[] =
{
    {"primes_less_than", primes_primes_less_than, METH_VARARGS,
    "Compute a list of all the primes up to an integer n."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef primes_module =
{
    PyModuleDef_HEAD_INIT,
    "primes_module",
    "Methods for working with primes and prime factorizations.",
    -1,
    PrimesMethods
};

PyMODINIT_FUNC PyInit_primes(void)
{
    PyObject *m;

    m = PyModule_Create(&primes_module);
    if (m == NULL)
        return NULL;

    return m;
}