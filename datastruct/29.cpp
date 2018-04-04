//	计算器code
//	采用逆波兰表达式
//	模板范型

#include <stdio.h>
#include <stdlib.h>		//	atof()
#include <math.h>
#include <ctype.h>		//	isdigit()

//	宏定义
#define MAX_SIZE 		42
#define INCREAM_SIZE 	10
#define MAX_BUFFER		10


//	定义栈的类
template <class ElemType>
class SqStack{
public:
	SqStack();
	~SqStack();

	void _push(ElemType e);
	void _pop(ElemType *e);
	int _lengthStack();

private:
	ElemType *top;
	ElemType *base;
	int stackSize;
};


/*************************************************************************
 *							栈的成员函数      						         *
 *************************************************************************/

//	构造函数
template <class ElemType>
SqStack<ElemType>::SqStack()
{
	base = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
	if(!base){
		printf("申请内存错误\n");
		exit(0);
	}

	top = base;
	stackSize = MAX_SIZE;
}	


//	析构函数
template <class ElemType>
SqStack<ElemType>::~SqStack()
{

}


//	入栈操作
//	e为入栈的元素
template <class ElemType>
void SqStack<ElemType>::_push(ElemType e)
{
	//	如果初始化的栈空间不够，需要重新分配
	if((top - base) >= stackSize){
		base = (ElemType *)realloc(base, (stackSize + INCREAM_SIZE)*sizeof(ElemType));
		if(!base){
			printf("申请内存错误\n");
			exit(0);
		}
	}


	*top = e;
	top++;
}

//	出栈操作
template <class ElemType>
void SqStack<ElemType>::_pop(ElemType *e)
{
	if(top == base){
		return;
	}
	top--;
	*e = *top;
}


//	求栈当前容量的函数
template <class ElemType>
int SqStack<ElemType>:: _lengthStack()
{
	return (top - base);
}


//	中缀表达式转化为后缀表达式
//	参数strPolish用于存储逆波兰表达式
void _toReversePolish(char *strPolish)
{
	SqStack<char> s;
	char c;		//	用于按字符读取键盘数据
	char d;		//	用于接收运算符的弹栈

	char i = 0;	//	逆波兰表达式的下标

	printf("输入中缀表达式（以#作为结束）：\n");
	scanf("%c", &c);

	while(c != '#'){		//	读取键盘输入
		while(isdigit(c)){
 			// printf("%c", c);
 			*(strPolish++) = c;
 			scanf("%c", &c);
 			if(!isdigit(c)){
 				// printf(" ");
 				*(strPolish++) = ' ';
 				break;
 			}
 		}

 		if(')' == c){		//	为什么要把c写在右边？
 			s._pop(&d);
 			while('(' != d){
 				// printf("%c ", d);
 				*(strPolish++) = d;
 				*(strPolish++) = ' ';
 				s._pop(&d);
 			}
 		}
 		else if('+' == c || '-' == c){
 			if(!(s._lengthStack())){
 				s._push(c);
 			}
 			else{
 				do{
 					s._pop(&d);
 					if('(' == d){
 						s._push(d);
 					}
 					else{
 						// printf("%c ", d);
 						*(strPolish++) = d;
 						*(strPolish++) = ' ';
 					}
 				}while(s._lengthStack() && '(' != d);
 				s._push(c);
 			}
 		}
 		else if('*' == c || '/' == c || '(' == c){
 			s._push(c);
 		}
 		else if('#' == c){		
 			break;
 		}
 		else if(' ' == c){		//	过滤空格
 			scanf("%c", &c);
 			continue;
 		}
 		else{
 			printf("输入错误\n");
 			return;
 		}
 		scanf("%c ", &c);
 	}

 	//	输出栈内遗留数据
	while(s._lengthStack()){
		s._pop(&d);
		// printf("%c ", d);
		*(strPolish++) = d;
		*(strPolish++) = ' ';
	}

	// printf("\n");
	*(strPolish++) = '#';	//	添加结束符
	*(strPolish++) = '\0';
 }


int main(int argc, char const *argv[])
{
	char strPolish[MAX_SIZE];
	_toReversePolish(strPolish);
	// printf("主函数内：%s\n", strPolish);

	SqStack<double> s;	
	char c;			//	接收输入
	double d, e;	//	接收pop数据
	char str[MAX_BUFFER];	//	定义缓冲区
	int j = 0;		//	str下标
	int i = 0;		//	strPolish下标

	c = strPolish[i++];

	while(c != '#'){
		while(isdigit(c) || c == '.'){		//	定义一个缓冲区，用于过滤数字
			str[j++] = c;
			str[j] = '\0';	//	为什么需要？——以此判断c风格字符串

			if(j >= 10){
				printf("输入的单个数据过大\n");
				return -1;
			}
			c = strPolish[i++];
			if(' ' == c){
				d = atof(str);	//	将字符串转化为浮点数
				s._push(d);
				// printf("传入数据：%f\n", d);
				j = 0;
				break;
			}
		}

		switch (c){
			case '+':
				s._pop(&d);
				s._pop(&e);
				s._push(d + e);
				// printf("分步结果：%f\n", d + e);
				break;
			case '-':
				s._pop(&d);
				s._pop(&e);
				s._push(e - d);
				// printf("分步结果：%f\n", e - d);
				break;
			case '*':
				s._pop(&d);
				s._pop(&e);
				s._push(d * e);
				// printf("分步结果：%f\n", d * e);
				break;
			case '/':
				s._pop(&d);
				s._pop(&e);
				if(e != 0){
					s._push(e / d);
					// printf("分步结果：%f\n", e / d);
				}
				else{
					printf("分母不能为0\n");
					return -1;
				}
				break;
		}

		c = strPolish[i++];
	}

	// getchar();		//	读取'\n'
	s._pop(&d);
	printf("此表达式的结果是：%f\n", d);

	return 0;
}

 //	需要解决的问题：在转换逆波兰表达式和计算逆波兰表达式的时候用到的ElemType类型不一致？
 //	解决方式一：模板范型编程（类的范型编程）
 //	引发的问题：不能将栈声明为指针，会报错

//	问题二：如何在函数内将转化好的逆波兰表达式保存？
//	如果作为函数返回值返回：作为局部变量，地址会随着函数调用结束而消失，作为返回值不成立。
//	所以应该作为函数参数，传入的参数只能是指针，所以在函数中的调用需要调整。（如上）

//	发生莫名其妙的错误，后来发现是因为数组长度太小。