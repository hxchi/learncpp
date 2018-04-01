//	约瑟夫环进阶版
//	问题描述：编号为1-N的N个人按顺时针方向围坐成一圈，每个人持有一个密码，
//			密码为正整数，可以随意挑选。随机选择一个数M开始第一轮报数，
//			报到M的人出局，留下他的密码作为下一轮的M，如此循环，直至所有人out


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define MAX 99		//	密码的最大值被设置为99

typedef int ElemType;

typedef struct Node{
	ElemType data;
	char name;
	struct Node * next;
} Node;
typedef struct Node* LoopList;


//	初始化循环链表
//	参数i表示循环链表的结点数
//	将每个结点的data初始化为随机数
void _creatLoopList(LoopList *L, int i)
{
	srand(time(0));

	LoopList p, q;
	int j = 1;

	while(j <= i){
		if(j == 1){
			(*L) = (LoopList)malloc(sizeof(Node));
			if(!(*L)){
				printf("申请内存失败\n");
				exit(0);
			}
			(*L)->data = rand()%MAX + 1;
			(*L)->name = 'a';
			(*L)->next = (*L);
		}
		else{
			for(p = (*L); (p->next) != (*L); p = p->next);	//	寻找最后一个结点

			q = (LoopList)malloc(sizeof(Node));
			if(!q){
				printf("申请内存失败\n");
				exit(0);
			}
			q->data = rand()%MAX + 1;
			q->name = 'a'+j-1;

			q->next = (*L);
			p->next = q;
		}
		j++;
	}
}


// 返回链表长度
int _lengthOfLoopList(LoopList *L)
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
		printf("%c--%d ", p->name, p->data);
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
	_creatLoopList(&L, 10);
	_coutLoopList(&L);


	// srand(time(0));
	int random = rand()%MAX + 1;
	printf("第一次随机数为：%d.\n", random);

	LoopList p = L;		// p作为起始
	// printf("第一个结点是：%c-->%d.\n\n", p->name, p->data);
	LoopList q;			// q作为临时变量，用来被删除
	
	while(_lengthOfLoopList(&p) != 1){
		//	如果要删除第一个结点
		if(random == 1){
			q = p;
			//	寻找到最后一个结点
			for( ; (p->next) != q; p = p->next){
				// printf("此时： %c-->%d\n", p->name, p->data);
			}

		}
		else{
			for(int i = 1; i < (random-1); i++){
				p = p->next;
			}
			q = p->next;
		}
		
		// printf("删除的元素是：%d.\n", q->data);
		printf("删除的编号是：%c.\n", q->name);

		//	删除q结点
		p->next = q->next;
		random = q->data;
		printf("下一轮的随机数为：%d.\n", random);
		LoopList qdel = q;	//	用来删除，不知这样对不对？
		free(qdel);

		p = p->next;	//	将p结点后移一位
		// printf("剩余链表的长度是：%d.\n", _lengthOfLoopList(&p));
		printf("\n\n");
	}

	// printf("删除的元素是：%d.\n", p->data);
	printf("删除的编号是：%c.\n", p->name);
	printf("游戏结束.\n");

	return 0;
}


//	注意测试边界条件。
//	完全可以将第一个结点作为参数，传入函数