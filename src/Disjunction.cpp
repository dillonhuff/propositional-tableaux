#include "Disjunction.h"

Disjunction::Disjunction(Formula* left, Formula* right)
{
  m_left = left;
  m_right = right;
}

bool Disjunction::IsDisjunction()
{
  return true;
}
