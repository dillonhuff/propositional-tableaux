#include "FormulaFactory.h"

FormulaFactory* formulaFactory;

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

Conjunction* FormulaFactory::MakeConjunction(Formula* left, Formula* right)
{
  Conjunction* newConj = new Conjunction(left, right);
  m_allFormulas->push_back(newConj);
  return newConj;
}

Disjunction* FormulaFactory::MakeDisjunction(Formula* left, Formula* right)
{
  Disjunction* newDis = new Disjunction(left, right);
  m_allFormulas->push_back(newDis);
  return newDis;
}

void FormulaFactory::MakeFormulaFactory()
{
  formulaFactory = new FormulaFactory();
  formulaFactory->m_allFormulas = new vector<Formula*>();
}

void FormulaFactory::TearDownFormulaFactory()
{
  vector<Formula*> formulas = *(formulaFactory->m_allFormulas);
  for (auto formula : formulas) {
      delete formula;
  }
  delete formulaFactory->m_allFormulas;
  delete formulaFactory;
}
