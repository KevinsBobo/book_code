/*线性表的单链表存储结构*/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1
#define TURE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct Node{
	ElemType data;
	struct Node *next;
} Node;

typedef struct Node *LinkList;

/*读取函数：用e返回L中第i个元素的值*/
Status GetElem(LinkList L, int i, ElemType *e){
	int j;
	LinkList p;
	//将p指向链表L的第一个节点
	p = L->next;
	j = 1;
	//p不为空且j还没有等于i时循环继续
	while(p && j < i){
		p = p->next;//将p只想下一个结点
		j++;
	}
	if(!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}

/*插入函数：在L中的第L个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(LinkList *L, int i, ElemType e){
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	//寻找第i个结点
	while(p && j < i){
		p = p->next;
		++j;
	}
	if(!p || j > i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));//生成新结点
	s->data = e;
	s->next = p->next;
	p->next = s;
	(*L)->data++;
	return OK;
}

/*删除函数：删除L的第i个数据元素，并用d返回其值，L长度减1*/
Status ListDelete(LinkList *L, int i, ElemType *e){
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while(p->next && j < i){
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	(*L)->data--;
	return OK;
}

/*创建函数，表头插入法*/
Status CreateListHead(LinkList *L, int n){
	LinkList p;
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i * 2;
		p->next = (*L)->next;
		(*L)->next = p;
	}
	(*L)->data = i;
	return OK;
}

/*创建函数，表尾插入法*/
Status CreateListTail(LinkList *L, int n){
	LinkList p, r;
	int i;
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i = 0; i < n; i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = i * 2;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	(*L)->data = i;
}

/*整表删除*/
Status ClearList(LinkList *L){
	LinkList p,q;
	p = (*L)->next;
	while(p){
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}

/*测试*/
int main(){
	LinkList testlist;
	CreateListTail(&testlist, 15);

	if(!ListInsert(&testlist, 8, 1000))
		printf("insert 1000\nlength %d\n", testlist->data);
	if(!ListInsert(&testlist, 13, 1000))
		printf("insert 1000\nlength %d\n", testlist->data);

	ElemType e;
	if(!ListDelete(&testlist, 12, &e))
		printf("delete %d,length %d\n", e, testlist->data);

	for(int i = 1; i <= testlist->data; i++){
		if(!GetElem(testlist, i, &e))
			printf("list %d velue is: %d\n", i, e);
	}

	if(!ClearList(&testlist))
		printf("list delete\n");
	return OK;
}

