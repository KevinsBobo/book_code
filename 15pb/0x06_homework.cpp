#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// 上机题
// 2. 定义字符指针数组 3. 用指针访问不同的字符串
void initPointCharArr(){
	char *pSzBuff[] = { "Hello" , "15pb" , "Change" , "World" };
	char **p = pSzBuff;
	for(int i = 0; i < sizeof(pSzBuff) / sizeof(pSzBuff[ 0 ]); i++)
		printf("%s\n" , *(p + i));
}

// 4. 定义函数指针并传参
int add(int a , int b){
	return a + b;
}
int ddd(int a , int b){
	return a - b;
}
int xxx(int a , int b){
	return a * b;
}
int ccc(int a , int b){
	return a / b;
}
int todo(int(*fun)(int , int) , int a , int b){
	return fun(a , b);
}
void myOprtion(){
	int a = 10 , b = 5;
	printf("%d\n" , todo(&add , a , b));
	printf("%d\n" , todo(&ddd , a , b));
	printf("%d\n" , todo(&xxx , a , b));
	printf("%d\n" , todo(&ccc , a , b));
}

// 5. 保存书信息的结构体
typedef struct BookInfo
{
	char *bookName;
	char *whoWrite;
	int  price;
} myBookInfo , *pMyBook;
void freeAllBook(pMyBook pBook[] , int nCount){
	for(int i = 0; i < nCount; i++){
		free(pBook[ i ]);
		pBook[ i ] = NULL;
	}
}
int initBook(pMyBook pBook[] , int nCount){
	for(int i = 0; i < nCount; i++){
		pBook[ i ] = (pMyBook)malloc(sizeof(myBookInfo));
		if(pBook[ i ] == NULL){
			freeAllBook(pBook , nCount);
			return 0;
		}
	}
	return 1;
}
void myBook(){
	pMyBook bookA[ 20 ] = { NULL };
	char szName[ 20 ][ 20 ] , szWho[ 20 ][ 20 ];
	int bNum = 0;

	printf("请输入书的数量：");
	scanf_s("%d" , &bNum);

	if(!initBook(bookA , bNum)){
		printf("内存分配失败！\n");
		return;
	}

	for(int i = 0; i < bNum; i++){

		printf("请输入书名：");
		scanf_s("%s" , szName[ i ] , 20);
		bookA[ i ]->bookName = szName[ i ];
		printf("请输入作者：");
		scanf_s("%s" , szWho[ i ] , 20);
		bookA[ i ]->whoWrite = szWho[ i ];
		printf("请输入价格：");
		scanf_s("%d" , &bookA[ i ]->price);
	}

	for(int i = 0; i < bNum; i++){
		printf("书名：%s, 作者：%s, 价格：%d\n" , \
			   bookA[ i ]->bookName , bookA[ i ]->whoWrite , bookA[ i ]->price);

	}
	freeAllBook(bookA , bNum);
}

// 6. 文件读写操作
void writefile(){
	FILE *fpFile;
	char szBuff[ 20 ];
	char sBuff[ 20 ];
	printf("请输入字符串：");
	scanf_s("%s" , szBuff , 20);

	printf("%d\n" , (fopen_s(&fpFile , "D:\\a.txt" , "w+")));
	fputs(szBuff , fpFile);

	rewind(fpFile);
	fgets(sBuff ,20 , fpFile);
	printf("文件内容为：%s\n" , sBuff);

	fclose(fpFile);
}

// 8. 移动文件
void movefile(int argc , char *argv[]){
	FILE *fpFileA;
	FILE *fpFileB;
	int cTemp;
	if(argc == 3){
		printf("%d\n" , (fopen_s(&fpFileA , argv[ 1 ] , "r")));
		printf("%d\n" , (fopen_s(&fpFileB , argv[ 2 ] , "w")));

		rewind(fpFileA);

		//printf("%c\n" , fgetc(fpFileA));
		while((cTemp = fgetc(fpFileA)) != EOF){
			printf("%c\n", cTemp);
			fputc(cTemp , fpFileB);
		}
		fclose(fpFileA);
		fclose(fpFileB);
		remove(argv[ 1 ]);
	}
}

int main(int argc , char *argv[]){
	//initPointCharArr();
	//myOprtion();
	//myBook();
	//writefile();
	//movefile(argc , argv);

	system("pause");
	return 0;
}
