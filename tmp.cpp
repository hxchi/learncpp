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
const int N = 40;		// 两倍数组a的长度，可大不可小

int main()
{
  const char *a = "aabcd";
  const char *b = "cdaa";

  int m = strlen(a);
  int n = strlen(b);
  char c[N];	                // 为了调用字符串数组的函数，这里必须要是字符串数组
  strcpy(c, a);			// 测试后，这边如果使用strcat函数，第一个字符会是空格
  strcat(c, a);
  
  bool bf = 1;			// 用来当标识符
  for(int i = 0; i <= (2*m-n); ++i){
    bf = 1;
    for(int j = 0; j < n; ++j){
      if(b[j] != c[i+j]){
	bf = 0;
	break;
      }
    }
    if(bf){
      cout << b << endl;
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
