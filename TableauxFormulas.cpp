#include "TableauxFormulas.h"

TableauxFormulas::TableauxFormulas()
{
  m_formulas = new set<Formula*>();
}

TableauxFormulas::~TableauxFormulas()
{
  delete m_formulas;
}

unsigned int TableauxFormulas::Size()
{
  return m_formulas->size();
}

void TableauxFormulas::AddFormula(Formula* f)
{
  m_formulas->insert(f);
}

Formula* TableauxFormulas::NextFormula()
{
  return *(m_formulas->begin());
}

void TableauxFormulas::RemoveFormula(Formula* f)
{
  m_formulas->erase(f);
}
