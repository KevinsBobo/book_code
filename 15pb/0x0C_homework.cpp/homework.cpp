#include <iostream>

// 二、上机基础 四、上机选做1
#include "delink.h"

int main(){
	// 二、上机基础、选做1测试用例
	// 创建链表
	CHdLink<int> myLink;
	for(int i = 10; i >= 0; i--){
		myLink.insert(i);
	}
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// 在8后面插入0
	myLink.insert(0 , myLink.find(8));
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// 将链表头指向数据为2的结点
	myLink.resetHead(myLink.find(2));
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// 删除数据为5的结点
	int e;
	myLink.del(myLink.find(5) , e);
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// 将数据为3的节点的数据重置为0
	myLink.reset(myLink.find(3) , 0);
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// 将链表头指向数据为7的结点
	myLink.resetHead(myLink.find(7));
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;
	// 清空链表
	myLink.clear();
	myLink.echo();
	std::cout << myLink.getSize() << std::endl;


	return 0;
}