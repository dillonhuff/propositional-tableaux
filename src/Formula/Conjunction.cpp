#include <iostream>

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

bool Conjunction::operator==(Formula* other)
{
  if (other->IsConjunction()) {
    Conjunction* c = (Conjunction*) other;
    return (this->Left() == c->Left()) && (this->Right() == c->Right());
  } else {
    return false;
  }
}

void Conjunction::PrettyPrint()
{
  Left()->PrettyPrint();
  std::cout << " & ";
  Right()->PrettyPrint();
}
