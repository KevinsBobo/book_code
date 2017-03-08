#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// �ϻ���

// 1. ��ת���ֺ���λ������
void getDecFromNum(int nNum , char szDec[]){
	int i = 0;
	int nTemp = 0;
	while(nNum > 0){
		nTemp = nNum % 2;
		nNum /= 2;
		szDec[ 31 - i++ ] = nTemp + '0';
	}
	while(i < 32)
		szDec[ 31 - i++ ] = '0';
	szDec[ 32 ] = '\0';
}
void revDec(){
	int nNum = 0;
	char szDec[ 33 ];

	printf("���������֣�");
	scanf_s("%d" , &nNum);

	getDecFromNum(nNum , szDec);

	printf("��תǰ��2���ƣ�%s\n" , szDec);

	for(int i = 0; i < 4; i++)
		szDec[ 31 - i ] = (szDec[ 31 - i ] == '1') ? '0' : '1';

	printf("��ת���2���ƣ�%s\n" , szDec);
}

// 2. ͳ��1�ĸ���
void countOneInDec(){
	int nNum = 0;
	int nCount = 0;
	printf("���������֣�");
	scanf_s("%d" , &nNum);

	while(nNum != 0){
		nCount += nNum && 1;
		nNum >>= 1;
	}
	printf("һ����%dλ1\n" , nCount);
}

void countStuFen(){
	int nFen[ 6 ] = { 0 };
	int nZongFen = 0;
	printf("������6��ͬѧ�ķ�����");
	for(int i = 0; i < 6; i++){
		scanf_s("%d" , &nFen[ i ]);
		nZongFen += nFen[ i ];
	}

	printf("ƽ����Ϊ��%d\n" , nZongFen / 6);
}

// 4. �򵥵���Ϸ��ʼ����
void simpleGame(){
	int nNum;
	char gameFace[][ 26 ] = {
		"*************************" ,
		"* 1   one Player        *" ,
		"* 2   two Player        *" ,
		"* 3   Edit Map          *" ,
		"* 4   Chose Level       *" ,
		"*************************" ,
		"please input your choice:"
	};
	for(int i = 0; i < 7 ; i++)
		printf("%s\n" , gameFace[ i ]);

	scanf_s("%d" , &nNum);

	switch(nNum){
		case 1:
			printf("one Player\n"); break;
		case 2:
			printf("two Player\n"); break;
		case 3:
			printf("Edit Map\n"); break;
		case 4:
			printf("Chose Level\n"); break;
		default:
			printf("���벻��ȷ��\n");
	}
}

// 6. ��ӡ����ֱ��������
void printNum(){
	for(int i = 1; i < 6; i++){
		for(int j = 0; j < i; j++)
			printf("%d" , i);
		printf("\n");
	}
}

// 8. ��ͬ�м������������λ���ķ���
void changeTwoNum(){
	int aNum = 1 , bNum = 4;
	aNum ^= bNum;
	bNum ^= aNum;
	aNum ^= bNum;
	printf("aNum = %d, bNum = %d\n" , aNum , bNum);

	aNum += bNum;
	bNum = aNum - bNum;
	aNum = aNum - bNum;
	printf("aNum = %d, bNum = %d\n" , aNum , bNum);
}

// 10. ���ú��׹�ʽ�����������
void heronFormula(){
	float a , b , c , s;
	printf("�����������������ߣ�");
	scanf_s("%f %f %f" , &a , &b , &c);

	s = (a + b + c) / 2;

	printf("�����ε����Ϊ��%f\n" , sqrt(s*(s - a)*(s - b)*(s - c)));

}

int main(){
	// revDec();
	// countOneInDec();
	// countStuFen();
	// simpleGame();
	// printNum();
	// changeTwoNum();
	heronFormula();
	system("pause");
	return 0;
}
