#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

// 上机题
// 1. 计算n!之后0的个数
int countHierarchy(int nNum){
	int nSum = 1;
	int nReaust = 0;
	for(int i = 1; i <= nNum; i++)
		nSum *= i;
	while(nSum % 10 == 0){
		++nReaust;
		nSum /= 10;
	}
	return nReaust;
}

// 2. 打印一个99乘法表
void print99(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= i; j++)
			printf(" | %d*%d=%d" , j , i , i * j);
		printf("\n");
	}
}

// 3. 猜数字游戏
void isThisNumGame(){
	int theNum = 0;
	int nNum = 0;
	srand((unsigned)time(NULL));
	theNum = rand() % (20);

	do{
		printf("请输入猜测的数字：");
		scanf_s("%d" , &nNum);
		if(nNum > theNum)
			printf("猜大了\n");
		else if(nNum < theNum)
			printf("猜小了\n");
		else
			printf("猜对了\n");
	} while(nNum != theNum);

}

// 4.在函数内部打印"hello15PB"
void printHello15pb(){
	printf("hello15PB\n");
}

// 6. 打印参数地址
void printXinCan(int a){
	printf("形参地址：%x\n" , &a);
}
void printAderrs(){
	int a = 0;
	printf("实参地址：%x\n" , &a);
	printXinCan(a);
}

// 7. 返回按键
int printKeybraodPass(){
	printf("请按键:\n");
	while(_kbhit() == 0)
		return _getch();
	return 0;
}

// 8. 将字符串中的大写字母转换为小写字母
void changeStrToLower(char *szBuff , int nMax){
	for(int i = 0; *(szBuff + i) != '\0' && i < nMax; i++)
		if(*(szBuff + i) >= 'A' && *(szBuff + i) <= 'Z')
			*(szBuff + i) += 32;
}
void printLowerStr(){
	const int nMax = 100;
	char szBuff[ nMax ];
	scanf_s("%s" , szBuff , 100);
	changeStrToLower(szBuff , 100);
	printf("%s\n" , szBuff);
}

// 10. 不用strlen算字符串长度
void printStrlen(){
	char szBuff[ 100 ] = { 0 };
	int  szCount = 0;
	int  i = 0;
	printf("请输入字符串：");
	scanf_s("%s" , szBuff , 100);

	while(*(szBuff + i) != '\0')
		++i , ++szCount;

	printf("字符串长度为：%d\n" , szCount);
}

// 12. 兔子数量
int printTuNum(int nNum){
    if(nNum == 0)
        return 0;
    else if(nNum == 1 || nNum == 2)
        return 1;
    else
        return printTuNum(nNum - 1) + printTuNum(nNum - 2);
}

int main(){
	// printf("%d的n!后有%d个0\n" ,10, countHierarchy(10));
	// print99();
	// isThisNumGame();
	// printHello15pb();
	//printAderrs();
	//printf("按下了：%d\n" , printKeybraodPass());
	//printLowerStr();
	//printStrlen();
	printf("%d月后一共有%d只兔子\n", 15, printTuNum(15));
    system("pause");
	return 0;
}
