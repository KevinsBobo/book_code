/*
 * 用栈实现汉诺塔
 * */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int Elemtype;

// 栈结点定义
typedef struct Node{
	Elemtype data;
	struct Node *next;
} Node;

// 栈顶点定义
typedef struct{
	Node *top;
	int count;
} Stacktop;

// 初始化栈
void init(Stacktop *topnode){
	topnode->top = NULL;
	topnode->count = 0;
}

// 基本push功能
void stackPush(Stacktop *topnode, Elemtype e){
	Node *s = malloc(sizeof(Node));
	s->data = e;
	s->next = topnode->top;
	topnode->top = s;
	topnode->count += 1;
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
	topnode->count -= 1;
	free(p);
	return e;
}

// 定义操作
enum Action {no, LtoM, MtoL, MtoR, RtoM};

// 移动函数
int move(enum Action *record, enum Action perNoAct, enum Action nowAct,
		Stacktop *fStack, Stacktop *tStack, char from, char to){
	// 当移动满足相邻不可逆和小压大的原则时执行移动
	if(*record != perNoAct && fStack->top->data < tStack->top->data){
		stackPush(tStack, stackPop(fStack));
		printf("Move %d from %c to %c\n", tStack->top->data, from, to);
		*record = nowAct;
		return 1;
	}
	return 0;
}

int hannoi(int num, char left, char mid, char right){
	Stacktop LS, MS, RS;
	int i;

	init(&LS);
	init(&MS);
	init(&RS);
	stackPush(&LS, INT_MAX);
	stackPush(&MS, INT_MAX);
	stackPush(&RS, INT_MAX);

	for(i = num; i > 0; i--)
		stackPush(&LS, i);

	enum Action record = no;
	int step = 0;

	while(RS.count < num + 1){
		// 跟据相邻不可逆和小压大原则，以下四次调用只会有一次执行移动操作。
		step += move(&record, MtoL, LtoM, &LS, &MS, left, mid); 
		step += move(&record, LtoM, MtoL, &MS, &LS, mid, left); 
		step += move(&record, RtoM, MtoR, &MS, &RS, mid, right); 
		step += move(&record, MtoR, RtoM, &RS, &MS, right, mid); 
	}

	return step;
}

int main(){
	int num;
	while(scanf("%d", &num) != EOF)
		printf("Move %d floor\n%d\n", num, hannoi(num, 'A', 'B', 'C'));

	return 0;
}
