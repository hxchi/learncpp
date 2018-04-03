//	栈


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>	//	pow

//	宏定义
#define STACK_MAX_SIZE 100
#define STACK_INCREAM 10


typedef int ElemType;

//	定义栈
typedef struct{
	ElemType *base;		//	栈底
	ElemType *top;		//	栈顶
	int stackSize;		//	栈可用的最大空间
}sqStack;


//	初始化一个栈
void _initStack(sqStack *s)
{
	//	base申请的内存空间就是整个栈的内存空间
	s->base = (ElemType *)malloc(STACK_MAX_SIZE * sizeof(ElemType));

	if(!(s->base)){
		printf("申请内存错误\n");
		exit(0);
	}

	s->top = s->base;	//	空栈，栈底就是栈顶
	s->stackSize = STACK_MAX_SIZE;

	//	测试base+1的地址
	// printf("s->base: %x\n", s->base);
	// printf("s->base + 1: %x\n", ++s->base);		//	注意这里需要++在前 
}


//	压栈，也就是在栈顶（表尾）插入元素
//	第二个参数n表示压入的元素
void push(sqStack *s, ElemType e)
{
	//	判断栈是否已满，若是已满，需要追加空间
	if((s->top - s->base) >= s->stackSize){		
		s->base = (ElemType *)realloc(s->base, (s->stackSize+STACK_INCREAM)*sizeof(ElemType));
		if(!(s->base)){
			printf("申请内存错误\n");
			exit(0);
		}

		s->top = s->base + s->stackSize;	//	设置表头
		s->stackSize = s->stackSize + STACK_INCREAM;	//	设置栈的最大容量
	}

	//	检查栈的内存占用情况
	// printf("s->base: %x\n", s->base);
	// printf("s->top: %x\n", s->top);
	// printf("s->top - s->base: %d\n\n", s->top - s->base);	//	此处的差值和s的类型也有关系

	*(s->top) = e;
	s->top++;
}


//	弹栈，也就是从栈顶（表尾）弹出元素
//	第二个参数n表示弹出的元素的个数
void pop(sqStack *s, int n)
{
	for(int i = 1; i <= n; i++){
		if(s->top != s->base){
			s->top--;	//	先要减一个，top指向栈顶（待存储），没有内容的
			printf("%d\n", *(s->top));
		}
	}
}


//	清空一个栈
//	注意不是销毁，栈本身的物理空间并没有发生变化
void _clearStack(sqStack *s)
{
	//	空栈的标准就是栈顶和栈底重合
	s->top = s->base;
}


//	销毁一个栈
//	将该栈从内存中移除
void _deleteStack(sqStack *s)
{
	int len;	//	表示栈的空间

	len = s->stackSize;
	for(int i = 0; i < len; i++){
		free(s->base);
		s->base++;	//	只会移动base类型的长度
	}

	s->base = s->top = NULL;
	s->stackSize = 0;
}


//	计算栈的当前容量（不是栈的最大容量）
int _lengthStack(sqStack *s)
{
	return (s->top - s->base);
}


//	将二进制数转换为十进制数
int _binToDec(sqStack *s)
{
	int len = _lengthStack(s);	//	记录该栈的当前长度
	printf("当前栈的长度为：%d\n", len);
	int sum = 0;	//	转化后的十进制数

	for(int i = 0; i < len; i++){
		s->top--;
		sum += (*(s->top))*pow(2.0, (double)i);

		// //	输出测试
		// printf("s->top：%d\n", *(s->top));
		// printf("pow：%d\n", (int)pow(2.0, (double)i));
		// printf("sum = %d\n\n", sum);
	}

	return sum;
}

//	main函数
int main(int argc, char const *argv[])
{
	sqStack s;
	_initStack(&s);
	
	int opt = 0;
	while(1){
		printf("请输入要push的数字：");
		scanf("%d", &opt);
		if(opt == 42){
			break;
		}

		push(&s, opt);
	}

	printf("对应的十进制为：%d\n", _binToDec(&s));
	

	return 0;
}


//	如果栈的空间一直够用，那么top的地址按照每次（ElemType）的尺寸递增
//	如果栈的空间不够，那么需要重新申请空间，这时不能只申请后面增加的部分，会导致内存空间不连续，从而引发无法访问的问题
//	解决上述问题的方法是利用realloc()函数，重新分配内存，保证原先那部分内存的数据跟着移动