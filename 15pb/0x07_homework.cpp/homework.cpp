#include <iostream>
#include <cstdlib>
#include <string>
#include "CLiFang.h"
#include "CHumen.h"

// 2. 打印杨辉三角
void coutYanHei(){
	int nRow = 6;
	for(int i = 0; i < nRow; i++){
		for(int j = 0; j < nRow * 2; j++){
			if(j < nRow - i || j > nRow + i){
				std::cout << " ";
			}
			else{
				std::cout << i - abs(j - nRow) + 1;
			}
		}
		std::cout << std::endl;
	}
}

// 4. 不使用指针交换两个数的变量
void chNum(int &a , int &b){
	a ^= b;
	b ^= a;
	a ^= b;
}

// 6. 立方体类
void fLiFang(){
	CLiFang a;
	a.siteNum(5 , 6 , 2);
	std::cout << a.getLiFang() << std::endl;
}

// 8. 人类
void human(){
	CHuman *CBuff[ 10 ];
	std::string name;
	int age;
	int high;
	int tizhong;
	for(int i = 0; i < 10; i++){
		CBuff[ i ] = new CHuman;
		std::cin >> name >> age >> high >> tizhong;
		CBuff[ i ]->setInfo(name , age , high , tizhong);
	}
	for(int i = 0; i < 10; i++){
		std::cout << "姓名：" << CBuff[ i ]->getName() << "年龄"
			<< CBuff[ i ]->getAge() << "身高" << CBuff[i]->getHigh()
			<< "体重" << CBuff[i]->getTizhong() << "健康指数"
			<< CBuff[i]->getHealth() << std::endl;
		delete CBuff[ i ];
	}
}

int main(){
	// coutYanHei();
	// fLiFang();
	human();

	system("pause");
	return 0;
}