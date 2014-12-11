#ifndef _TABLEAUX_SAT_H_
#define _TABLEAUX_SAT_H_

#include "Formula.h"
#include "SATResult.h"

class TableauxSAT
{
 public:
  void CheckSAT(Formula* f, SATResult* res);
};

#endif
