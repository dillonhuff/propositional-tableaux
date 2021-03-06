#ifndef _FORMULA_FACTORY_H_
#define _FORMULA_FACTORY_H_

#include <vector>

#include "Conjunction.h"
#include "Disjunction.h"
#include "Formula.h"
#include "Negation.h"
#include "Variable.h"


class FormulaFactory
{
 private:
  vector<Formula*>* m_allFormulas;

 public:
  static void MakeFormulaFactory();
  static void TearDownFormulaFactory();

  Variable* MakeVariable(string name);
  Negation* MakeNegation(Formula* f);
  Conjunction* MakeConjunction(Formula* left, Formula* right);
  Disjunction* MakeDisjunction(Formula* left, Formula* right);
  
};

extern FormulaFactory* formulaFactory;

#endif
