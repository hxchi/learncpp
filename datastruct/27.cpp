//	将中缀表达式转变为后缀表达式

#include <stdio.h>
#include <stdlib.h>		//	atof()
#include <math.h>
#include <ctype.h>		//	isdigit()

//	宏定义
#define MAX_SIZE 		20
#define INCREAM_SIZE 	10
#define MAX_BUFFER		10

//	别名
typedef char ElemType;	//

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
 	ElemType c;		//	用于按字符读取键盘数据
 	ElemType d;		//	用于接收运算符的弹栈

 	_initStack(&s);

 	printf("输入中缀表达式（以#作为结束）：\n");
 	scanf("%c", &c);

 	while(c != '#'){
 		while(isdigit(c)){
 			printf("%c", c);
 			scanf("%c", &c);
 			if(!isdigit(c)){
 				printf(" ");
 				break;
 			}
 		}

 		if(')' == c){		//	为什么要把c写在右边？
 			_pop(&s, &d);
 			while('(' != d){
 				printf("%c ", d);
 				_pop(&s, &d);
 			}
 		}
 		else if('+' == c || '-' == c){
 			if(!_lengthStack(s)){
 				_push(&s, c);
 			}
 			else{
 				do{
 					_pop(&s, &d);
 					if('(' == d){
 						_push(&s, d);
 					}
 					else{
 						printf("%c ", d);
 					}
 				}while(_lengthStack(s) && '(' != d);
 				_push(&s, c);
 			}
 		}
 		else if('*' == c || '/' == c || '(' == c){
 			_push(&s, c);
 		}
 		else if('#' == c){		//	为什么需要？
 			break;
 		}
 		else{
 			printf("输入错误\n");
 			return -1;
 		}
 		scanf("%c ", &c);
 	}

 	//	输出栈内遗留数据
	while(_lengthStack(s)){
		_pop(&s, &d);
		printf("%c ", d);
	}

	printf("\n");
 	return 0;
 }


 //	转化中可以遇到的情况很多，不知道怎么归纳？

 //	是否可以使用递归？

