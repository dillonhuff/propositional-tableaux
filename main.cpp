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
  testResult(actualResult->Equals(expectedResult), testName, "unexpected SAT result");
}

void singleVariable()
{
  Variable* x = formulaFactory->MakeVariable("x");
  SATResult* satAsg = satResFactory->MakeSATResult();
  satAsg->AddAssignment(x, true);
  testTableauxSATAssignment(x, satAsg, "single variable");
}

void negatedVariable()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Formula* negX = formulaFactory->MakeNegation(x);
  SATResult* satAsg = satResFactory->MakeSATResult();
  satAsg->AddAssignment(negX, true);
  satAsg->AddAssignment(x, false);
  testTableauxSATAssignment(negX, satAsg, "negated variable");
}

void unSATNegation()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Negation* notX = formulaFactory->MakeNegation(x);
  Negation* notX2 = formulaFactory->MakeNegation(x);
  Negation* notNotX = formulaFactory->MakeNegation(notX2);
  Conjunction* unsat = formulaFactory->MakeConjunction(notNotX, notX);
  SATResult* satAsg = satResFactory->MakeUnSATResult();
  testTableauxSATAssignment(unsat, satAsg, "not x and not not x");
}

void oneUnSATConjunction()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Negation* notX = formulaFactory->MakeNegation(x);
  Conjunction* xAndNotX = formulaFactory->MakeConjunction(x, notX);
  SATResult* satAsg = satResFactory->MakeUnSATResult();
  testTableauxSATAssignment(xAndNotX, satAsg, "one unsat conjunction");
}

void oneSATConjunction()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Conjunction* xAndX = formulaFactory->MakeConjunction(x, x);
  SATResult* satAsg = satResFactory->MakeSATResult();
  satAsg->AddAssignment(xAndX, true);
  satAsg->AddAssignment(x, true);
  testTableauxSATAssignment(xAndX, satAsg, "one sat conjunction");
}

void oneSATDisjunction()
{
  Variable* x = formulaFactory->MakeVariable("x");
  Variable* y = formulaFactory->MakeVariable("y");
  Disjunction* xOrY = formulaFactory->MakeDisjunction(x, y);
  SATResult* satAsg = satResFactory->MakeSATResult();
  satAsg->AddAssignment(x, true);
  satAsg->AddAssignment(xOrY, true);
  testTableauxSATAssignment(xOrY, satAsg, "one sat disjunction");
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
  unSATNegation();
  oneUnSATConjunction();
  oneSATConjunction();
  oneSATDisjunction();
  cout << "* Done with tests" << endl;

  cout << "\nStarting teardown..." << endl;
  FormulaFactory::TearDownFormulaFactory(formulaFactory);
  SATResultFactory::TearDownSATResultFactory(satResFactory);
  cout << "Done with teardown" << endl;

  return 0;
}
