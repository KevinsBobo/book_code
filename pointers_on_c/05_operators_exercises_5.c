#include <stdio.h>
#include <limits.h>

#define INT_BITS  (CHAR_BIT * sizeof(int))

/* * *
 *
 * 函数功能： 把给定一个的值（value_to_store）存储到一个整数（original_value）的
 *            指定的几个位（starting_bit 到 ending_bit）
 * 位数编号： 从右到左
 *
 * * */
int store_bit_field(int original_value, int value_to_store,
		unsigned int starting_bit, unsigned int ending_bit){

	if(starting_bit >= INT_BITS || ending_bit >= INT_BITS
		|| starting_bit < ending_bit){
		printf("input wrong!\n");
		return original_value;
	}

	//创建掩码（0-15位为1，为什么不是32位，应该是因为编译器优化的结果）
	unsigned int mask = ~0;
	/*
	 * 更好地方法：
	 * unsigned int mask = (unsigned)-1;
	 * 原因：-1 在计算机中以补码的方式存在，他的补码是0xFFFFFFFF
	 * */

	//将掩码向右移结束位之后存在的所有位，逻辑上等同于结束位的值
	//此操作使结束位位于最右边，在结束后将掩码移回原位相当于使结束位之后的所有位设置为0
	mask >>= ending_bit;
	//将掩码向左移回原为并再次向左移开始位之前存在的所有位，逻辑上等同于（31-starting_bit）的值
	//此操作使开始位位于最左边，在结束后将掩码移回原位相当于使开始位之前的所有位设置为0
	mask <<= (ending_bit + ( 31 - starting_bit));
	//将掩码移回原位
	mask >>= (31 - starting_bit);
	/*
	 * 更好地方法：
	 * #include <limits.h>
	 * #define INT_BITS  (CHAR_BIT * sizeof(int))
	 * //找出需要插入的位数并将其他为置为0，然后将其移回原为
	 * mask >>= INT_BITS - (starting_bit - endling_bit + 1);
	 * mask <<= ending_bit;
	 *
	 * 原因：
	 * 1.从机器中获取到char类型长度，通过其计算出int类型位数，大大提高程序移植性
	 * 2.只通过两次位移就将相应的位数保留为1
	 * */

	//将掩码取反与源整数进行 & 操作，使要插入位置的值为0
	original_value &= ~mask;
	//将要插入的数的相应为左移至空出的位置，即左移结束位之前存在的所有位
	value_to_store <<= ending_bit;
	//将要插入的数与掩码进行 & 操作，清除插入位之外的值
	value_to_store &= mask;
	//返回插入完成的数
	return original_value | value_to_store;
}

int main(){
	int original, store;
	unsigned int start, end;
	while(scanf("%d %d %d %d", &original, &store, &start, &end) != EOF)
		printf("0x%x\n", store_bit_field(original, store, start, end));
	return 0;
}
