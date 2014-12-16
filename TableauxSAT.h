#ifndef _TABLEAUX_SAT_H_
#define _TABLEAUX_SAT_H_

#include <map>

#include "Formula.h"
#include "SATResult.h"

class TableauxSAT
{
 private:
  SATResult* m_satRes;
  void RecursiveCheckSAT(Formula* f);

 public:
  SATResult* CheckSAT(Formula* f);
};

#endif
