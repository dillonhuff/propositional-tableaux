#include "TestUtils.h"

#include <iostream>

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
