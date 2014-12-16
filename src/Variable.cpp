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
