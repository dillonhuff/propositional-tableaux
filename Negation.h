#ifndef _NEGATION_H_
#define _NEGATION_H_

#include "Formula.h"

class Negation : public Formula
{
 public:
  Negation(Formula* f);
};

#endif
