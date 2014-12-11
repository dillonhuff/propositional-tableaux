#include "TableauxSAT.h"

void TableauxSAT::CheckSAT(Formula* f, SATResult* res)
{
  Variable* v = (Variable*) f;
  res->AddAssignment(v, true);
  return;
}
