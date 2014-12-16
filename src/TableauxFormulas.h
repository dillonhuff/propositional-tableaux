#ifndef _TABLEAUX_FORMULAS_H_
#define _TABLEAUX_FORMULAS_H_

#include <set>

#include "Formula.h"

using namespace std;

class TableauxFormulas
{
 private:
  set<Formula*>* m_formulas;

 public:
  TableauxFormulas();
  ~TableauxFormulas();

  unsigned int Size();

  void AddFormula(Formula* f);
  void RemoveFormula(Formula* f);
  Formula* NextFormula();
};

#endif
