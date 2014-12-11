#ifndef _SAT_RESULT_H_
#define _SAT_RESULT_H_

#include <map>

#include "Variable.h"

enum AddAssignmentResult {
  NO_CONFLICT = 1,
  ASSIGNMENT_CONFLICT };

class SATResult
{
 private:
  bool m_isUnsat;
  map<Variable*, bool>* m_truthAssignment;

 public:
  SATResult();
  ~SATResult();
  bool operator==(SATResult* other);
  AddAssignmentResult AddAssignment(Variable* v, bool truthVal);
};

#endif
