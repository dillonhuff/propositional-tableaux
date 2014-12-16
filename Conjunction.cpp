#include "Conjunction.h"

Conjunction::Conjunction(Formula* left, Formula* right)
{
  m_left = left;
  m_right = right;
}

bool Conjunction::IsConjunction()
{
  return true;
}

Formula* Conjunction::Left()
{
  return m_left;
}

Formula* Conjunction::Right()
{
  return m_right;
}
