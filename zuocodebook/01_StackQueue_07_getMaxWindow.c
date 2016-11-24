/*
 * 打印窗口最大值
 * */
#include <stdio.h>
#include <stdlib.h>


typedef int Elemtype;

// 双队列队列结点定义
typedef struct Node{
	Elemtype data;
	struct Node *next;
	struct Node *pre;
} Node;

// 双队列顶点定义
typedef struct{
	Node *top;
	Node *tail;
	int  count;
} Dueuetop;

// 初始化双队列
void init(Dueuetop *Dueue){
	Dueue->top = NULL;
	Dueue->tail = NULL;
	Dueue->count = 0;
}

// 基本push功能
void dueuePush(Dueuetop *Dueue, Elemtype e){
	Node *s = malloc(sizeof(Node));
	s->data = e;
	s->next = Dueue->top;
	s->pre  = NULL;
	if(Dueue->top != NULL)
		Dueue->top->pre = s;
	Dueue->top = s;
	if(Dueue->tail == NULL)
		Dueue->tail = s;
	Dueue->count += 1;
}

// 基本pushtail功能
void dueuePushTail(Dueuetop *Dueue, Elemtype e){
	Node *s = malloc(sizeof(Node));
	s->data = e;
	s->next = NULL;
	s->pre  = Dueue->tail;
	if(Dueue->tail != NULL)
		Dueue->tail->next = s;
	Dueue->tail = s;
	if(Dueue->top == NULL)
		Dueue->top = s;
	Dueue->count += 1;
}

// 基本pop功能
Elemtype dueuePop(Dueuetop *Dueue){
	if(Dueue->top == NULL)
		return 0;
	Node *p;
	Elemtype e;
	e = Dueue->top->data;
	p  = Dueue->top;
	Dueue->top = p->next;

	if(Dueue->top == NULL)
		Dueue->tail = NULL;
	else
		p->next->pre = NULL;

	Dueue->count -= 1;
	free(p);
	return e;
}

// 基本poptail功能
Elemtype dueuePopTail(Dueuetop *Dueue){
	if(Dueue->tail == NULL)
		return 0;
	Node *p;
	Elemtype e;
	e = Dueue->tail->data;
	p  = Dueue->tail;
	Dueue->tail = p->pre;

	if(Dueue->tail == NULL)
		Dueue->top = NULL;
	else
		p->pre->next = NULL;

	Dueue->count -= 1;
	free(p);
	return e;
}

// 清空双队列
void del(Dueuetop *Dueue){
	while(Dueue->top != NULL)
		dueuePop(Dueue);
}

/*
* 技巧：
* 1. 双队列队头存放当前窗口遇到的最大值下标
* 2. 双队列队尾存放当前窗口新进的元素下标
* 3. 当新进元素值大于等于队尾下标对应的元素时
*    循环将队尾下标弹出，直到队列为空或新进元素值
*    小于队尾下标对应的元素
* 4. 当队头存放的下标等与每次循环中的 i - w 时，
*    队头下标过期，将其弹出
*/
void getMaxWindows(int num, int const *buffer, int window){
	Dueuetop Dueue;
	init(&Dueue);
	int i;
	int j;

	printf("{");

	for(i = 0; i < num; i ++){
		/*
		* 当前队列不为空并且当前窗口中未进行比较的元素大于等于
		* 队列尾部下标所代表的元素时，
		* 弹出队尾元素，循环至不满足以上条件
		*/
		while(Dueue.tail != NULL && buffer[Dueue.tail->data] <= buffer[i])
			dueuePopTail(&Dueue);

		// 将当前元素下标存进队尾
		dueuePushTail(&Dueue, i);

		// 如果对头所存储的下标等于 i - window 时，下标过期，将其弹出
		if(Dueue.top->data == i - window)
			dueuePop(&Dueue);

		/*
		* 当走过第一个窗口的前 window - 1 个元素后，
		* 每次循环都会打印队头元素，即当前窗口最大值。
		*/
		if(i >= window - 1){
			printf("%d", buffer[Dueue.top->data]);
			if(i < num - 1)
				printf(",");
		}
	}
	printf("}\n");

	del(&Dueue);
}

int main(){
	int buffer[1000];
	int num;
	int window;
	printf("input arr length:");
	while(scanf("%d", &num) != EOF){
		printf("input arr member:");
		int i;
		for(i = 0; i < num; i++)
			scanf("%d", buffer + i);

		printf("input window length:");
		scanf("%d", &window);

		if(window > num){
			printf("window too big\n");
			continue;
		}

		getMaxWindows(num, buffer, window);
		printf("input arr length:");
	}
	return 0;
}
