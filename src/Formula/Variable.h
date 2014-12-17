#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <string>

#include "Formula.h"

using namespace std;

class Variable : public Formula
{
 private:
  string* m_name;

 public:
  Variable(string name);
  ~Variable();

  virtual bool IsVariable();

  virtual bool operator==(Formula* other);

  virtual void PrettyPrint();
};

#endif
