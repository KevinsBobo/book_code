/*
 * 测试字符串是否回文
 * 用指针方式改写数组方式
 *
 * 改正：将front和rear初始化为指向字符串首尾的指针
 *       经过编译器优化后程序执行效率会更高
 *       因为编译器会优化每次循环尾部的两次自增减操作
 *       原来的方法编译器在每次循环中需要对if内的表达式做乘法运算
 * */

#include <stdio.h>
#include <string.h>

int test_palindrome(char buffer[]){
	int front, rear;
	// int *front, *rear;
	front = 0;
	// front = buffer;
	rear = strlen(buffer) - 1;
	// rear = buffer + strlen(buffer) - 1;
	while(front < rear){
		if(*(buffer + front) !=  *(buffer + rear))
		// if(*front != *rear)
			return 1;
		front++;
		rear--;
	}
	if( front >= rear)
		return 0;
	else
		return -1;
}

int main(){
	char buffer[50];
	while(scanf("%s", buffer) != EOF)
		printf("This string is %s\n", test_palindrome(buffer) ? "not palindrome" : "palindrome");
	return 0;
}
