#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 上机题
// 1. 用指针打印数组
#define LENTH 10
void printArrByP(){
	int nBuff[ LENTH ] = { 0 };
	for(int i = 0; i < 10; i++)
		scanf_s("%d" , *(nBuff + i));
	for(int i = 0; i < 10; i++)
		printf("%d " , *(nBuff + i));
	printf("\n");
}

// 2. 用3个指针操作3个变量
void swap(int *a , int*b){
	if(*a > *b){
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
void useVarByP(){
	int aNum , bNum , cNum;
	int *pA = &aNum , *pB = &bNum , *pC = &cNum;
	printf("请输入三个数：");
	scanf_s("%d %d %d" , pA , pB , pC);

	swap(pA , pB);
	swap(pA , pC);
	swap(pB , pC);

	printf("排序后：%d %d %d" , *pA , *pB , *pC);
}

// 3. 翻转数组元素
void swapA(int *a , int*b){
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
void change(int array[] , int nNum){
	for(int i = 0; i < nNum / 2 ; i++)
		swapA(array + i , array + nNum - i - 1);
	for(int i = 0; i < nNum ; i++)
		printf("%d " , *(array + i));
	printf("\n");
}

// 4. 自定义strcpy
void myStrcpy(const char *sStr , char *dStr , const int n){
	int i = 0;
	for(i = 0; i < n && *(sStr + i) != '\0'; i++)
		*(dStr + i) = *(sStr + i);
	*(dStr + i) = '\0';
	printf("%s\n" , dStr);
}

// 5. 删除字符串中非字母字符
void dele(char *szStr , int n){
	char cTemp;
	for(int i = 0; i < n && *(szStr + i) != '\0'; i++){
		cTemp = *(szStr + i);
		if(cTemp < 'A' || (cTemp < 'Z' && cTemp < 'a') || cTemp > 'z'){
			strcpy_s(szStr + i , n - i - 1 , szStr + i + 1);
			--i;
		}
	}
	printf("%s\n" , szStr);
}

// 6. 结构体操作
typedef struct _STUINFO
{
	int nNum;
	char szName[ 20 ];
	int nScore;
} STUINFO , *PSTUINFO;
void editStruct(){
	STUINFO stu = { 0 , "0" , 0 };
	PSTUINFO pStu = &stu;
	pStu->nNum = 25;
	pStu->szName[ 0 ] = 'l';
	pStu->szName[ 1 ] = 'i';
	pStu->szName[ 2 ] = 'm';
	pStu->szName[ 3 ] = 'i';
	pStu->szName[ 4 ] = 'n';
	pStu->szName[ 5 ] = 'g';
	pStu->szName[ 6 ] = '\0';
	pStu->nScore = 88;
	printf("nNum: %d, szName: %s, nSocre: %d\n" , pStu->nNum , pStu->szName , pStu->nScore);
}

// 7. 打印黑框
#define BLK 22
#define NUM 40
void printBlackBlod(){
	char black[ NUM ][ NUM ];
	for(int i = 0; i < NUM; i++){
		for(int j = 0; j < NUM; j++){
			if(i == 0 || i == NUM - 1)
				black[ i ][ j ] = 22;
			else if(j == 0 || j == NUM - 1)
				black[ i ][ j ] = 22;
			else
				black[ i ][ j ] = ' ';
			printf("%c" , black[ i ][ j ]);
		}
		printf("\n");
	}
}

// 8. 定义保存坦克信息的结构体
typedef struct TANKE
{
	int size; // 大小
	int sudu; // 移动速度
	int paodansudu; // 炮弹速度
	int blod; // 血量
	int level; // 等级
	char face[ 5 ][ 5 ]; // 外观
} myTanke , *pMyTanke;

// 10. 计算日期
typedef unsigned int uint;
typedef struct DATE
{
	uint year;
	uint mounth;
	uint day;
} myDate , *pMyDate;
int isRunYear(uint year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 1;
	return 0;
}
void printDate(){
	uint days;
	uint years;
	myDate newDate;
	uint moDay[ 12 ] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
	printf("请输入日期：");
	scanf_s("%u %u %u" , &newDate.year , &newDate.mounth , &newDate.day);
	uint countDays = 0;
	for(uint i = 0; i < newDate.mounth - 1; i++)
		countDays += moDay[ i ];
	if(isRunYear(newDate.year) && newDate.mounth > 2)
		++countDays;
	countDays += newDate.day;
	printf("这是这一年中的第 %u 天\n" , countDays);

	printf("请输入年份和天数：");
	scanf_s("%u %u" , &years , &days);

	uint mo;
	if(isRunYear(years) && days > 59)
		++moDay[ 1 ];
	for(mo = 0; mo < 12 && days > moDay[ mo ]; mo++)
		days -= moDay[ mo ];
	printf("日期为：%u %u %u\n" , years , mo + 1 , days);
}

int main(){
	// printArrByP();
	// useVarByP();
	// int array[ 10 ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 };
	// change(array , 10);
	// char sStr[ 10 ] = "atuhanteu";
	// char dStr[ 10 ];
	// myStrcpy(sStr , dStr , 10);
	// char szStr[ 20 ] = "my234is9.hoh89,to8t";
	// dele(szStr , 20);
	// editStruct();
	// printBlackBlod();
	//printDate();


	system("pause");
	return 0;
}
