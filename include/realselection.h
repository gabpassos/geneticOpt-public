#ifndef REALSELECTION_H_INCLUDED
#define REALSELECTION_H_INCLUDED

#include "stdgen.h"

typedef void realSelectionFunction();

typedef struct realselectionmodel
{
    char type[MAX_TYPE_STRLEN];
    realSelectionFunction *function;
    

} realSelectionModel;

#endif