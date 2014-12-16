#include <iostream>
#include <map>

#include "BasicSATTests.h"
#include "Formula.h"
#include "FormulaFactory.h"
#include "Negation.h"
#include "SATResult.h"
#include "SATResultFactory.h"
#include "TableauxSAT.h"
#include "Variable.h"


int main(int argv, char** argc)
{
  cout << "Starting setup..." << endl;
  formulaFactory = FormulaFactory::MakeFormulaFactory();
  satResFactory = SATResultFactory::MakeSATResultFactory();
  cout << "Done with setup\n" << endl;

  cout << "* Running all tests..." << endl;
  basicSATTests();
  cout << "* Done with tests" << endl;

  cout << "\nStarting teardown..." << endl;
  FormulaFactory::TearDownFormulaFactory(formulaFactory);
  SATResultFactory::TearDownSATResultFactory(satResFactory);
  cout << "Done with teardown" << endl;

  return 0;
}
