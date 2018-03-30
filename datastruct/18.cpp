//	约瑟夫环问题代码实现

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node * next;
} Node;
typedef struct Node* LoopList;


//	初始化循环链表
//	参数i表示循环链表的结点数
//	将每个结点的data初始化为0
void _initLoopList(LoopList *L, int i)
{
	LoopList p, q;
	int j = 1;

	while(j <= i){
		if(j == 1){
			(*L) = (LoopList)malloc(sizeof(Node));
			if(!(*L)){
				printf("申请内存失败\n");
				exit(0);
			}
			(*L)->data = 0;
			(*L)->next = (*L);
		}
		else{
			for(p = (*L); (p->next) != (*L); p = p->next);	//	寻找最后一个结点

			q = (LoopList)malloc(sizeof(Node));
			q->data = 0;

			q->next = p->next;
			p->next = q;
		}
		j++;
	}
}


// 返回链表长度
int _numberLoopList(LoopList *L)
{
	LoopList p;
	int num = 1;

	for(p = (*L); (p->next) != (*L); p = p->next){
		num++;
	}

	return num;
}


//	为链表L赋值
//	赋值完后链表的结果是1, 2, 3, 4....
void _creatLoopList(LoopList *L)
{
	LoopList p;
	int i = 1;

	for(p = (*L); (p->next) != (*L); p = p->next);	//	寻找最后一个结点

	for( ; i <=_numberLoopList(L); i++){
		p = p->next;
		p->data = i;
	}
}


//	遍历链表
void _coutLoopList(LoopList *L)
{
	LoopList p;
	p = (*L);

	printf("循环链表的内容是： \n");
	while(1){
		printf("%d ", p->data);
		p = p->next;
		if(p == (*L)){
			break;
		}
	}
	printf("\n");
}


//	第2个参数是删除条件
//	比如如果是3,则删除第i个结点，并将原先的第i+1个结点返回
//	需要做输入检查，希望i的值大于1
LoopList _deleteSomeOne(LoopList *L, int i)
{
	if(i <= 1){
		printf("参数2的值应大于等于2\n");
		exit(0);
	}

	LoopList p, q;
	for(p = (*L); (p->next) != (*L); p = p->next);	//	寻找最后一个结点

	int j = 1;

	for( ; j < i; j++){
		p = p->next;
		q = p;		//	为了循环，同步，只能将这两个这么写
	}
	p->next = q->next->next;

	return q->next;
}

//	main函数
int main(int argc, char const *argv[])
{
	LoopList L;
	int i = 1;
	_initLoopList(&L, 41);
	_creatLoopList(&L);
	LoopList q = L;		//	作为第一个结点的记录
	std::cout << q << "\n\n";

	printf("链表L中结点的个数是： %d.\n", _numberLoopList(&L));

	LoopList p;
	for(p = L; (p->next) != L; p = p->next);

	//	输出结点指针
	for(int j = 1; j <= _numberLoopList(&L); j++){
		std::cout << p->next << "\n";
		p = p->next;
	}
	printf("\n\n");

	while(_numberLoopList(&L) >= 3){
		L = _deleteSomeOne(&L, 3);
		_creatLoopList(&L);
		printf("第%d轮后：\n", i);
		_coutLoopList(&L);
		printf("\n\n");
		i++;
	}

	//	输出结点指针
	for(p = L; (p->next) != L; p = p->next);

	for(int j = 1; j <= _numberLoopList(&L); j++){
		std::cout << p->next << "\n";
		p = p->next;
	}

	_coutLoopList(&L);
	printf("链表L中结点的个数是： %d.\n", _numberLoopList(&L));
	printf("\n\n");

	int tmpLength = _numberLoopList(&L);
	for(int m = 1; m <= tmpLength; m++){
		std::cout << "size of Node = " << sizeof(Node) << "\n";
		std::cout << "L-q = " << L-q << "\n";
		std::cout << (L-q)*sizeof(LoopList)/sizeof(Node)+1 << "\n";
		L = L->next;
	}

	return 0;
}

//	如何把剩余的两个结点在原链表中的位置输出？
//	我的做法是通过指针大小来获取原先的位置