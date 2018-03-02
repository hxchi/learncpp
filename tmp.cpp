// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>		// std::numeric_limits::max()

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

int func0(const char *x);
long long func1(const char *x);

int main()
{
  const char a[] = "-12345";
  cout << func1(a) << endl;
  cout << func1("23a456") << endl;
  cout << func1("+234567") << endl;
  
  return 0;
}


// 函数定义
int func0(const char *x)
{
  const char *y = x;
  while(*y++);
  // cout << "y = " << y << endl;
  // cout << "x = " << x << endl;
  return (y-x-1);
}


long long func1(const char *x)
{
  long long a = 0;

  bool bl = 1;			// 1代表是正数，0代表是负数
  if(*x == '+'){		// 先对第一个字符进行判断
    bl = 1;
    ++x;
  }
  else if(*x == '-'){
    bl = 0;
    ++x;
  }
 
  while(*x){
    if((*x >= '0') && (*x <= '9')){
      a = 10*a + (*x - '0');
      if(a > std::numeric_limits<int>::max()){
	a = 0;
	break;
      }
      ++x;
    }
    else{
      a = 0;
      break;
    }
  }

  if(!bl)
    a = - a;
  
  return a;
}
