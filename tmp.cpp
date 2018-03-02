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
  const char *a = "ababcabcacbab";
  const char *b = "abcac";

  int m = strlen(a);
  int n = strlen(b);
  if(m < n){
    cout << "找不到匹配的子串！" << endl;
    return -1;
  }
  
  char c[n];
  bool bf = 1;
  for(int i = 0; i <= (m-n); ++i){
    bf = 1;
    for(int j = 0; j < n; ++j){
      if(b[j] != a[i+j]){
	bf = 0;
	break;
      }
    }
    if(bf){
      char c[n];
      memcpy(c, a+i, n);	// 只能是字符串数组，不能是指针。
      cout << c << endl;
      cout << a+i << endl;
    }
  }
  
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
