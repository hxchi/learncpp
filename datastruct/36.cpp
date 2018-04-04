//	BF算法实现子串与主串的模式匹配
//	很暴力的算法

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	//	strlen()

const unsigned int MAX_SIZE = 100;

int main(int argc, char const *argv[])
{
	char str[MAX_SIZE] = "i am f...fucking love fis...fisc.com...fis";
	char strSon[MAX_SIZE] = "fishc";

	int i = 0;	//	str下标
	int j = 0;	//	strSon下标
	int k = 0;	//	循环内strSon下标
	bool bl;	//	0——模式匹配失败，1——模式匹配成功

	while(strSon[j] != '\0'){
		while(strSon[j] != str[i]){	//	寻找第一个匹配的字符
			i++;
			if(i >= strlen(str)){
				break;
			}
		}

		if(strSon[j] == str[i]){	//	找到后进行后续匹配
			for(k = 0; k < strlen(strSon); k++){
				if(strSon[k] != str[i++] || i >=  strlen(str)){
					bl = 0;
					break;
				}
				else{
					bl = 1;
				}
			}
			if(!bl){
				printf("匹配失败，重新寻找，从%d开始\n", i-k);
				i = i - k;
				j = 0;
				continue;
			}
			if(bl){
				break;
			}
		}

		if(i >= strlen(str)){
				break;
		}

		j++;
	}

	if(bl){
		printf("模式匹配成功\n");
		printf("子串开始于第%d个字符\n", (i-k+1));
	}
	else{
		printf("匹配失败\n");
	}

	return 0;
}


//	最外面不使用for循环？
//	因为使用for循环的话，相当与每次循环过后必然会执行就j++，不能进行重新从字串头开始搜索。

