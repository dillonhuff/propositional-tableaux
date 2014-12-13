#include "SATResultFactory.h"
#include "TableauxSAT.h"

SATResult* TableauxSAT::CheckSAT(Formula* f)
{
  SATResult* res = satResFactory->MakeSATResult();
  res->AddAssignment((Variable*) f, true);
  return res;
}


