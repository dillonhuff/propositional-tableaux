#include "Negation.h"

Negation::Negation(Formula* f)
{
  m_innerFormula = f;
}

Formula* Negation::InnerFormula()
{
  return m_innerFormula;
}

bool Negation::IsNegation()
{
  return true;
}
