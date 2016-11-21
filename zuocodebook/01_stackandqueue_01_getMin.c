/*
 * 设计一个由getMin功能的栈
 *
 * 一种方法是在stackmin栈中同步压入最小数，并同步弹栈
 * （每压一次数据栈就压一次最小数栈，及时最小数不变）
 * 另一种时在stackmin栈中记录当前出现过的最小数，
 * 只有当data弹出数等于min栈顶数时才弹出min栈顶数
 * （如果最新的数等于最小数也进行入栈）
 *
 * 我采用的是第二种
 * */

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

// 栈结点定义
typedef struct Node{
	Elemtype data;
	struct Node *next;
} Node;

// 栈顶点定义
typedef struct{
	Node *top;
} Stacktop;

// 初始化栈
void init(Stacktop *topnode){
	topnode->top = NULL;
}

// 基本push功能
void stackPush(Stacktop *topnode, Elemtype e){
	Node *s = malloc(sizeof(Node));
	s->data = e;
	s->next = topnode->top;
	topnode->top = s;
}

// 基本pop功能
void stackPop(Stacktop *topnode, Elemtype *e){
	if(topnode->top == NULL)
		return;
	Node *p;
	*e = topnode->top->data;
	p  = topnode->top;
	topnode->top = p->next;
	free(p);
}

// 入栈操作并记录min
void push(Stacktop *datanode, Stacktop *stackmin, Elemtype e){
	stackPush(datanode, e);
	if(stackmin->top == NULL || e <= stackmin->top->data)
		stackPush(stackmin, e);
}

// 弹栈并判断是否弹出min
void pop(Stacktop *datanode, Stacktop *stackmin, Elemtype *e){
	if(datanode->top == NULL || stackmin->top == NULL)
		return;
	Elemtype delmin;
	stackPop(datanode, e);
	if(*e == stackmin->top->data)
		stackPop(stackmin, &delmin);
}

// 获取最小数
Elemtype getMin(Stacktop const *minstack){
	if(minstack->top != NULL)
		return minstack->top->data;
	return 0;
}

// 测试函数
void testPush(Stacktop *datanode, Stacktop *stackmin, Elemtype e){
	push(datanode, stackmin, e);
	printf("Push %d, Min %d\n", datanode->top->data, getMin(stackmin));
}

void testPop(Stacktop *datanode, Stacktop *stackmin, Elemtype *e){
	pop(datanode, stackmin, e);
	printf("Pop %d, Min %d\n", *e, getMin(stackmin));
}

int main(){
	Stacktop topnode;
	Stacktop stackmin;
	Node *stacknode;
	Elemtype e;

	init(&topnode);
	init(&stackmin);

	testPush(&topnode, &stackmin, 8);
	testPush(&topnode, &stackmin, 2);
	testPush(&topnode, &stackmin, 4);
	testPush(&topnode, &stackmin, 8);
	testPush(&topnode, &stackmin, 6);
	testPush(&topnode, &stackmin, 1);
	testPush(&topnode, &stackmin, 7);
	testPush(&topnode, &stackmin, 2);
	testPush(&topnode, &stackmin, 6);

	stacknode = topnode.top;
	printf("All node data:\n");
	while(stacknode->next != NULL){
		printf("%d\n", stacknode->data);
		stacknode = stacknode->next;
	}

	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
	testPop(&topnode, &stackmin, &e);
}
