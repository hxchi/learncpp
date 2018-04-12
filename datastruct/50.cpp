// 创建线索二叉树

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
// 线索存储标志位
// Link(0):表示指向左右孩子的指针
// Thread(1):表示指向前驱后继的线索
typedef enum{Link, Thread} PointerNag;

typedef struct BiThrNode{
  ElemType data;
  struct BiThrNode *lchild, *rchild;
  PointerNag ltag;
  PointerNag rtag;
}BiThrNode, *BiThrTree;


// 定义全局变量，始终指向上一次访问过的结点
BiThrTree pre;


// 创建二叉树
// 按照前序遍历的方式
void CreatBiThrTree(BiThrTree *T)
{
  ElemType c;
  scanf("%c", &c);

  if(' ' == c){
    *T = NULL;
  }
  else{
    *T = (BiThrNode*)malloc(sizeof(BiThrNode));
    (*T)->data = c;
    (*T)->ltag = Link;
    (*T)->rtag = Link;

    CreatBiThrTree(&(*T)->lchild);
    CreatBiThrTree(&(*T)->rchild);
  }
}


// 中序遍历线索化
void InThreading(BiThrTree T)
{
  if(T){
    InThreading(T->lchild);	// 递归左孩子线索化
    if(!(T->lchild)){		// 如果该结点没有左孩子，
      T->ltag = Thread;		// 设置ltag为thred，
      T->lchild = pre;		// 并将lchild指向上一个结点。
    }
    if(!(pre->rchild)){		// 这里是判断pre
      pre->rtag = Thread;
      pre->rchild = T;
    }
    pre = T;
    
    InThreading(T->rchild);	// 递归右孩子线索化
  }
}


void InOrderThreading(BiThrTree *p, BiThrTree T)
{
  (*p) = (BiThrNode *)malloc(sizeof(BiThrNode));
  (*p)->ltag = Link;
  (*p)->rtag = Thread;
  (*p)->rchild = (*p);
  if(!T){
    (*p)->lchild = *p;
  }
  else{
    (*p)->lchild = T;
    pre = (*p);
    InThreading(T);
    pre->rchild = (*p);
    pre->rtag = Thread;
    (*p)->rchild = pre;
  }
}

// 主函数
int main()
{
  BiThrTree p;
  BiThrTree T = NULL;
  CreatBiThrTree(&T);

  InOrderThreading(&p, T);
  
  return 0;
}
