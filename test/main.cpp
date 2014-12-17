#include <iostream>

#include "BasicSATTests.h"
#include "FormulaFactory.h"
#include "ParserTests.h"
#include "SATResultFactory.h"

int main(int argv, char** argc)
{
  cout << "Starting setup..." << endl;
  formulaFactory = FormulaFactory::MakeFormulaFactory();
  satResFactory = SATResultFactory::MakeSATResultFactory();
  cout << "Done with setup\n" << endl;

  cout << "* Running all tests..." << endl;
  basicSATTests();
  parserTests();
  cout << "* Done with all tests" << endl;

  cout << "\nStarting teardown..." << endl;
  FormulaFactory::TearDownFormulaFactory(formulaFactory);
  SATResultFactory::TearDownSATResultFactory(satResFactory);
  cout << "Done with teardown" << endl;

  return 0;
}
