#ifndef _DIMACS_PARSER_H_
#define _DIMACS_PARSER_H_

#include "ParseResult.h"

class DIMACSParser
{
 public:
  ParseResult* ParseCNF(std::string fileString);
};

#endif
