//	链队列

#include <stdio.h>
#include <stdlib.h>

//	别名
typedef char ElemType;

//	结构定义
typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode, *QueuePrt;

typedef struct {
	QueuePrt front;	//	队头指针
	QueuePrt rear;	//	队尾指针
}LinkQueue;


//	初始化链队列
void _initLinkQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if(!(q->front)){
		printf("申请内存错误\n");
		exit(0);
	}

	q->front->next = NULL;
}


//	插入链队列
//	插入队列尾部
void _insertLinkQueue(LinkQueue *q, ElemType e)
{
	QueuePrt p;	//	待插入的结点
	p = (QueuePrt)malloc(sizeof(QNode));
	if(!p){
		printf("申请内存错误\n");
		exit(0);
	}

	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;	//	为了连续性，不可或缺

}


//	出队列操作
//	从队列的第一个元素移出
void _deleteLinkQueue(LinkQueue *q, ElemType *e)
{
	QueuePrt p;	//	待删除结点
	
	if(q->front == q->rear){
		return;
	}

	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	
	if(q->rear == p){
		q->rear = q->front;
	}

	free(p);
}

//	销毁队列
void _destoryLinkQueue(LinkQueue *q)
{
	while(q->front){	//	这里仅仅是将q->rear当作普通的QueuePrt在使用
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}


//	主函数
int main(int argc, char const *argv[])
{
	LinkQueue p;
	_initLinkQueue(&p);

	char c;	//	读取键盘输入
	char d;	//	读取队列
	printf("请输入一串字符（以#结束）：\n");

	scanf("%c", &c);
	while('#' != c){
		_insertLinkQueue(&p, c);
		scanf("%c", &c);
	}

	printf("读取结果：\n");
	while(p.front != p.rear){
		_deleteLinkQueue(&p, &d);
		printf("%c", d);
	}
	printf("\n");

	return 0;
}