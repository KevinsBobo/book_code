#include <stdio.h>
#include <stdlib.h>

// ���õݹ�ת������ӡ������
void printDec(long long num , int temp, int printSpace){
	// �ݹ���ֹ���������ڲ�����λ�Ķ�������ǰ�油��
	if(num == 0){
		while(4 - printSpace > 0){
			printf("0");
			printSpace++;
		}
		return;
	}

	temp = num % 2; // ��������Ƶ�ǰλ��ֵ
	num /= 2;
	printSpace = printSpace++ % 4; // ���㵱ǰ�����Ƶ�λ�ã���������ո�

	// �ݹ����
	printDec(num , temp , printSpace);

	// ÿ����4λ�����ƣ����ӡһ���ո�
	if(printSpace == 4) printf(" ");

	printf("%d" , temp);

}

int main(){
	// printf("Hello15PB\n");

	long long num = 455897641;
	int temp = 0;
	int printSpace = 0;
	long long numtemp = num;

	/* ��ӡ������� ��ʼ */
	printf("%9d\n\t/ 2\n" , num);
	while(numtemp > 0){
		temp = numtemp % 2;
		numtemp /= 2;

		printf("%9d    --" , numtemp);
		printf("%4d\n" , temp);

		if(numtemp != 0)
			printf("\t/ 2\n");
	}
	/* ��ӡ������� ���� */
	
	// ����
	temp = 0;

	// ���㲢��ӡת����Ķ�����
	printf("DEC : ");
	printDec(num , temp, printSpace);
	printf("\n");

	system("pause");
	return 0;
}