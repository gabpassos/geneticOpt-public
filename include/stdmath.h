#ifndef STDMATH_H_INCLUDED
#define STDMATH_H_INCLUDED

#include <stdlib.h>

#define uniform(a, b) (double) (b - a)*rand()/RAND_MAX + a

typedef enum Boolean
{
    False = 0,
    True = 1,
} boolean;
#endif