#ifndef _VARIABLE_H_
#define _VARIABLE_H_

using namespace std;

#include <string>

#include "Formula.h"

class Variable : public Formula
{
 private:
  string* m_name;

 public:
  Variable(string name);
  ~Variable();

  virtual bool IsVariable();
};

#endif
