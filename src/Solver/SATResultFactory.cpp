#include "SATResultFactory.h"

SATResultFactory* satResFactory;

SATResult* SATResultFactory::MakeSATResult()
{
  SATResult* newRes = new SATResult(SAT);
  m_allSATResults->push_back(newRes);
  return newRes;
}

SATResult* SATResultFactory::MakeUnSATResult()
{
  SATResult* newUnSATRes = new SATResult(UNSAT);
  m_allSATResults->push_back(newUnSATRes);
  return newUnSATRes;
}

void SATResultFactory::MakeSATResultFactory()
{
  vector<SATResult*>* allResults = new vector<SATResult*>();
  satResFactory = new SATResultFactory();
  satResFactory->m_allSATResults = allResults;
}

void SATResultFactory::TearDownSATResultFactory()
{
  vector<SATResult*> allResults = *(satResFactory->m_allSATResults);
  for (auto result : allResults) {
    delete result;
  }
  delete satResFactory->m_allSATResults;
  delete satResFactory;
}
