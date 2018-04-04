//	BF算法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//	strlen(), c_str()
#include <string>

// 返回子串T在主串S中第pos个字符之后的位置
// 若不存在，则返回0
int _index(std::string S, std::string T)
{
	int i = 0;	// i用于主串S中当前位置下标
	int j = 0;		// j用于子串T中当前位置下标
	
	while(i < strlen(S.c_str()) && j < strlen(T.c_str())){	// i或j其中一个到达尾部即终止搜索！
		if(S[i] == T[j]){	// 若相等则继续下一个元素匹配
			// printf("s: %c t: %c\n", S[i], T[j]);
			i++;
			j++;
		}
		else{				//	如果匹配失败
			i = i-j+1;		//	i回溯到上次匹配首位的下一个元素（效率低下的关键）
			j = 0;			//	j回溯到第一个元素重新匹配
		}
	}
	
	if(j >= strlen(T.c_str())){	//	匹配成功意味着t串被遍历了，即j=strlen(t)
		return i - strlen(T.c_str());
	}
	else{	//	匹配失败
		return 0;
	}
}


//	main函数
int main(int argc, char const *argv[])
{
	std::string s = "i am f...fucking love fis...fishc.com...fis";
	std::string t = "fishc";

	printf("s的长度：%d\n", strlen(s.c_str()));
	printf("t的长度：%d\n", strlen(t.c_str()));
	int k = _index(s, t);
	printf("%d\n", k);

	return 0;
}


//	可以认为在这里，i和j都是循环控制变量。