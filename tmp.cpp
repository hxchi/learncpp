// c
#include <stdio.h>

// cpp
#include <iostream>
#include <vector>
#include <set>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;

int *times(int a[], const int n);
int *cal(int * input, int n);

int main()
{
  int a[4] = {2, 3, 4, 5};
  // int *b = times(a, 4);
  int * b = cal(a, 4);

  // 测试
  for(int i = 0; i < 4; i++){
    cout << b[i] << " ";
  }
  cout << endl;
  
  return 0;
}


// 函数定义
int *times(int a[], const int n)
{
  int b[n];
  for(int i = 0; i < n; i++){
    b[i] = a[i];
  }
  int tmp1 = 1, tmp2 = 0;
  int i = 0;
  while(i < n){
    tmp2 = b[i];
    b[i] = 1;
    for(int j = 0; j < n; j++){
      tmp1 *= b[j];
    }
    a[i] = tmp1;
    tmp1 = 1;
    b[i] = tmp2;
    i++;
  }
  return a;
}

int *cal(int * input, int n)
{
  int i;
  int *result = new int[n];
  result[0] = 1;

  for(int i = 1; i < n; ++i){
    result[i] = result[i-1] * input[i-1];
  }
  result[0] = input[n-1];
  for(i = (n-2); i > 0; --i){
    result[i] *= result[0];
    result[0] *= input[i];
  }

  return result;
}
