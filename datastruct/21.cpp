//	双向链表
//	实现字母表的移位

#include <stdio.h>
#include <stdlib.h>

//	定义一些固定的变量
#define OK 		1
#define ERROR 	0

typedef int		Status;
typedef char 	ElemType;

//	双向链表的定义
typedef struct DualNode{
	ElemType data;
	struct DualNode *prior;
	struct DualNode *next;
} DualNode, *DuLinkList;


//	初始化双向循环链表
//	结果是生成一个返回26个字母的双向循环链表
Status _initDualLinkList(DuLinkList *L)
{
	DuLinkList p;	//	用来表示插入结点的前一个结点
	DuLinkList q;	//	用来表示待插入的结点
	int i = 0;

	//	先定义一个头结点
	(*L) = (DuLinkList)malloc(sizeof(DualNode));
	if(!(*L)){
		printf("无法申请内存空间\n");
		return ERROR;
	}
	(*L)->prior = NULL;
	(*L)->next = NULL;

	p = (*L);	//	将p初始化

	//	依次生成26个字母
	//	这里采用p和q，用来循环生成
	for( ; i < 26; i++){
		q = (DuLinkList)malloc(sizeof(DualNode));
		if(!q){
			printf("无法申请内存空间\n");
			return ERROR;
		}

		q->data = 'A'+i;
		q->prior = p;
		q->next = p->next;
		p->next = q;

		p = q;
	}
	//	建立链表循环，需要跳过头结点
	p->next = (*L)->next;
	(*L)->next->prior = q;
}


//	重排序
//	参数i表示排序的整数
void _sortDualLinkList(DuLinkList *L, int i)
{
	if(i > 0){
		for(int j = i; j >= 1; j--){
			(*L)->next = (*L)->next->next;
		}
	}
	else{
		for(int j = i; j <= -1; j++){
			(*L)->next = (*L)->next->prior;
		}
	}
}


//	遍历双向循环链表
void _coutDualListLink(DuLinkList *L)
{
	DuLinkList p;	//	作为临时变量

	for(p = (*L)->next; (p->next) != (*L)->next; p = p->next){
		printf("%c ", p->data);
	}
	printf("%c", p->data);	//	将p定位到了循环链表的最后一个结点，所以需要将最后一个结点的内容输出
	printf("\n\n");
}


//	main函数
int main(int argc, char const *argv[])
{
	DuLinkList L;
	_initDualLinkList(&L);
	_coutDualListLink(&L);

	int opt = 0;
	printf("请输入数字：\n");
	scanf("%d", &opt);
	_sortDualLinkList(&L, opt);
	_coutDualListLink(&L);

	return 0;
}