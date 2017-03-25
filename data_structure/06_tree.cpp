#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 普通二叉树
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 线索二叉树
typedef enum {Link , Thread} PointerTag;
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag lTag, rTag;
} BiThrNode, *BiThrTree;


void echoTreeByPreOrder(BiTree tree){
    if(tree == NULL)
        return;
    printf("%c ", tree->data);
    echoTreeByPreOrder(tree->lchild);
    echoTreeByPreOrder(tree->rchild);
}

void echoTreeByInOrder(BiTree tree){
    if(tree == NULL)
        return;
    echoTreeByInOrder(tree->lchild);
    printf("%c ", tree->data);
    echoTreeByInOrder(tree->rchild);
}

void echoTreeByPostOrder(BiTree tree){
    if(tree == NULL)
        return;
    echoTreeByPostOrder(tree->lchild);
    echoTreeByPostOrder(tree->rchild);
    printf("%c ", tree->data);
}

void createBiTree(BiTree *tree){
    TElemType ch;
    scanf("%c", &ch);
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

// 创建线索二叉树初始状态
void createBiThrTree(BiThrTree *tree){
    TElemType ch;
    scanf("%c", &ch);
    if(ch == '#')
        *tree = NULL;
    else{
        *tree = (BiThrTree)malloc(sizeof(BiThrNode));
        (*tree)->lchild = NULL;
        (*tree)->rchild = NULL;
        (*tree)->lTag = Link;
		(*tree)->rTag = Link;
        if(!*tree)
            exit(1);
        (*tree)->data = ch;
        createBiThrTree(&((*tree)->lchild));
        createBiThrTree(&((*tree)->rchild));
    }
}

// 前序输出
void echoThrTreeByPreOrder(BiThrTree tree){
    if(tree == NULL)
        return;
    printf("%c ", tree->data);
    echoThrTreeByPreOrder(tree->lchild);
    echoThrTreeByPreOrder(tree->rchild);
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
        pre->rchild =p;
    }
    // 更新遍历过的结点信息
    pre = p;
    // 遍历右子树
    inThreading(p->rchild);
}

// 为线索二叉树增加头结点
void addThrTreeHead(BiThrTree *t, BiThrTree p){
    if(p == NULL)
        return;

    // 将头结点的左结点指针指向树的根结点
    (*t)->lTag = Link;
    (*t)->lchild = p;
    // 遍历到最左侧子节点 - 中序遍历第一个结点
    while(p->lchild != NULL)
        p = p->lchild;
    // 将中序遍历第一个结点的左结点指针指向头结点
    p->lchild = *t;
    p->lTag = Thread;

    // 遍历到最右侧子节点 - 中序遍历最后一个结点
    while(p->rchild != NULL)
        p = p->rchild;
    // 将中序遍历最后一个结点的右结点指针指向头结点
    p->rchild = *t;
    p->rTag = Thread;
    // 将头结点右结点指针指向中序遍历最后一个结点
    (*t)->rTag = Thread;
    (*t)->rchild = p;
}

// 通过线索二叉树头结点 正向遍历中序二叉树
void echoTreeByInOrder_Thr(BiThrTree t){
    if(t == NULL)
        return;

    BiThrTree p;
    // 将p指向根结点
    p = t->lchild;
    // 开始遍历
    while(p != t){ // 遍历结束时 p == t
        // 始终将p指向每颗子树最左边的结点 - 中序遍历的第一个结点
        while(p->lTag == Link)
            p = p->lchild;
        
        printf("%c ", p->data); // 打印每颗子树最左侧结点

        // 按照中序遍历的顺序寻找下个结点，若下个右节点顺序不对则停止遍历
        while(p->rTag == Thread && p->rchild != t){
            p = p->rchild;
            printf("%c ", p->data);
        }
        // 将指针指向右子树根结点，下次遍历则从右子树开始
        p = p->rchild;
    }
}

// 通过线索二叉树头节点 反向遍历中序二叉树
void echoTreeByInOrder_Thr_Pre(BiThrTree t){
    if(t == NULL)
        return;

    BiThrTree p;
    // 将p指向根结点
    p = t->lchild;
    while(p != t){ // 遍历结束时 p == t
        // 始终将p指向每颗子树最右边的节点 - 中序遍历的最后一个节点
        while(p->rTag == Link)
            p = p->rchild;

        printf("%c ", p->data); // 打印每颗子树最右侧节点

        // 按照中序遍历的相反顺序寻找下个节点，若下个左节点顺序不对则停止遍历
        while(p->lTag == Thread && p->lchild != t){
            p = p->lchild;
            printf("%c ", p->data);
        }
        // 将指针指向左子树根结点，下次遍历则从左子树开始
        p = p->lchild;
    }
}

int main(){
    // 普通二叉树测试用例
    /*
    BiTree myTree;
    printf("Input Tree (eg: AB#D##C##): ");
    createBiTree(&myTree);
    echoTreeByPreOrder(myTree);
    printf("\n");
    echoTreeByInOrder(myTree);
    printf("\n");
    echoTreeByPostOrder(myTree);
    printf("\n");
    */

    // 线索二叉树测试用例
    BiThrTree myThrTree;
    printf("Input Tree (eg: ABDH##I##EJ###CF##G##): ");
    createBiThrTree(&myThrTree);
    echoThrTreeByPreOrder(myThrTree);
    printf("\n");
    BiThrNode thrHeadNode;
	BiThrTree ThrTreeHd = &thrHeadNode;
	inThreading(myThrTree);
    addThrTreeHead(&ThrTreeHd, myThrTree);
    echoTreeByInOrder_Thr(ThrTreeHd);
    printf("\n");
    echoTreeByInOrder_Thr_Pre(ThrTreeHd);
    printf("\n");

    return 0;
}
