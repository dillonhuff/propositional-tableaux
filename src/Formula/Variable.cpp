#include <iostream>

#include "Variable.h"

Variable::Variable(string name)
{
  m_name = new string(name);
}

Variable::~Variable()
{
  delete m_name;
}

bool Variable::IsVariable()
{
  return true;
}

bool Variable::operator==(Formula* f)
{
  if (f->IsVariable()) {
    Variable* v = (Variable*) f;
    return this->m_name == v->m_name;
  } else {
    return false;
  }
}

void Variable::PrettyPrint()
{
  cout << *m_name;
}
