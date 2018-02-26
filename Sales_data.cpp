#include "Sales_data.h"
#include <iostream>
#include <string>

using std::cout; using std::endl; using std::cin;
using std::string;

int main()
{
  Sales_data s1("hxc", 10, 19.99);
  Sales_data s2(cin);

  Sales_data s3 = add(s1, s2);

  print(cout, s1) << endl;
  print(cout, s2) << endl;
  print(cout, s3) << endl;

  return 0;
}
