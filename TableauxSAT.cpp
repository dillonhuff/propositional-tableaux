#include <assert.h>

#include "Conjunction.h"
#include "Negation.h"
#include "SATResultFactory.h"
#include "Variable.h"
#include "TableauxSAT.h"

void TableauxSAT::RecursiveCheckSAT(Formula* f)
{
  if (f->IsVariable()) {
    m_satRes->AddAssignment((Variable*) f, true);
  } else if (f->IsNegation()) {
    Negation* negF = (Negation*) f;
    assert(negF->InnerFormula()->IsVariable());
    m_satRes->AddAssignment((Variable*) negF->InnerFormula(), false);
  } else if (f->IsConjunction()) {
    Conjunction* conj = (Conjunction*) f;
    Formula* left = conj->Left();
    Formula* right = conj->Right();
    //    RecursiveCheckSAT
  }
}

SATResult* TableauxSAT::CheckSAT(Formula* f)
{
  m_satRes = satResFactory->MakeSATResult();
  RecursiveCheckSAT(f);
  return m_satRes;
}


