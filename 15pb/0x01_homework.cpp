#include <stdio.h>
#include <stdlib.h>

// 利用递归转换并打印二进制
void printDec(long long num , int temp, int printSpace){
	// 递归终止条件，并在不足四位的二进制最前面补零
	if(num == 0){
		while(4 - printSpace > 0){
			printf("0");
			printSpace++;
		}
		return;
	}

	temp = num % 2; // 计算二进制当前位的值
	num /= 2;
	printSpace = printSpace++ % 4; // 计算当前二进制的位置，用于输出空格

	// 递归调用
	printDec(num , temp , printSpace);

	// 每积累4位二进制，则打印一个空格
	if(printSpace == 4) printf(" ");

	printf("%d" , temp);

}

int main(){
	// printf("Hello15PB\n");

	long long num = 455897641;
	int temp = 0;
	int printSpace = 0;
	long long numtemp = num;

	/* 打印计算过程 开始 */
	printf("%9d\n\t/ 2\n" , num);
	while(numtemp > 0){
		temp = numtemp % 2;
		numtemp /= 2;

		printf("%9d    --" , numtemp);
		printf("%4d\n" , temp);

		if(numtemp != 0)
			printf("\t/ 2\n");
	}
	/* 打印计算过程 结束 */
	
	// 重置
	temp = 0;

	// 计算并打印转化后的二进制
	printf("DEC : ");
	printDec(num , temp, printSpace);
	printf("\n");

	system("pause");
	return 0;
}