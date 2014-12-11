#ifndef _SAT_RESULT_H_
#define _SAT_RESULT_H_

#include "Variable.h"

enum AddAssignmentResult {
  NO_CONFLICT = 1,
  ASSIGNMENT_CONFLICT };

class SATResult
{
 public:
  AddAssignmentResult AddAssignment(Variable* v, bool truthVal);
};

#endif
