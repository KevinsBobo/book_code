/*
 * 寻找质数
 * */

#include <stdio.h>

#define SIZE  1000

#define TRUE  1
#define FALSE 0

int main(){
	char sieve[SIZE];
	char *sp;
	int  number;

	//将质数数组所有元素标识为TRUE
	for(sp = sieve; sp < &sieve[SIZE];)
		*sp++ = TRUE;

	//开始处理质数数组，只处理奇数，所以从3开始每循环一次加2
	for(number = 3; ; number += 2){
		//每次循环后将指针指向数组下一个元素，并在超出数组后界后结束循环
		sp = &sieve[0] + (number - 3) / 2;
		if(sp >= &sieve[SIZE])
			break;

		//将当前奇数后可以整除的数标识为FALSE
		while(sp += number, sp < &sieve[SIZE])
			*sp = FALSE;
	}
	
	//打印所有标识为TRUE的数组下标对应的质数
	printf("1\n2\n");
	for(number = 3, sp = &sieve[0];
		sp < &sieve[SIZE];
		number += 2, sp++){
		if(*sp)
			printf("%d\n", number);
	}
	return 0;
}
