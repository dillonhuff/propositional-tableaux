#ifndef _TABLEAUX_SAT_H_
#define _TABLEAUX_SAT_H_

#include <map>

#include "Formula.h"
#include "SATResult.h"
#include "TableauxFormulas.h"

class TableauxSAT
{
 private:
  SATResult* m_satRes;
  TableauxFormulas* m_remainingFormulas;

  void NegationSAT(Negation* neg);
  void BothEvaluateTo(Formula* left, Formula* right, bool value);
  void AtLeastOneEvaluatesTo(Formula* left, Formula* right, bool value);
  void DisjunctionSAT(Disjunction* disj);
  void ConjunctionSAT(Conjunction* conj);
  void RecursiveCheckSAT();

 public:
  SATResult* CheckSAT(Formula* f);
};

#endif
