// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// cpp
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;
using std::min_element; using std::max_element;
using std::string; 

int func(const char *x);

int main()
{
  char ch[10] = "value";
  char * ch1 = ch;
  cout << sizeof(ch) << endl;	// 输出10
  cout << sizeof(ch1) << endl;	// 输出8
  cout <<  endl;
  cout << strlen(ch) << endl;	// 输出5
  cout << strlen(ch1) << endl;	// 输出5
  
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
