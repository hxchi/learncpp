//	二进制转八进制

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//	宏定义
#define MAX_SIZE 		20
#define INCREAM_SIZE 	10

//	别名
typedef char ElemType;	//	这里为什么要用char？

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
	sqStack s;	//	存储二进制，以字符的形式存入
	sqStack m;	//	存储八进制，以字符的形式存入
	ElemType c;	//	用于栈s
	ElemType d;	//	用于栈m
	int lens, lenm, sum = 0;

	_initStack(&s);
	_initStack(&m);

	printf("请输入二进制字符串（输入#表示结束）：");
	while(1){	//	通过while循环读取键盘缓冲区里面的内容
		scanf("%c", &c);
		if(c == '#'){
			break;
		}
		_push(&s, c);
	}
	getchar();		//	为了读取回车'\n'
	
	lens = _lengthStack(s);
	for(int i = 0; i < lens; i++){
		_pop(&s, &c);
		printf("%c\n", c);
		sum += ((int)(c - '0')) * pow(2.0, (double)(i%3));
		if(i%3 == 2){
			d = '0' + sum;
			//	测试中间结果
			// printf("sum = %d\n", sum);
			// printf("d = %c\n", d);
			_push(&m, d);
			sum = 0;
		}
	}

	lenm = _lengthStack(m);
	printf("对应的八进制数为：");
	for(int i = 0; i < lenm; i++){
		_pop(&m, &d);
		printf("%c", d);
	}
	printf("\n");
	
	return 0;
}

