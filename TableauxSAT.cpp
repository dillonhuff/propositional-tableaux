#include <assert.h>

#include "Negation.h"
#include "SATResultFactory.h"
#include "TableauxSAT.h"

SATResult* TableauxSAT::CheckSAT(Formula* f)
{
  SATResult* res = satResFactory->MakeSATResult();
  if (f->IsVariable()) {
    res->AddAssignment((Variable*) f, true);
  } else if (f->IsNegation()) {
    Negation* negF = (Negation*) f;
    assert(negF->InnerFormula()->IsVariable());
    res->AddAssignment((Variable*) negF->InnerFormula(), false);
  }
  return res;
}


