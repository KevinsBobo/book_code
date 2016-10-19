/*用数组创建线性表*/
#include <stdio.h>

#define MAXSIZE 20
#define OK 0
#define ERROR 1
#define TURE 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
}SqList;

/*查找函数，用e返回L中第i个数据元素的值*/
Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];
	return OK;
}

/*插入函数，在L中第i个位置之前插入新的数据元素e，L的长度加1*/
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if(L->length == MAXSIZE)
		return ERROR;
	if(i < 1 || i > L->length+1)
		return ERROR;
	if(i <= L->length)
	{
		for(k = L->length-1; k >= i-1; k--)
			L->data[k+1] = L->data[k];
	}
	L->data[i-1] = e;
	L->length++;
	return OK;
}

/*删除函数，；删除L的第i个数据元素，并用e返回其值，L长度减1*/
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if(L->length == 0)
		return ERROR;
	if(i < 1 || i > L->length)
		return ERROR;
	*e=L->data[i-1];
	if(i < L->length)
	{
		for(k = i; k < L->length; k++)
			L->data[k-1] = L->data[k];
	}
	L->length--;
	return OK;
}

/*测试*/
int main(){
	SqList testlist;
	for(int i = 0; i < 15; i++)
		testlist.data[i] = i*2;
	testlist.length = 15;
	
	if(!ListInsert(&testlist, 8, 1000))
		printf("insert 1000\n");
	if(!ListInsert(&testlist, 13, 1000))
		printf("insert 1000\n");

	ElemType e;
	if(!ListDelete(&testlist, 12, &e))
		printf("delete %d\n", e);

	for(int i = 1; i <= testlist.length; i++){
		if(!GetElem(testlist, i, &e))
			printf("list %d velue is: %d\n", i, e);
	}
	return OK;
}
