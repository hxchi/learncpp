// KMP算法

#include <stdio.h>
#include <string.h>

#include <string>

// s表示子串
int _indexSon(std::string s, std::string t)
{
  // 判断子串中第一个字符是否和和其他字符相等
  int l;			// 表示与第一个字符相等的字符的位置（从0开始计算）
  for(l = 1; l < strlen(s.c_str()); l++){
    if(s[l] == s[0]){
      break;
    }
  }
  if(l == strlen(s.c_str())){
    l = 0;
  }

  int i = 0;			// i表示s的下标
  int j = 0;			// j表示t的下标
  while(i < strlen(s.c_str()) && j < strlen(t.c_str())){
    if(s[i] == t[j]){		// 如果相等，那么比较下一个
      i++;
      j++;
    }
    else{			// 如果不等，那么回溯
      j = j+1;			// 无需再-i
      i = 0;
    }
  }
  if(i == strlen(s.c_str())){
    return (j-i);
  }
  else{
    return 0;
  }
}


// main函数
int main()
{
  std::string s = "universe";
  std::string t = "the answer of universe is the 42.";

  int l = _indexSon(s, t);

  printf("s在t中成功匹配：%d.\n", l);

  return 0;
}
