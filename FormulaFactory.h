#ifndef _FORMULA_FACTORY_H_
#define _FORMULA_FACTORY_H_

#include <vector>

#include "Formula.h"
#include "Negation.h"
#include "Variable.h"


class FormulaFactory
{
 private:
  vector<Formula*>* m_allFormulas;
 public:
  static FormulaFactory* MakeFormulaFactory();
  static void TearDownFormulaFactory(FormulaFactory* ff);

  Variable* MakeVariable(string name);
  Negation* MakeNegation(Formula* f);
  
};

#endif