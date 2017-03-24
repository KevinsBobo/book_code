#include <stdio.h>
#include <stdlib.h>

// �����ϻ���� - ������
// ��ͨ������
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild , *rchild;
} BiTNode , *BiTree;

// ����������
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

// ������������ - ת��Ϊ����˫������
BiThrTree pre = NULL;
void inThreading(BiThrTree p){
	if(p == NULL)
		return;

	// ����������
	inThreading(p->lchild);
	// ����ǰ����������ָ��
	if(p->lchild == NULL){
		p->lTag = Thread;
		p->lchild = pre;
	}
	// �����ϴα������Ľ���������ָ��
	if(pre != NULL && pre->rchild == NULL){
		pre->rTag = Thread;
		pre->rchild = p;
	}
	// ���±������Ľ����Ϣ
	pre = p;
	// ����������
	inThreading(p->rchild);
}

/*
int main(){
	// ��������
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