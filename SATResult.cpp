#include <iostream>

#include "SATResult.h"
#include "Variable.h"

SATResult::SATResult(AddAssignmentResult res)
{
  if (res == SAT) {
    m_isUnsat = false;
  } else if (res == UNSAT) {
    m_isUnsat = true;
  } else {
    cout << "ERROR: Unsupported AddAssignmentResult in SATResult::SATResult" << endl;
  }
  m_truthAssignment = new map<Variable*, bool>();
}

SATResult::~SATResult()
{
  delete m_truthAssignment;
}

const bool SATResult::Equals(const SATResult* other)
{
  if (this->m_isUnsat != other->m_isUnsat) {
    return false;
  }

  map<Variable*, bool>* thisTA = this->m_truthAssignment;
  map<Variable*, bool>* otherTA = other->m_truthAssignment;

  return thisTA->size() == otherTA->size()
    && std::equal(thisTA->begin(), thisTA->end(), otherTA->begin());
}

AddAssignmentResult SATResult::AddAssignment(Variable* v, bool truthVal)
{
  if (m_truthAssignment->count(v) > 0) {
    bool currentTruthVal = m_truthAssignment->find(v)->second;
    if (currentTruthVal != truthVal) {
      m_isUnsat = true;
      return UNSAT;
    }
  }
  (*m_truthAssignment)[v] = truthVal;
  return SAT;
}
