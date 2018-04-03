//	求解逆波兰表达式

#include <stdio.h>
#include <stdlib.h>		//	atof()
#include <math.h>
#include <ctype.h>		//	isdigit()

//	宏定义
#define MAX_SIZE 		20
#define INCREAM_SIZE 	10
#define MAX_BUFFER		10

//	别名
typedef double ElemType;	//

//	定义栈结构体
typedef struct sqStack{
	ElemType *top;
	ElemType *base;
	int stackSize;
} sqStack;


/*************************************************************************
 *							栈的函数      						         *
 *************************************************************************/

//	初始化函数
void _initStack(sqStack *s)
{
	s->base = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
	if(!(s->base)){
		printf("申请内存错误\n");
		exit(0);
	}

	s->top = s->base;
	s->stackSize = MAX_SIZE;
}	

//	入栈操作
//	e为入栈的元素
void _push(sqStack *s, ElemType e)
{
	//	如果初始化的栈空间不够，需要重新分配
	if((s->top - s->base) >= s->stackSize){
		(s->base) = (ElemType *)realloc(s->base, (s->stackSize + INCREAM_SIZE)*sizeof(ElemType));
		if(!(s->base)){
			printf("申请内存错误\n");
			exit(0);
		}
	}

	*(s->top) = e;
	s->top++;
}

//	出栈操作
//	e用来记录出栈的地址。为什么这里使用地址呢？
void _pop(sqStack *s, ElemType *e)
{
	if(s->top == s->base){
		return;
	}
	s->top--;
	*e = *(s->top);
}


//	求栈当前容量的函数
int _lengthStack(sqStack s)
{
	return (s.top - s.base);
}


/*************************************************************************
 *							 主函数	      						         *
 *************************************************************************/
int main(int argc, char const *argv[])
{
	sqStack s;	
	char c;			//	接收输入
	ElemType d, e;	//	接收pop数据
	char str[MAX_BUFFER];	//	定义缓冲区
	int i = 0;

	_initStack(&s);

	printf("请输入逆波兰表达式（用空格隔开，以#结束）：\n");
	scanf("%c", &c);

	while(c != '#'){
		while(isdigit(c) || c == '.'){		//	定义一个缓冲区，用于过滤数字
			str[i++] = c;
			str[i] = '\0';	//	为什么需要？

			if(i >= 10){
				printf("输入的单个数据过大\n");
				return -1;
			}
			scanf("%c", &c);
			if(c == ' '){
				d = atof(str);	//	将字符串转化为浮点数
				_push(&s, d);
				i = 0;
				break;
			}
		}

		switch (c){
			case '+':
				_pop(&s, &d);
				_pop(&s, &e);
				_push(&s, d + e);
				break;
			case '-':
				_pop(&s, &d);
				_pop(&s, &e);
				_push(&s, e - d);
				break;
			case '*':
				_pop(&s, &d);
				_pop(&s, &e);
				_push(&s, d * e);
				break;
			case '/':
				_pop(&s, &d);
				_pop(&s, &e);
				if(e != 0){
					_push(&s, e / d);
				}
				else{
					printf("分母不能为0\n");
					return -1;
				}
				break;
		}

		scanf("%c", &c);
	}

	getchar();		//	读取'\n'
	_pop(&s, &d);
	printf("此表达式的结果是：%f\n", d);

	return 0;
}


//	怎么解决将多位数读取为int/double？（不用cin）
//	设置读取缓冲区，将在遇到空格之前的所有字符写入到一个字符串中，再通过atof()函数进行转换


