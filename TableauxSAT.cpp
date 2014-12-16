#include <assert.h>
#include <iostream>

#include "Conjunction.h"
#include "Negation.h"
#include "SATResultFactory.h"
#include "TableauxSAT.h"
#include "Variable.h"

void TableauxSAT::NegationSAT(Negation* neg)
{
  Formula* innerF = neg->InnerFormula(); 
  AddAssignmentResult res = m_satRes->AddAssignment(innerF, false);
  if (res == UNSAT) {
    return;
  }

  m_remainingFormulas->AddFormula(innerF);
  RecursiveCheckSAT();
}

void TableauxSAT::ConjunctionSAT(Conjunction* conj)
{
  Formula* left = conj->Left();
  Formula* right = conj->Right();

  AddAssignmentResult leftRes = m_satRes->AddAssignment(left, true);
  if (leftRes == UNSAT) {
    return;
  }

  AddAssignmentResult rightRes = m_satRes->AddAssignment(right, true);
  if (rightRes == UNSAT) {
    return;
  }

  m_remainingFormulas->AddFormula(left);
  m_remainingFormulas->AddFormula(right);
  RecursiveCheckSAT();
}

void TableauxSAT::RecursiveCheckSAT()
{
  if (m_remainingFormulas->Size() == 0) {
    return;
  }

  Formula* f = m_remainingFormulas->NextFormula();
  m_remainingFormulas->RemoveFormula(f);

  if (f->IsVariable()) {
    RecursiveCheckSAT();
  } else if (f->IsNegation()) {
    Negation* negF = (Negation*) f;
    NegationSAT(negF);
  } else if (f->IsConjunction()) {
    Conjunction* conj = (Conjunction*) f;
    ConjunctionSAT(conj);
  }
}

SATResult* TableauxSAT::CheckSAT(Formula* f)
{
  m_remainingFormulas = new TableauxFormulas();
  m_satRes = satResFactory->MakeSATResult();
  m_satRes->AddAssignment(f, true);
  m_remainingFormulas->AddFormula(f);

  RecursiveCheckSAT();

  assert(m_remainingFormulas->Size() == 0);
  delete m_remainingFormulas;

  return m_satRes;
}


