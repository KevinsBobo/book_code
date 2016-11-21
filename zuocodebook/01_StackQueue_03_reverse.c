/*
 * 只用递归和栈操作逆序一个栈
 *
 */
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
Elemtype stackPop(Stacktop *topnode){
	if(topnode->top == NULL)
		return 0;
	Node *p;
	Elemtype e;
	e = topnode->top->data;
	p  = topnode->top;
	topnode->top = p->next;
	free(p);
	return e;
}

// 弹出栈底元素并将其返回
Elemtype get(Stacktop *stack){
	Elemtype e = stackPop(stack);
	if(stack->top == NULL)
		return e;
	else{
		Elemtype s = get(stack);
		stackPush(stack, e);
		return s;
	}
}

// 通过递归依次获取栈底元素，并在最后一层递归完成后
// 从最后一层开始将所有获取到的元素重新压回栈中
void reverse(Stacktop *stack){
	if(stack->top == NULL)
		return;
	Elemtype e = get(stack);
	reverse(stack);
	stackPush(stack, e);
}

int main(){
	Stacktop stack;
	int i;
	Node *p;
	
	init(&stack);
	
	for(i = 1; i <= 5; i++)
		stackPush(&stack, i);

	reverse(&stack);

	p = stack.top;
	while(p != NULL){
		printf("%d\n", p->data);
		p = p->next;
	}

	return 0;
}
