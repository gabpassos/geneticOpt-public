#ifndef REALREPLACEMENT_H_INCLUDED
#define REALREPLACEMENT_H_INCLUDED

#include "genericmodeldata.h"

typedef void realReplacementFunction();

typedef struct realreplacementmodel
{
    char type[MAX_TYPE_STRLEN];
    realReplacementFunction *function;

} realReplacementModel;

#endif