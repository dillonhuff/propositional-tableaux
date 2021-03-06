#include <assert.h>
#include <iostream>

#include "Conjunction.h"
#include "Disjunction.h"
#include "Negation.h"
#include "SATResultFactory.h"
#include "TableauxSAT.h"
#include "Variable.h"

void TableauxSAT::NegationSAT(Negation* neg)
{
  Formula* innerF = neg->InnerFormula();
  AddAssignmentResult res;
  if (m_satRes->TruthValue(neg) == true) {
    res = m_satRes->AddAssignment(innerF, false);
  } else {
    res = m_satRes->AddAssignment(innerF, true);
  }

  if (res == UNSAT) {
    m_satRes->RemoveAssignment(innerF);
    return;
  }

  m_remainingFormulas->AddFormula(innerF);
  RecursiveCheckSAT();

  if (!m_satRes->IsSAT()) {
    m_satRes->RemoveAssignment(innerF);
  }
}

void TableauxSAT::BothEvaluateTo(Formula* left, Formula* right, bool value)
{
  AddAssignmentResult leftRes = m_satRes->AddAssignment(left, value);
  if (leftRes == UNSAT) {
    m_satRes->RemoveAssignment(left);
    return;
  }

  AddAssignmentResult rightRes = m_satRes->AddAssignment(right, value);
  if (rightRes == UNSAT) {
    m_satRes->RemoveAssignment(right);
    return;
  }

  m_remainingFormulas->AddFormula(left);
  m_remainingFormulas->AddFormula(right);

  RecursiveCheckSAT();

  if (!m_satRes->IsSAT()) {
    m_satRes->RemoveAssignment(left);
    m_satRes->RemoveAssignment(right);
  }
}

void TableauxSAT::AtLeastOneEvaluatesTo(Formula* left, Formula* right, bool value)
{
  AddAssignmentResult leftRes = m_satRes->AddAssignment(left, value);
  if (leftRes == UNSAT) {
    m_satRes->RemoveAssignment(left);
    return;
  }

  m_remainingFormulas->AddFormula(left);
  RecursiveCheckSAT();

  if (m_satRes->IsSAT()) {
    return;
  }

  m_satRes->RemoveAssignment(left);

  AddAssignmentResult rightRes = m_satRes->AddAssignment(right, value);
  if (rightRes == UNSAT) {
    m_satRes->RemoveAssignment(right);
    return;
  }

  m_remainingFormulas->AddFormula(right);
  RecursiveCheckSAT();

  if (m_satRes->IsSAT()) {
    return;
  }

  m_satRes->RemoveAssignment(right);
}

void TableauxSAT::DisjunctionSAT(Disjunction* disj)
{
  if (m_satRes->TruthValue(disj) == true) {
    AtLeastOneEvaluatesTo(disj->Left(), disj->Right(), true);
  } else {
    BothEvaluateTo(disj->Left(), disj->Right(), false);
  }
}

void TableauxSAT::ConjunctionSAT(Conjunction* conj)
{
  if (m_satRes->TruthValue(conj) == true) {
    BothEvaluateTo(conj->Left(), conj->Right(), true);
  } else {
    AtLeastOneEvaluatesTo(conj->Left(), conj->Right(), false);
  }
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
  } else if (f->IsDisjunction()) {
    Disjunction* disj = (Disjunction*) f;
    DisjunctionSAT(disj);
  }
}

SATResult* TableauxSAT::CheckSAT(Formula* f)
{
  m_remainingFormulas = new TableauxFormulas();
  m_satRes = satResFactory->MakeSATResult();
  m_satRes->AddAssignment(f, true);
  m_remainingFormulas->AddFormula(f);

  RecursiveCheckSAT();

  if (!m_satRes->IsSAT()) {
    m_satRes->RemoveAssignment(f);
    assert(m_satRes->Size() == 0);
  }

  assert(m_remainingFormulas->Size() == 0);
  delete m_remainingFormulas;

  return m_satRes;
}
