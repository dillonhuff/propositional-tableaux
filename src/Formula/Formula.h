#ifndef _FORMULA_H_
#define _FORMULA_H_

class Formula
{
 public:
  virtual ~Formula();

  virtual bool IsConjunction();
  virtual bool IsDisjunction();
  virtual bool IsNegation();
  virtual bool IsVariable();

  virtual bool operator==(Formula* other) = 0;

  virtual void PrettyPrint() = 0;
};

#endif
