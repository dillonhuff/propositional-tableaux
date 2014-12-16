#ifndef _BINARY_CONNECTIVE_H_
#define _BINARY_CONNECTIVE_H_

#include "Formula.h"

class BinaryConnective : public Formula
{
 protected:
  Formula* m_left;
  Formula* m_right;

 public:
  Formula* Left();
  Formula* Right();
};

#endif
