#ifndef _FORMULA_H_
#define _FORMULA_H_

class Formula
{
 public:
  virtual bool IsConjunction();
  virtual bool IsDisjunction();
  virtual bool IsNegation();
  virtual bool IsVariable();
  virtual ~Formula();
};

#endif
