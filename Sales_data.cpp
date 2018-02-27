#include "Sales_data.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout; using std::endl; using std::cin;
using std::string; using std::vector;

int main()
{
  Sales_data s1("hxc", 10, 19.99);
  Sales_data s2(cin);

  Sales_data s3 = add(s1, s2);

  print(cout, s1) << endl;
  print(cout, s2) << endl;
  print(cout, s3) << endl;

  // 测试范型算法
  vector<Sales_data> vs;
  Sales_data tmp;
  while(read(cin, tmp)){
    vs.push_back(tmp);
  }
  sort(vs.begin(), vs.end(), CompareIsbn);
  for(auto i : vs){
    print(cout, i) << endl; 
  }
  
  return 0;
}
