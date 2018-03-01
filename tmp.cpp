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
  int n;
  char y[10] = "nsta";
  char *x = y;
  n = strlen(x);
  *x = x[n];
  x++;
  printf("x=%s\n", x);		// x=sta
  printf("y=%s\n", y);		// y=
  
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
