#ifndef _SAT_RESULT_H_
#define _SAT_RESULT_H_

#include <map>

#include "Variable.h"

enum AddAssignmentResult {
  SAT = 1,
  UNSAT };

class SATResult
{
 private:
  bool m_isUnsat;
  map<Formula*, bool>* m_truthAssignment;

 public:
  SATResult(AddAssignmentResult res);
  ~SATResult();

  bool Equals(const SATResult* other);
  bool SameAssignment(const SATResult* other);
  bool TruthValue(Formula* f);
  bool IsSAT();
  unsigned int Size();

  AddAssignmentResult AddAssignment(Formula* f, bool truthVal);
  void RemoveAssignment(Formula* f);
};

#endif
