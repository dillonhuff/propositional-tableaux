#include <string>

#include "DIMACSParser.h"
#include "FormulaFactory.h"
#include "ParseResultFactory.h"

ParseResult* DIMACSParser::ParseCNF(std::string toParse)
{
  Formula* dummyFormula = formulaFactory->MakeVariable("1");
  ParseResult* parseRes = parseResultFactory->MakeParseResult(dummyFormula);
  return parseRes;
}
