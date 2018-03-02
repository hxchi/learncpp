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

int func0(const char *x);
void func1(const char *x);

int main()
{
  const char a[] = "12345";
  func1(a);
  func1("23456");
  
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


void func1(const char *x)
{
  while(*x){
    switch (*x){
      case 48 : cout << 0;
	break;
      case 49 : cout << 1;
	break;
      case 50 : cout << 2;
	break;
      case 51 : cout << 3;
	break;
      case 52 : cout << 4;
	break;
      case 53 : cout << 5;
	break;
      case 54 : cout << 6;
	break;
      case 55 : cout << 7;
	break;
      case 56 : cout << 8;
	break;
      case 57 : cout << 9;
	break;
      default : cout << "有非数字字符串，报错。" << endl;
	break;
    }
    ++x;
  }
  cout << endl;
}
