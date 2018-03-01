// c
#include <stdio.h>
#include <stdlib.h>

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
  const int N = 20;
  int a[N];
  for(int i = 0; i < N; i++){	// 构造出符合的数组，存在某个数，大于前面的数同时小于后面的数
    if( i == 10)
      a[i] = 5;
    else if(i < 10)
      a[i] = rand() % 5;
    else
      a[i] = rand() % 3 + 6; 
  }

  bool bf = 1;
  for(int i = 1; i <= N-1; ++i){
    bf = 1;
    for(int j = 0; j < i; ++j){
      if(a[j] >= a[i]){
	bf = 0;
	break;
      }
    }
    for(int j = i+1; j < N; ++j){
      if(a[j] <= a[i]){
	bf = 0;
	break;
      }
    }
    if(bf)
      cout << a[i] << endl;
  }
  
  // 测试
  for(int i = 0; i < N; i++){
    cout << a[i] << " ";
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
