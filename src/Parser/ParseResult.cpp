#include "ParseResult.h"

ParseResult::ParseResult(Formula* f)
{
  m_parsedFormula = f;
}

Formula* ParseResult::ParsedFormula()
{
  return m_parsedFormula;
}
