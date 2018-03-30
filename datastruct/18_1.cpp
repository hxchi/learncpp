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
void _creatLoopList(LoopList *L, int i)
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
			(*L)->data = j;
			(*L)->next = (*L);
		}
		else{
			for(p = (*L); (p->next) != (*L); p = p->next);	//	寻找最后一个结点

			q = (LoopList)malloc(sizeof(Node));
			q->data = j;

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


//	main函数
int main(int argc, char const *argv[])
{
	LoopList L;
	_creatLoopList(&L, 41);
	_coutLoopList(&L);


	int m = _numberLoopList(&L);
	int n = 3;	//	逢3删除
	m %= n;		//	m = 2

	LoopList p = L;
	LoopList q;		//	临时，用来找到待删除的地址并将其删除

	while(p != p->next){	//	循环的3体现在while中两句p = p->next中
		p = p->next;
		q = p->next;	//	待删除的元素

		printf("%d-->", q->data);
		p->next = q->next;
		free(q);
		p = p->next;
	}
	printf("%d", p->data);	//	while循环之后还剩一个结点
	printf("\n\n");

	return 0;
}
