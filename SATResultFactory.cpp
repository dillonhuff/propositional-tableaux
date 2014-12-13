#include "SATResultFactory.h"

SATResultFactory* satResFactory;

SATResult* SATResultFactory::MakeSATResult()
{
  SATResult* newRes = new SATResult();
  m_allSATResults->push_back(newRes);
  return newRes;
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
