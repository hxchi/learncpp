#include "Person.h"
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;

int main()
{
  Person p1("xingxing", "weihai");
  Person p2;
  read(p2, cin);
  print(p1, cout) << endl;
  print(p2, cout) << endl;

  return 0;
}
