#include "FormulaFactory.h"

Variable* FormulaFactory::MakeVariable(string name)
{
  Variable* newVar = new Variable(name);
  m_allFormulas->push_back(newVar);
  return newVar;
}

Negation* FormulaFactory::MakeNegation(Formula* f)
{
  Negation* newNeg = new Negation(f);
  m_allFormulas->push_back(newNeg);
  return newNeg;
}

FormulaFactory* FormulaFactory::MakeFormulaFactory()
{
  FormulaFactory* newFF = new FormulaFactory();
  newFF->m_allFormulas = new vector<Formula*>();
  return newFF;
}

void FormulaFactory::TearDownFormulaFactory(FormulaFactory* ff)
{
  vector<Formula*> formulas = *(ff->m_allFormulas);
  for (auto formula : formulas) {
      delete formula;
  }
  delete ff->m_allFormulas;
}
