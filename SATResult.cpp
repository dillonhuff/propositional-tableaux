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
  m_truthAssignment = new map<Formula*, bool>();
}

SATResult::~SATResult()
{
  delete m_truthAssignment;
}

bool SATResult::Equals(const SATResult* other)
{
  return this->m_isUnsat == other->m_isUnsat;
}

bool SATResult::SameAssignment(const SATResult* other)
{
  if (this->m_isUnsat != other->m_isUnsat) {
    return false;
  }

  map<Formula*, bool>* thisTA = this->m_truthAssignment;
  map<Formula*, bool>* otherTA = other->m_truthAssignment;

  return thisTA->size() == otherTA->size()
    && std::equal(thisTA->begin(), thisTA->end(), otherTA->begin());
}

AddAssignmentResult SATResult::AddAssignment(Formula* f, bool truthVal)
{
  if (m_truthAssignment->count(f) > 0) {
    bool currentTruthVal = m_truthAssignment->find(f)->second;
    if (currentTruthVal != truthVal) {
      m_isUnsat = true;
      return UNSAT;
    }
  }
  (*m_truthAssignment)[f] = truthVal;
  return SAT;
}
