#ifndef _CONJUNCTION_H_
#define _CONJUNCTION_H_

#include "BinaryConnective.h"

class Conjunction : public BinaryConnective
{
 public:
  Conjunction(Formula* left, Formula* right);

  virtual bool IsConjunction();
};

#endif
