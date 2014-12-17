#include <iostream>

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

bool Disjunction::operator==(Formula* other)
{
  if (other->IsDisjunction()) {
    Disjunction* d = (Disjunction*) other;
    return (this->Left() == d->Left()) && (this->Right() == d->Right());
  } else {
    return false;
  }
}

void Disjunction::PrettyPrint()
{
  Left()->PrettyPrint();
  std::cout << " | ";
  Right()->PrettyPrint();
}
