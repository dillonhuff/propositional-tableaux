#include "ParseResultFactory.h"

ParseResultFactory* parseResultFactory;

ParseResult* ParseResultFactory::MakeParseResult(Formula* f)
{
  ParseResult* newParseResult = new ParseResult();
  m_allParseResults->push_back(newParseResult);
  return newParseResult;
}

void ParseResultFactory::MakeParseResultFactory()
{
  parseResultFactory = new ParseResultFactory();
  parseResultFactory->m_allParseResults = new vector<ParseResult*>();
}

void ParseResultFactory::TearDownParseResultFactory()
{
  vector<ParseResult*> results = *(parseResultFactory->m_allParseResults);
  for (auto parseRes : results) {
    delete parseRes;
  }
  delete parseResultFactory->m_allParseResults;
  delete parseResultFactory;
}
