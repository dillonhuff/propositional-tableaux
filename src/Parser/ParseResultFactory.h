#ifndef _PARSE_RESULT_FACTORY_H_
#define _PARSE_RESULT_FACTORY_H_

#include <vector>

#include "Formula.h"
#include "ParseResult.h"

using namespace std;

class ParseResultFactory
{
 private:
  vector<ParseResult*>* m_allParseResults;

 public:
  ParseResult* MakeParseResult(Formula* f);

  static void MakeParseResultFactory();
  static void TearDownParseResultFactory();
};

extern ParseResultFactory* parseResultFactory;

#endif
