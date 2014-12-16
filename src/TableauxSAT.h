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
  void TrueConjunction(Conjunction* conj);
  void FalseConjunction(Conjunction* conj);
  void ConjunctionSAT(Conjunction* conj);
  void RecursiveCheckSAT();

 public:
  SATResult* CheckSAT(Formula* f);
};

#endif
