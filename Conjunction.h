#ifndef _CONJUNCTION_H_
#define _CONJUNCTION_H_

#include "Formula.h"

class Conjunction : public Formula
{
 private:
  Formula* m_left;
  Formula* m_right;

 public:
  Conjunction(Formula* left, Formula* right);

  virtual bool IsConjunction();

  Formula* Left();
  Formula* Right();
};

#endif
