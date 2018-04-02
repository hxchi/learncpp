//	判断单链表中是否存在环？
//	有环的定义是指：当尾指针指向单链表中的其中某个元素的时候称之为有环

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0


typedef int Status;		//	Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int ElemType;	//	ElemType类型根据实际情况而定，这里假设为int

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

//	初始化空链表
//	该链表带头结点
Status _initLinkList(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(Node));
	if(!(*L)){
		printf("不能为链表申请内存空间\n");
		return ERROR;
	}

	(*L)->next = NULL;		//	头结点的指针域为空

	return OK;
}


//	返回链表的数据元素的个数
//	前提是链表已经存在
int _lengthLinkList(LinkList *L)
{
	LinkList p = (*L);
	int i = 0;

	for( ; (p->next) != NULL; p = p->next){
		i++;
	}

	return i;
}

//	创建含有n个元素的单链表L（随机产生）
//	该链表带表头
//	这里认为需要自行初始化链表
//	这里认为头插法插入的位置为头结点之前的位置，这样的缺点是插入之后，头结点的指针值是发生了变化的
void _creatLinkListHead_1(LinkList *L, int n)
{
	srand(time(0));

	int i = 1;	//	记录元素个数
	LinkList p;	//	用来表示插入的结点

	(*L) = (LinkList)malloc(sizeof(Node));
	if(!(*L)){
		printf("不能为链表申请内存空间\n");
		exit(0);
	}
	(*L)->next = NULL;

	for( ; i <= n; i++){
		(*L)->data = rand()%99+1;
		p = (LinkList)malloc(sizeof(Node));
		if(!p){
			printf("不能为链表申请内存空间\n");
			exit(0);
		}
		p->next = (*L);
		(*L) = p;
	}
}

//	创建含有n个元素的单链表L（随机产生）
//	该链表带表头
//	这里认为需要自行初始化链表
//	这里认为头插法插入的位置为头结点紧接着的位置，头结点的位置没有发生变化
void _creatLinkListHead_2(LinkList *L, int n)
{
	srand(time(0));

	int i = 1;	//	记录元素个数
	LinkList p;	//	用来表示插入的结点

	(*L) = (LinkList)malloc(sizeof(Node));
	if(!(*L)){
		printf("不能为链表申请内存空间\n");
		exit(0);
	}
	(*L)->next = NULL;

	for( ; i <= n; i++){
		p = (LinkList)malloc(sizeof(Node));
		if(!p){
			printf("不能为链表申请内存空间\n");
			exit(0);
		}
		p->data = rand()%99+1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}


//	创建含有n个元素的单链表L（随机产生）
//	该链表带表头
//	这里认为需要自行初始化链表
void _creatLinkListTail(LinkList *L, int n)
{
	srand(time(0));

	LinkList p;	//	p作为待插入的结点
	LinkList q;	//	q作为链表L的最后一个结点
	int i = 1;

	(*L) = (LinkList)malloc(sizeof(Node));
	if(!(*L)){
		printf("不能为链表申请内存空间\n");
		exit(0);
	}
	(*L)->next = NULL;
	q = (*L);

	for( ; i <= n; i++){
		p = (LinkList)malloc(sizeof(Node));
		if(!p){
			printf("不能为链表申请内存空间\n");
			exit(0);
		}
		p->data = rand()%99+1;
		p->next = NULL;

		q->next = p;
		q = p;
	}

	q->next = (*L)->next->next;	//	创建有环链表
}


//	参数(*L)表示单链表的头指针
//	比较到达某结点所经过的步长是否相同
int _ifExitLoop_1(LinkList *L)
{
	LinkList p = (*L);	//	p是一步一步往前走的
	LinkList q;			//	q是每次都从头开始走的

	int posp = 0;
	int posq = 0;

	while(p){
		q = (*L);
		posq = 0;		//	初始化

		while(q){
			if(q == p){
				if(posq == posp){
					break;	//	表示相同步数，没有发现有环
				}
				else{
					printf("该链表为有环链表，尾指针指向第%d个结点。\n", posq);
					return 1;
				}
			}
			q = q->next;
			posq++;
		}

		p = p->next;
		// printf("p = %d.\n\n", p->data);	//	这个操作不能加，如果p=NULL，那么会导致内存错误
		posp++;
	}

	return 0;
}


//	参数(*L)表示单链表的头指针
//	比较到达某结点所经过的步长是否相同
int _ifExitLoop_2(LinkList *L)
{
	LinkList p = (*L);		//	步长为1
	LinkList q = (*L); 		//	步长为2


	while(p && q && (q->next)){
		p = p->next;
		q = q->next->next;

		printf("p: %d, q: %d\n", p->data, q->data);

		if(p == q){
			return 1;
		}
	}

	return 0;
}


//	main函数
int main()
{
	LinkList L;
	char option;
	ElemType e;

	_initLinkList(&L);
	printf("初始化L后：L的长度是：%d.\n", _lengthLinkList(&L));

	printf("\n1.创建有环链表（尾插法）\n2.创建无环链表（头插法）\n3.判断链表是否有环\n0.退出\n");

	printf("\n请输入你的操作：\n");

	while(option != '0'){
		scanf("%c", &option);

		switch(option){
			case '1':
				_creatLinkListTail(&L, 6);
				break;
			case '2':
				_creatLinkListHead_2(&L, 6);
				break;
			case '3':
				printf("方法一：\n");
				if(_ifExitLoop_1(&L) == 0){
					printf("链表无环\n");
				}

				printf("方法二：\n");
				if(_ifExitLoop_2(&L)){
					printf("链表有环\n");
				}
				else{
					printf("链表无环\n");
				}
			case '0':
				break;
		}
	}

	return 0;
}


//	注意，这里的快慢指针方法不能很快的给出有环的话是第几个？