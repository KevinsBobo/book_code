#include <iostream>

// �����ϻ����� �ġ��ϻ�ѡ��1
#include "delink.h"

int main(){
	// �����ϻ�������ѡ��1��������
	// ��������
	CHdLink<int> myLink;
	for(int i = 10; i >= 0; i--){
		myLink.insert(i);
	}
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// ��8�������0
	myLink.insert(0 , myLink.find(8));
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// ������ͷָ������Ϊ2�Ľ��
	myLink.resetHead(myLink.find(2));
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// ɾ������Ϊ5�Ľ��
	int e;
	myLink.del(myLink.find(5) , e);
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// ������Ϊ3�Ľڵ����������Ϊ0
	myLink.reset(myLink.find(3) , 0);
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// ������ͷָ������Ϊ7�Ľ��
	myLink.resetHead(myLink.find(7));
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// �������
	myLink.clear();
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;


	return 0;
}