//	魔术师发牌问题

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

//	定义循环链表
typedef int ElemType;

struct Node{
	ElemType data;
	struct Node* next;
} Node;
typedef struct Node* LinkList;		//	重命名

//	全局的poker数组
ElemType poker[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

//	初始化循环链表
//	此循环链表为空
void _initLinkList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(Node));
	if(!(*L)){
		printf("不能为链表申请内存空间\n");
		exit(0);
	}

	(*L)->next = (*L);		//	第一个结点指向自己
}


//	第一个参数是链表的首地址
//	第二个参数代表当前填充元素的数组下标
//	第二个参数同时意味着循环次数
void _fillLinkList(LinkList *L, int i)
{
	LinkList p;		//	p表示即将填入的元素
	LinkList q;		//	q代表链表的最后一个结点

	if(i == 12){	//	第一个元素需要特殊对待
		(*L)->data = poker[i];
		p = (*L);
	}
	else{
		p = (LinkList)malloc(sizeof(Node));
		if(!p){
			printf("不能为链表申请内存空间\n");
			exit(0);
		}

		p->data = poker[i];
		
		for(q=(*L); (q->next) != (*L); q = q->next);

		p->next = q->next;
		q->next = p;	//	p作为第一个结点插入，在此后的循环中，p代表第一个结点，q代表最后一个结点
		
		for(int j = 1; j <= (i%(13-i)); j++){
			for(q = p ; (q->next) != p; q = q->next);

			p = q;
		}

		(*L) = p;
	}
}


//	遍历链表
void _coutLoopList(LinkList *L)
{
	LinkList p;
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


//	main函数
int main()
{
	LinkList L;
	std::cout << &L << "\n";
	_initLinkList(&L);
	std::cout << &L << "\n\n";	//	经过初始化和未经过初始化的地址是一样的，是否可以不用初始化
	_coutLoopList(&L);

	for(int i = 12; i >= 0; i--){
		_fillLinkList(&L, i);
	}

	//	遍历链表
	_coutLoopList(&L);

	return 0;
}


//	答案的做法：先将所有的结点的元素设置为0,通过判断该元素是否为零来判断这张牌是否被拿出牌组