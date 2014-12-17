#ifndef _PARSE_RESULT_H_
#define _PARSE_RESULT_H_

#include "Formula.h"

class ParseResult
{
 private:
  Formula* m_parsedFormula;

 public:
  Formula* ParsedFormula();
};

#endif
