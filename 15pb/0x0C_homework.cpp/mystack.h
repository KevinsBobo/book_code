#include <iostream>

template <class T>
class CMyStack
{
public:
	CMyStack(T e) :m_data(e), next(nullptr),pre(nullptr);
	CMyStack(CMyStack &obj);
	virtual ~CMyStack();
private:
	T m_data;
	CMyStack *next;
	CMyStack *pre;
};

typedef enum {outOfTheSide = -1, stackIsEmpty = 0, success = 1} theError;

template <class T>
class CHdStack
{
public:
	CHdStack() :m_size(0) , theStack(nullptr);
	CHdStack(CHdStack &obj);
	virtual ~CHdStack();

	theError insert(T e);
	theError insert(T e , CMyStack &p);
	theError del(CMyStack &p , T &e);
	theError reset(CMyStack &p , T e);
	theError clear();
	CMyStack &find(T e);

	int getSize();

private:
	int m_size;
	CMyStack<T> *theStack;
};