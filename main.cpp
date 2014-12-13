#include <iostream>
#include <map>

#include "Formula.h"
#include "FormulaFactory.h"
#include "Negation.h"
#include "SATResult.h"
#include "TableauxSAT.h"
#include "Variable.h"

using namespace std;

FormulaFactory *formulaFactory;

void testResult(bool condition, string testName, string errorMessage)
{
  if (!condition) {
    cout << "ERROR in " << testName << ": " << errorMessage << endl;
  } else {
    cout << testName << " passed" << endl;
  }
  return;
}

void testTableauxSATAssignment(Formula* f, SATResult* expectedResult, string testName)
{
  SATResult actualResult = SATResult();
  TableauxSAT tSAT;
  tSAT.CheckSAT(f, &actualResult);
  testResult(actualResult == expectedResult, testName, "unexpected SAT result");
  return;
}

void singleVariable()
{
  Formula* x = formulaFactory->MakeVariable("x");
  SATResult satAsg = SATResult();
  satAsg.AddAssignment((Variable*) x, true);
  testTableauxSATAssignment(x, &satAsg, "single variable");
}

void negatedVariable()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Formula* negX = formulaFactory->MakeNegation(x);
  SATResult satAsg = SATResult();
  satAsg.AddAssignment(x, false);
  testTableauxSATAssignment(negX, &satAsg, "negated variable");
}

int main(int argv, char** argc)
{
  cout << "Running all tests\n";
  formulaFactory = FormulaFactory::MakeFormulaFactory();
  singleVariable();
  negatedVariable();
  FormulaFactory::TearDownFormulaFactory(formulaFactory);
  return 0;
}
