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
void func2(const string &a, int b[26]);
bool func3(const string &rht, const string &lft);

int main()
{
  // 测试func1
  // const char a[] = "-12345";
  // cout << func1(a) << endl;
  // cout << func1("23a456") << endl;
  // cout << func1("+234567") << endl;

  // 测试func2
  int b[26] = {0};
  string s1 = "abccdefghlmnopqrs";
  string s2 = "dcgsrqpomc";
  string s3 = "dcgsrqpozc";
  if(func3(s1, s3))
    cout << "包含！" << endl;
  else
    cout << "不包含！" << endl;
  // cout << s1.length() << endl;
  // cout << s1.size() << endl;
  // func2(s1, b);
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


void func2(const string & a, int b[26])
{
  for(int i = 0; i < a.size(); i++){
    if((a[i] >= 'a') && (a[i] <= 'z')){
      b[a[i] - 'a']++;
    }
    else if((a[i] >= 'A') && (a[i] <= 'Z')){
      b[a[i] - 'A']++;
    }
  }

  // 测试
  // for(int i = 0; i < 26; ++i){
  //   cout << b[i] << " ";
  // }
  // cout << endl;
}

bool func3(const string &rht, const string &lft)
{
  int a[26] = {0};
  int b[26] = {0};

  func2(rht, a);
  func2(lft, b);

  for(int i = 0; i < 26; i++){
    if(b[i] > 0){
      if(a[i] == 0)
	return 0;
    }
  }
  return 1;
}
