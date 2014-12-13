#include <iostream>
#include <map>

#include "Formula.h"
#include "FormulaFactory.h"
#include "Negation.h"
#include "SATResult.h"
#include "SATResultFactory.h"
#include "TableauxSAT.h"
#include "Variable.h"

using namespace std;

void testResult(bool condition, string testName, string errorMessage)
{
  if (!condition) {
    cout << "* ERROR in " << testName << ": " << errorMessage << endl;
  } else {
    cout << "* " << testName << " passed" << endl;
  }
  return;
}

void testTableauxSATAssignment(Formula* f, SATResult* expectedResult, string testName)
{
  TableauxSAT tSAT;
  SATResult* actualResult = tSAT.CheckSAT(f);
  testResult(actualResult == expectedResult, testName, "unexpected SAT result");
}

void singleVariable()
{
  Variable* x = formulaFactory->MakeVariable("x");
  SATResult* satAsg = satResFactory->MakeSATResult();
  satAsg->AddAssignment((Variable*) x, true);
  testTableauxSATAssignment(x, satAsg, "single variable");
}

void negatedVariable()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Formula* negX = formulaFactory->MakeNegation(x);
  SATResult* satAsg = satResFactory->MakeSATResult();
  satAsg->AddAssignment(x, false);
  testTableauxSATAssignment(negX, satAsg, "negated variable");
}

int main(int argv, char** argc)
{
  cout << "Starting setup..." << endl;
  formulaFactory = FormulaFactory::MakeFormulaFactory();
  satResFactory = SATResultFactory::MakeSATResultFactory();
  cout << "Done with setup\n" << endl;

  cout << "* Running all tests..." << endl;
  singleVariable();
  negatedVariable();
  cout << "* Done with tests" << endl;

  cout << "\nStarting teardown..." << endl;
  FormulaFactory::TearDownFormulaFactory(formulaFactory);
  SATResultFactory::TearDownSATResultFactory(satResFactory);
  cout << "Done with teardown" << endl;

  return 0;
}
