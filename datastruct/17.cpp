#include <stdio.h>
#include <stdlib.h>


#define ERROR 	0
#define OK 		1

typedef int Status;
typedef int ElemType;

//	单链表的定义
typedef struct Node{
	ElemType data;
	struct Node* next;
} Node;
typedef struct Node* LoopList;


//	初始化循环链表
//	此处的循环列表没有头结点，从第一个结点开始
void _initLoopList(LoopList *L)
{
	LoopList p, q;
	
	printf("请输入插入的结点值，输入0结束\n");
	ElemType i = -1;

	while(1){
		scanf("%d", &i);
		if(i == 0){
			break;
		}
		printf("the number is %d\n", i);
		if((*L) == NULL){	//	如果L是NULL，也就是如果是初始化第一个结点
			(*L) = (LoopList)malloc(sizeof(Node));
			if(!(*L)){		//	malloc之后需要进行判断
				printf("malloc 失败，不能申请新的内存空间...\n");
				exit(0);
			}
			(*L)->data = i;
			(*L)->next = (*L);
		}
		else{	
			//	需要找到指向第一个结点的结点，然后在此处插入
			//	替代了我之前的保留第一个结点的方法
			for(p = (*L); (p->next) != (*L); p = p->next);	

			q = (LoopList)malloc(sizeof(Node));
			if(!q){		//	malloc之后需要进行判断
				printf("malloc 失败，不能申请新的内存空间...\n");
				exit(0);
			}

			q->data = i;
			q->next = p->next;
			p->next = q;
		}
	}
}


//	返回结点个数
//	用作输入检查
int _numberLoopList(LoopList *L)
{
	LoopList p;
	int num = 1;

	for(p = (*L); (p->next) != (*L); p = p->next){
		num++;
	}

	return num;
}


//	插入结点
//	参数i是插入的位置
Status _insertLoopList(LoopList *L, int i)
{
	ElemType *e = new ElemType;
	int j = 1;
	LoopList p;
	LoopList q;		//	记录要插入的结点
	
	printf("请输入需要插入的内容：\n");
	scanf("%d", e);

	if(i == 1){		// 在最开始插入，即插入后的元素作为第一个元素
		q = (LoopList)malloc(sizeof(Node));
		if(!q){		//	malloc之后需要进行判断
			return ERROR;
		}

		q->data = *e;

		//	寻找最后一个结点
		for(p = (*L); (p->next) != (*L); p = p->next);

		q->next = (*L);
		p->next = q;
		(*L) = q;
	}
	else{
		p = (*L);
		for( ; j < (i-1); j++){
			p = p->next;
		}

		q = (LoopList)malloc(sizeof(Node));
		if(!q){		//	malloc之后需要进行判断
			return ERROR;
		}

		q->data = *e;
		q->next = p->next;
		p->next = q;
	}

	return OK;
}


//	删除结点
//	参数i表示要删除的结点的位置
//	i=1表示要删除第一个结点
Status _deleteLoopList(LoopList *L, int i)
{
	LoopList p;		//	设计来指向链表的最后一个结点
	LoopList q;
	int j = 1;

	if(i == 1){
		for(p = (*L); (p->next) != (*L); p = p->next);

		printf("当前列表最后一个元素是： %d\n", p->data);

		p->next = (*L)->next;
		(*L) = p->next;
	}
	else{
		for(p = (*L); (p->next) != (*L); p = p->next);
		
		printf("当前列表最后一个元素是： %d\n", p->data);

		for( ; j < i; j++){
			q = p->next;
			p = q;
		}

		q->next = p->next->next;
	}

	return OK;
}


//	返回结点所在位置
//	输入参数为e为指向该元素的指针
int _posOfLoopList(LoopList *L, ElemType *e)
{
	LoopList p;
	bool bl = 0;
	int i = 0;

	for(p = (*L); (p->next) != (*L); p = p->next);

	while(!bl){
		p = p->next;
		i++;
		if((p->data) == *e){
			bl = 1;
		}
	}

	if(!bl){
		return -1;
	}

	return i;
}


//	遍历链表
//	前提是链表存在
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


// main 函数
int main(int argc, char const *argv[])
{
	LoopList L = NULL;
	printf("1: 初始化循环链表\n2： 插入循环链表\n3： 删除某个结点\n4：定位结点\n5：退出\n");
	char opp;
	int pos = -1;
	int answerPos = -1;
	printf("%c\n", opp);
	while(opp != '5'){
		scanf("%c", &opp);

		switch(opp){
			case '1':
				_initLoopList(&L);
				break;
			case '2':
				_coutLoopList(&L);
				printf("请输入要插入的位置\n");
				while(1){
					scanf("%d", &pos);
					if(pos > (_numberLoopList(&L))){
						printf("请输入一个小于等于链表长度的值\n");
						printf("链表长度为： %d\n", _numberLoopList(&L));
					}
					else{
						break;
					}
				}
				_insertLoopList(&L, pos);
				_coutLoopList(&L);
				break;
			case '3':
				_coutLoopList(&L);
				printf("请输入要删除的位置\n");
				while(1){
					scanf("%d", &pos);
					if(pos > (_numberLoopList(&L))){
						printf("请输入一个小于等于链表长度的值\n");
						printf("链表长度为： %d\n", _numberLoopList(&L));
					}
					else{
						break;
					}
				}
				_deleteLoopList(&L, pos);
				_coutLoopList(&L);
				break;
			case '4':
				_coutLoopList(&L);
				printf("请输入需要定位的结点元素\n");
				scanf("%d", &pos);
				answerPos = _posOfLoopList(&L, &pos);
				if(answerPos == -1){
					printf("找不到指定元素\n");
				}
				else{
					printf("元素位置是第%d个结点\n", answerPos);
				}
				break;
			case '5':
				break;
		}
	}

	return 0;
}
