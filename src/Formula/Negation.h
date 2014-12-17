#ifndef _NEGATION_H_
#define _NEGATION_H_

#include "Formula.h"

class Negation : public Formula
{
 private:
  Formula* m_innerFormula;

 public:
  Negation(Formula* f);

  virtual bool IsNegation();

  virtual bool operator==(Formula* other);

  Formula* InnerFormula();

  virtual void PrettyPrint();
};

#endif
