// 建立二叉树，并返回结点的层数

#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;

typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

// 使用递归创建一个二叉树
// 通过前序遍历方式输入
void CreatBiTree(BiTree *T)
{
  ElemType c;
  scanf("%c", &c);
  if(' ' == c){
    *T = NULL;
  }
  else{
    *T = (BiTNode *)malloc(sizeof(BiTNode));
    (*T)->data = c;
    CreatBiTree(&(*T)->lchild);
    CreatBiTree(&(*T)->rchild);
  }
}

void Vist(BiTree T, int level)
{
  printf("%c 位于 %d层\n", T->data, level);
}

// 前序遍历二叉树
void PreOrderTraverse(BiTree T, int level)
{
  if(T){
    Vist(T, level);
    PreOrderTraverse(T->lchild, level+1);
    PreOrderTraverse(T->rchild, level+1);
  }
}


// 主函数
int main()
{
  int level = 1;
  BiTree T = NULL;

  CreatBiTree(&T);
  PreOrderTraverse(T, level);
  
  return 0;
}
