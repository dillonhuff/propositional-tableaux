#include <iostream>

#include "BasicSATTests.h"
#include "FormulaFactory.h"
#include "ParseResultFactory.h"
#include "ParserTests.h"
#include "SATResultFactory.h"

int main(int argv, char** argc)
{
  cout << "Starting setup..." << endl;
  FormulaFactory::MakeFormulaFactory();
  SATResultFactory::MakeSATResultFactory();
  ParseResultFactory::MakeParseResultFactory();
  cout << "Done with setup\n" << endl;

  cout << "* Running all tests..." << endl;
  basicSATTests();
  parserTests();
  cout << "* Done with all tests" << endl;

  cout << "\nStarting teardown..." << endl;
  FormulaFactory::TearDownFormulaFactory();
  SATResultFactory::TearDownSATResultFactory();
  ParseResultFactory::TearDownParseResultFactory();
  cout << "Done with teardown" << endl;

  return 0;
}
