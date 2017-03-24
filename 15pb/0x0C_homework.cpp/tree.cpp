#include <stdio.h>
#include <stdlib.h>

// 二、上机提高 - 二叉树
// 普通二叉树
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild , *rchild;
} BiTNode , *BiTree;

// 线索二叉树
typedef enum
{
	Link , Thread
} PointerTag;
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild , *rchild;
	PointerTag lTag , rTag;
} BiThrNode , *BiThrTree;


void echoTreeByPreOrder(BiTree tree){
	if(tree == NULL)
		return;
	printf("%c " , tree->data);
	echoTreeByPreOrder(tree->lchild);
	echoTreeByPreOrder(tree->rchild);
}

void echoTreeByInOrder(BiTree tree){
	if(tree == NULL)
		return;
	echoTreeByInOrder(tree->lchild);
	printf("%c " , tree->data);
	echoTreeByInOrder(tree->rchild);
}

void echoTreeByPostOrder(BiTree tree){
	if(tree == NULL)
		return;
	echoTreeByPostOrder(tree->lchild);
	echoTreeByPostOrder(tree->rchild);
	printf("%c " , tree->data);
}

void createBiTree(BiTree *tree){
	TElemType ch;
	scanf("%c" , &ch);
	if(ch == '#')
		*tree = NULL;
	else{
		*tree = (BiTree)malloc(sizeof(BiTNode));
		if(!*tree)
			exit(1);
		(*tree)->data = ch;
		createBiTree(&((*tree)->lchild));
		createBiTree(&((*tree)->rchild));
	}
}

// 二叉树线索化 - 转化为有序双向链表
BiThrTree pre = NULL;
void inThreading(BiThrTree p){
	if(p == NULL)
		return;

	// 遍历左子树
	inThreading(p->lchild);
	// 处理当前结点的左子树指针
	if(p->lchild == NULL){
		p->lTag = Thread;
		p->lchild = pre;
	}
	// 处理上次遍历过的结点的右子树指针
	if(pre != NULL && pre->rchild == NULL){
		pre->rTag = Thread;
		pre->rchild = p;
	}
	// 更新遍历过的结点信息
	pre = p;
	// 遍历右子树
	inThreading(p->rchild);
}

/*
int main(){
	// 测试用例
	BiTree myTree;
	printf("Input Tree (eg: AB#D##C##): ");
	createBiTree(&myTree);
	echoTreeByPreOrder(myTree);
	printf("\n");
	echoTreeByInOrder(myTree);
	printf("\n");
	echoTreeByPostOrder(myTree);
	printf("\n");

	return 0;
}
*/