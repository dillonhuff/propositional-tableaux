#include <iostream>

#include "DIMACSParser.h"
#include "ParserTests.h"
#include "FormulaFactory.h"
#include "TestUtils.h"

using namespace std;

void checkCorrectFormula(Formula* correct, string toParse, string testName)
{
  DIMACSParser parser;
  Formula* parseResult = parser.ParseCNF(toParse)->ParsedFormula();
  testResult(correct == parseResult, testName, "expected and actual formula don't match");
}

void oneVariableOneClause()
{
  string toParse = "p cnf 1 1\n1 0\n%\n0";
  Formula* correct = formulaFactory->MakeVariable("1");
  checkCorrectFormula(correct, toParse, "one clause with one variable");
}

void parserTests()
{
  cout << endl << "* ----- Starting parser tests ----- *" << endl;
  oneVariableOneClause();
  cout << "* ----- Done with parser tests ----- *" << endl << endl;
}
