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

SATResultFactory* SATResultFactory::MakeSATResultFactory()
{
  vector<SATResult*>* allResults = new vector<SATResult*>();
  SATResultFactory* newFactory = new SATResultFactory();
  newFactory->m_allSATResults = allResults;
  return newFactory;
}

void SATResultFactory::TearDownSATResultFactory(SATResultFactory* srf)
{
  vector<SATResult*> allResults = *srf->m_allSATResults;
  for (auto result : allResults) {
    delete result;
  }
  delete srf->m_allSATResults;
}
