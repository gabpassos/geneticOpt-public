#ifndef STDMATH_H_INCLUDED
#define STDMATH_H_INCLUDED

#define uniform(a, b) (double) (b - a)*rand()/RAND_MAX + a

#include <stdlib.h>

typedef enum Boolean
{
    False = 0,
    True = 1,
} boolean;
#endif