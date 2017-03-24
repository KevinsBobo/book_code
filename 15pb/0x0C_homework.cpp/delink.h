#pragma once
#include <iostream>

/*********************
双向循环链表 - 链式存储
**********************/

// 链表头声明
template <class T>
class CHdLink;

// 结点数据结构
template <class T>
class CDeLink
{
public:
	CDeLink(T e) :m_data(e) , next(nullptr) , pre(nullptr){}
	friend CHdLink<T>;
private:
	T m_data;
	CDeLink *next;
	CDeLink *pre;
};

typedef enum {outOfintheSide = -1, stackIsEmpty = 0, success = 1} theError;

// 链表头
template <class T>
class CHdLink
{
public:
	CHdLink() :m_size(0) , theStack(nullptr){}

	// 在头部插入
	theError insert(T e){
		CDeLink<T> *temp = new CDeLink<T>(e);
		if(this->theStack != nullptr){
			temp->pre = this->theStack->pre;
			this->theStack->pre = temp;
			temp->next = this->theStack;
			temp->pre->next = temp;
			this->theStack = temp;
		}
		else{
			temp->pre = temp;
			temp->next = temp;
			this->theStack = temp;
		}
		++m_size;
		return success;
	}
	// 指定插入位置，插入传入结点指针之后
	theError insert(T e , CDeLink<T> *p){
		CDeLink<T> *temp = new CDeLink<T>(e);
		if(p == nullptr)
			return outOfintheSide;
		temp->pre = p;
		p->next->pre = temp;
		temp->next = p->next;
		p->next = temp;
		++m_size;

		return success;
	}
	// 删除指定节点
	theError del(CDeLink<T> *p , T &e){
		if(this->theStack == nullptr)
			return stackIsEmpty;
		else if(p == nullptr)
			return outOfintheSide;

		if(p == this->theStack){
			this->theStack = p->next;
		}
		if(p->next == p && p->pre == p){
			this->theStack = nullptr;
		}
		p->next->pre = p->pre;
		p->pre->next = p->next;

		e = p->m_data;
		delete p;
		p = nullptr;
		--m_size;
		return success;
	}
	// 设置指定节点数据
	theError reset(CDeLink<T> *p , T e){
		if(this->theStack == nullptr)
			return stackIsEmpty;
		else if(p == nullptr)
			return outOfintheSide;

		p->m_data = e;
		return success;
	}
	// 清空链表
	theError clear(){
		T e;
		while(this->theStack != nullptr){
			this->del(this->theStack , e);
		}
		m_size = 0;
		return success;
	}
	// 寻找某数据，返回节点指针
	CDeLink<T> *find(T e){
		if(this->theStack == nullptr)
			return nullptr;

		CHdLink<T> *temp = new CHdLink<T>(*this);
		do{
			if(temp->theStack->m_data == e)
				return temp->theStack;
			temp->theStack = temp->theStack->next;
		} while(temp->theStack != this->theStack);

		return nullptr;
	}
	// 输出链表
	void echo(){
		if(this->theStack == nullptr){
			std::cout << "空链表" << std::endl;
			return;
		}
		CHdLink<T> *temp = new CHdLink<T>(*this);
		do{
			std::cout << temp->theStack->m_data << "->";
			temp->theStack = temp->theStack->next;
		} while(temp->theStack != this->theStack);
		std::cout << std::endl;

		temp->theStack = temp->theStack->pre;
		do{
			std::cout << temp->theStack->m_data << "<-";
			temp->theStack = temp->theStack->pre;
		} while(temp->theStack != this->theStack->pre);
		std::cout << std::endl;
	}
	// 获得链表大小
	int getSize(){
		return m_size;
	}
	// 改变头结点指向
	void resetHead(CDeLink<T> *temp){
		this->theStack = temp;
	}

private:
	int m_size;
	CDeLink<T> *theStack;
};