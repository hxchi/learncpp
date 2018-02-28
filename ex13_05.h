#ifndef EX13_05_H
#define EX13_05_H

#include <string>

using std::std;

class HasPtr{
 public:
 HasPtr(const string & s = string()) :
  ps(new string()), i(0) { }
 HasPtr(const HasPtr & hasptr) :
  ps(new string(*hasptr.ps)), i(hasptr.i) { } /* 将对象拷贝到ps所指向的内容 */
  
 private:
  string *ps;
  int i;
};


#endif
