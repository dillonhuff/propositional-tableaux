#ifndef SAT_RESULT_FACTORY_H_
#define SAT_RESULT_FACTORY_H_

#include <vector>

#include "SATResult.h"

class SATResultFactory
{
 private:
  vector<SATResult*>* m_allSATResults;

 public:
  SATResult* MakeSATResult();

  static SATResultFactory* MakeSATResultFactory();
  static void TearDownSATResultFactory(SATResultFactory* srf);
};

extern SATResultFactory* satResFactory;

#endif
