/*
 * 用一个栈实现另一个栈的排序
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

/*
* 技巧：始终将遇到的最大元素存入help栈底
*
* 创建一个help栈用于辅助
* 
* 循环将stack栈顶元素弹出并存在cur变量中
* 
*	如果help为空栈或cur小于等于help栈顶元素
*	则将cur压入help栈
*
*	如果cur大于help栈顶元素则将help栈顶元素依次弹出并压回stack栈中
*	直到遇到cur小于等于help的栈顶元素或help栈为空时结束循环
*	完成后将cur压入help栈
*
*	继续循环，直到stack栈为空
*
* 操作完成后help栈中的元素从栈顶到栈底所有元素按照从小到大排序
* 
* 此时再将help栈中的所有元素依次压回stack栈中
* 此时stack栈从顶到底完成从大到小排序
*/
void sortStack(Stacktop *stack){
	Stacktop help;
	Elemtype cur;
	
	init(&help);
	while(stack->top != NULL){
		cur = stackPop(stack);
		while(help.top != NULL && cur > help.top->data)
			stackPush(stack, stackPop(&help));
		stackPush(&help, cur);
	}

	while(help.top != NULL)
		stackPush(stack, stackPop(&help));
}

int main(){
	Stacktop stack;
	init(&stack);
	
	stackPush(&stack, 4);
	stackPush(&stack, 2);
	stackPush(&stack, 5);
	stackPush(&stack, 1);
	stackPush(&stack, 3);

	sortStack(&stack);

	while(stack.top != NULL)
		printf("%d\n", stackPop(&stack));

	return 0;
}
