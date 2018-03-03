// c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits>		// std::numeric_limits::max()
#include <assert.h>		// 函数assert()

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
// 例3
long long func4(const char *a);
long long func5(const char *a, const char *b);
// 例3 答案
void multiply(const char *rht, const char *lft);
// 字符串逆序
void func6(const char *rht, char *lft);
void reverse(char *pb, char *pe);
char* reverseSentence(char *pData);

int main()
{
  // 测试func1
  // const char a[] = "-12345";
  // cout << func1(a) << endl;
  // cout << func1("23a456") << endl;
  // cout << func1("+234567") << endl;

  // 测试func2
  // int b[26] = {0};
  // string s1 = "abccdefghlmnopqrs";
  // string s2 = "dcgsrqpomc";
  // string s3 = "dcgsrqpozc";
  // if(func3(s1, s3))
  //   cout << "包含！" << endl;
  // else
  //   cout << "不包含！" << endl;
  // cout << s1.length() << endl;
  // cout << s1.size() << endl;
  // func2(s1, b);

  // 测试 例3
  // const char *a = "12345";
  // const char *b = "23456";
  // cout << func5(a, b) << endl;

  // 测试 例3 答案
  // multiply("12", "12");
  // multiply("123", "123");
  // multiply("1234", "2453");

  // 测试strlen()
  // const char *c = "Today is Friday!";
  // cout << sizeof(c) << endl;	// 输出是8!
  // cout << strlen(c) << endl;	// 输出是16，是正确的。
  // char *d = new char[strlen(c)];
  // func6(c, d);

  char c[] = "Today is Friday!";
  cout << reverseSentence(c) << endl;
  
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

// 例3
long long func4(const char *a)
{
  long long num = 0;
  while(*a){
    if((*a >= '0') && (*a <= '9')){
      num = 10*num + (*a - '0');
      a++;
    }
  }
  return num;
}

long long func5(const char *a, const char *b)
{
  return func4(a)*func4(b);
}

// 例3 答案
void multiply(const char *rht, const char *lft)
{
  assert((rht != NULL) && (lft != NULL)); // 如果条件语句的返回值为0，那么就终止程序

  int i, j, crht, clft, *s;
  crht = strlen(rht);
  clft = strlen(lft);

  s = (int *)malloc(sizeof(int)*(crht+clft)); // 分配内存
  for(i = 0; i < (crht+clft); i++)	      // 将数组初始化
    s[i] = 0;
  for(i = 0; i < crht; i++)
    for(j = 0; j < clft; j++)
      s[i+j+1] += (rht[i] - '0')*(lft[j] - '0');
  for(i = (crht+clft-1); i >= 0; i--) // 这里实现进位操作
    if(s[i] >= 10){
      s[i-1] += s[i]/10;
      s[i] %= 10;
    }

  char *c = new char[(crht+clft)];
  // char *c = (char *)malloc((crht+clft)*sizeof(char));
  i = 0;
  while(s[i] == 0)
    i++;
  for(j = 0; i < (crht+clft); i++, j++){
    c[j] = s[i] + '0';
    // cout << c[j] << endl;
  }
  c[j] = '\0';

  // for(j = 0; j < (crht+clft); j++)
  //   cout << c[j];
  // cout << endl;
  cout << c << endl;

  free(s);
  // free(c);
  delete [] c;
}




// 字符串逆序
void func6(const char *rht, char *lft)
{
  // 先将字符串实现全逆序
  int n = strlen(rht);
  for(int i = 0; i < n; i++)
    lft[i] = rht[n-i-1];
  cout << lft << endl;		// 连字符串中间的空格也可以输出。
  
  // 通过空格分割单词
  int j = 0;
  for(int i = 0; i < n; i++){
    if(lft[i] == ' '){
      cout << j << endl;
      for(int k = j; k < i; k++)
	lft[k] = lft[i-k-j-1];
      j = i+1;
    }
  }

  cout << lft << endl;
}

void reverse(char *pb, char *pe) 
{
  if(pb == NULL || pe == NULL){	// 类似于assert函数的功能
    return;
  }

  while(pb < pe){		// 交换pb和pe的内容
    char tmp = *pb;
    *pb = *pe;
    *pe = tmp;
    pb ++;
    pe --;
  }
}

char* reverseSentence(char *pData)
{
  if(pData == NULL){
    return NULL;
  }

  char *pBegin = pData;
  char *pEnd = pData;

  while(*pEnd != '\0'){
    pEnd ++;
  }
  pEnd --;			// 去掉空格
  reverse(pBegin, pEnd);
  pBegin = pEnd = pData;
  while(*pBegin != '\0'){
    if(*pBegin == ' '){
      pBegin ++;
      pEnd ++;
      continue;
    }

    else if(*pEnd == ' ' || *pEnd == '\0'){
      reverse(pBegin, --pEnd);
      pBegin = ++pEnd;
    }
    else{
      pEnd++;
    }
  }
  return pData;
}
