#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 思考题第11题：打印基本数据类型所占内存大小
void printTypeSize(){
	printf("char: %lu, int: %lu, short: %lu, long: %lu, \
               long long: %lu, float: %lu, double: %lu\n" , \
               sizeof(char) , sizeof(int) , sizeof(short) , \
               sizeof(long) , sizeof(long long) , sizeof(\
               float) , sizeof(double));
}

// 上机题：

// 1. 将输入的3个数中最大的数输出
void printMaxNumForInput(){
	int nNum = 0;

	// 计算最小可输入值
	int nMax = -1 << (sizeof(int) * 8 - 1);

	// 打印，计算最大可输入值
	printf("最小输入值：%d\n最大输入值：%d\n" , nMax , -1 ^ nMax);
	printf("请输入3位数：");

	// 比较最大值
	for(int i = 0; i < 3; i++){
		scanf_s("%d" , &nNum);
		nMax = (nNum > nMax) ? nNum : nMax;
	}
	printf("最大的数为：%d\n" , nMax);
}


// 2. 判断输入整数是否可以被3、5、7整除
void threeFiveSeven(){
	int nNum = 0;
	char flag = 0;
	printf("请输入要被除数：");
	scanf_s("%d", &nNum);

	// 判断能否整除
	if(!(nNum % 7)) flag |= 4;
	if(!(nNum % 5)) flag |= 2;
	if(!(nNum % 3)) flag |= 1;

	// 输出
	switch(flag){
		case 7:
			printf("能同时被3、5、7整除\n"); break;
		case 1:
			printf("只能被其中一个数整除（3）\n"); break;
		case 2:
			printf("只能被其中一个数整除（5）\n"); break;
		case 4:
			printf("只能被其中一个数整除（7）\n"); break;
		case 3:
			printf("能被其中两个数（3、5）整除\n"); break;
		case 5:
			printf("能被其中两个数（3、7）整除\n"); break;
		case 6:
			printf("能被其中两个数（5、7）整除\n"); break;
		default:
			printf("不能被3、5、7任何一个整除\n"); break;
	}
}

// 3. 判断三角形
void trangle(){
	int aSide , bSide , cSide;
	printf("请输入三角形三条边：");
	scanf_s("%d %d %d" , &aSide , &bSide , &cSide);

	if(aSide == bSide && aSide == cSide)
		printf("等边三角形\n");
	else if(aSide == bSide || aSide == cSide || bSide == cSide)
		printf("等腰三角形\n");
	else
		printf("不等边三角形\n");
}

// 4. 判断闰年
void isLeapYear(){
	int nYear = 0;
	printf("请输入年份：");
	scanf_s("%d" , &nYear);
	if((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
		printf("闰年\n");
	else
		printf("平年\n");
}

// 5. 比较两个数字
void twoNum(){
	int aNum , bNum;
	printf("请输入两个数字：");
	scanf_s("%d %d" , &aNum ,&bNum);
	printf("较大的数是：");
	if(aNum > bNum) printf("%d\n" , aNum);
	else printf("%d\n" , bNum);

	printf("较大的数是：");
	printf("%d\n" , (aNum > bNum) ? aNum : bNum);
}

// 6. 判断字符大小写、数字
void isUpLowerNum(){
	char cChar;
	printf("请输入一个字符：");
	cChar = getchar();

	if(cChar >= 'A' && cChar <= 'Z')
		printf("一个大写字母\n");
	else if(cChar >= 'a' && cChar <= 'z')
		printf("一个小写字母\n");
	else if(cChar >= '0' && cChar <= '9')
		printf("一个数字\n");
	else
		printf("一个其他字符\n");
}

// 7. 小写转大写
void lowerToUp(){
	char cChar;
	printf("请输入一个字符：");
	cChar = getchar();

	if(cChar >= 'a' && cChar <= 'z')
		printf("转换为大写：%c\n" , cChar - 32);
	else
		printf("输入字符并非小写字母\n");
}

// 8. 数字转英文，递归方法
void getEng(int nNum , char * numEng[]){
	if(nNum < 10){
		printf("%s " , numEng[ nNum ]);
		return;
	}
	int temp = nNum % 10;
	nNum /= 10;
	getEng(nNum , numEng);
	printf("%s " , numEng[ temp ]);
}
void numToEng(){
	int nNum;
	char *numEng[] = { "Zero" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nigh" };
	printf("请输入一个整数：");
	scanf_s("%d" , &nNum);
	getEng(nNum, numEng);
	printf("\n");
}

// 能被9整除余2的数
void nighTwo(){
	printf("1 - 100 中能被9整除余2的数：");
	for(int i = 1; i <= 100 ; i++)
		if(i % 9 == 2) printf("%d ", i);
	printf("\n");
}

// 10. 水仙花数
void flowerNum(){
	printf("0 - 999 中的水仙花数：");
	int fNum , sNum , tNum;
	for(int i = 0; i <= 999; i++){
		fNum = i % 10;
		sNum = i / 10 % 10;
		tNum = i / 100;
		if((double)i == pow((double)fNum , 3) + pow((double)sNum , 3) + pow((double)tNum , 3))
			printf("%d " , i);
	}
	printf("\n");
}

// 11. 将输入的三个数从小到大排序
void threeNumSort(){
	int aNum , bNum , cNum;
	printf("请输入三个数字：");
	scanf_s("%d %d %d" , &aNum , &bNum , &cNum);
	
}

// 12. 判断是否为5、7的整数倍
void fiveSeven(){
	int nNum = 0;
	printf("请输入一个数：");
	scanf_s("%d" , &nNum);
	if(nNum % 5 == 0 && nNum % 7 == 0)
		printf("Yes\n");
	else
		printf("No\n");
}

// 13. 简单运算
void opeartion(){
	int aNum = 0 , bNum = 0;
	char cChar;
	printf("请输入两个数的运算，例\"1 * 1\"：");
	scanf_s("%d %c %d" , &aNum , &cChar , &bNum);
	if(cChar != '+' && cChar != '-' && cChar != '*' && cChar != '/'){
		printf("输入不合法！\n");
		return;
	}
	if(cChar == '/' && bNum == 0){
		printf("除数不能为0！\n");
		return;
	}

	switch(cChar){
		case '+': printf("%d\n" , aNum + bNum); break;
		case '-': printf("%d\n" , aNum - bNum); break;
		case '*': printf("%d\n" , aNum * bNum); break;
		case '/': printf("%d\n" , aNum / bNum); break;
		default: printf("算不出来啦！\n");
	}
}

int main(){
	// printTypeSize();
	// printMaxNumForInput();
	// threeFiveSeven();
	// trangle();
	// isLeapYear();
	// twoNum();
	// isUpLowerNum();
	// lowerToUp();
	// numToEng();
	// nighTwo();
	// flowerNum();
	// threeNumSort();
	// fiveSeven();
	// opeartion();
	system("pause");
	return 0;
}
