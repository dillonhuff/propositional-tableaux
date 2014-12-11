#include "SATResult.h"
#include "Variable.h"

SATResult::SATResult()
{
  m_isUnsat = false;
  m_truthAssignment = new map<Variable*, bool>();
}

SATResult::~SATResult()
{
  delete m_truthAssignment;
}

bool SATResult::operator==(SATResult* other)
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
      return ASSIGNMENT_CONFLICT;
    }
  }
  (*m_truthAssignment)[v] = truthVal;
  return NO_CONFLICT;
}
