// c
#include <stdio.h>
#include <stdlib.h>

// cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;
using std::min_element; using std::max_element;

int func(const char *x);

int main()
{
  cout << func("hxc") << endl;
  
  return 0;
}


// 函数定义
int func(const char *x)
{
  const char *y = x;
  while(*y++);
  // cout << "y = " << y << endl;
  // cout << "x = " << x << endl;
  return (y-x-1);
}
