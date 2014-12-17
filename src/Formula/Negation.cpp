#include <iostream>

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

bool Negation::operator==(Formula* other)
{
  if (other->IsNegation()) {
    Negation* n = (Negation*) other;
    return this->InnerFormula() == n->InnerFormula();
  } else {
    return false;
  }
}

void Negation::PrettyPrint()
{
  std::cout << "~(";
  InnerFormula()->PrettyPrint();
  std::cout << ")";
}
