#ifndef _DISJUNCTION_H_
#define _DISJUNCTION_H_

#include "BinaryConnective.h"

class Disjunction : public BinaryConnective
{
 public:
  Disjunction(Formula* left, Formula* right);
  
  virtual bool IsDisjunction();
};

#endif
