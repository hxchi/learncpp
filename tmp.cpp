// c
#include <stdio.h>
#include <stdlib.h>

// cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::cin; using std::cout; using std::endl;
using std::vector; using std::set; using std::multiset;
using std::min_element; using std::max_element;


int main()
{
  int a[6] = {1, 2, 1, 1, 1, 3};
  int b[5] = {1, 2, 2, 2, 3};

  int bcnt[5] = {0};
  for(int i = 0; i < (sizeof(b)/sizeof(int)); ++i){
    ++bcnt[i];
    for(int j = 0; j < i; ++j){
      if(b[i] == b[j])
	++bcnt[i];
    }
  }

  for(int i = 0; i < (sizeof(b)/sizeof(int)); ++i){
    if(bcnt[i] >= (sizeof(b)/sizeof(int))/2){
      cout << b[i] << endl;
      break;
    }
  }

  return 0;
  
  
  // 测试
}


// 函数定义
