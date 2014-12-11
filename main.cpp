#include <iostream>
#include <map>

#include "Formula.h"
#include "SATResult.h"
#include "TableauxSAT.h"
#include "Variable.h"

using namespace std;

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

void singleVariableTableaux()
{
  Formula x = Variable("x");
  SATResult satAsg = SATResult();
  satAsg.AddAssignment((Variable*) &x, true);
  testTableauxSATAssignment(&x, &satAsg, "single variable");
  return;
}

int main(int argv, char** argc)
{
  cout << "Running all tests\n";
  singleVariableTableaux();
  return 0;
}
