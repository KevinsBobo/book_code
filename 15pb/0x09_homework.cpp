#include <iostream>
#include <string.h>


// 2. 继承COORD
class COORD
{
protected:
	int m_x;
	int m_y;
};

typedef enum coorAct { u = 0 , d , l , r } coorAct;

class CMyCoord: public COORD
{
public:
	CMyCoord(int x , int y , coorAct act) : m_x(x) , m_y(y) , m_act(act){}

	CMyCoord& operator++(){
		++m_x;
		return *this;
	}
	CMyCoord& operator++(int){
		++m_y;
		return *this;
	}

	CMyCoord& operator--(){
		--m_x;
		return *this;
	}
	CMyCoord& operator--(int){
		--m_y;
		return *this;
	}

	void moveStep(){
		switch(m_act){
			case u: --(*this); break;
			case d: ++(*this); break;
			case l: (*this)--; break;
			case r: (*this)++; break;
			default: break;
		}
	}

private:
	coorAct m_act;
};


// 3. 4. 5. 字符串类
class CStr
{
public:
	CStr(){
		str = new char[ 20 ];
		strLen = 0;
	}
	CStr(char *szBuff){
		unsigned int len = strlen(szBuff);
		str = new char[ len + 1 ];
		strcpy_s(str , len + 1 , szBuff);
		strLen = len;
	}
	CStr(CStr &cStr){
		unsigned int len = strlen(cStr.str);
		str = new char[ len + 1 ];
		strcpy_s(str , len + 1 , cStr.str);
		strLen = len;
	}
	~CStr(){
		if(str != NULL){
			delete str;
			str = NULL;
		}
	}
	void setStr(char *szBuff){
		delete str;
		str = NULL;
		unsigned int len = strlen(szBuff);
		str = new char[ len + 1 ];
		if(str != NULL){
			strcpy_s(str , len + 1 , szBuff);
			strLen = len;
		}
		else
			strLen = 0;
	}
	void clrStr(){
		if(str != NULL){
			delete str;
			str = NULL;
		}
	}
	char getStrI(int i){
		if(str != NULL){
			return str[ i ];
		}
	}
	char steStrI(int i , char c){
		if(str != NULL){
			str[ i ] = c;
		}
	}
	int getStrLen(){
		return strLen;
	}

	// 重载输入输出
	friend std::istream &operator>>(std::istream &i, CStr &obj){
		i >> obj.str;
		return i;
	}
	friend std::ostream &operator<<(std::ostream &o , CStr &obj){
		o << obj.str;
		return o;
	}

	// 重载 + = += [] ==
	CStr &operator+(CStr &obj){
		unsigned int strALen = strlen(this->str);
		unsigned int strBLen = strlen(obj.str);
		char *szBuff = new char[ strALen + strBLen + 1 ];
		strcpy_s(szBuff , strALen + 1 , this->str);
		strcpy_s(szBuff + strALen , strBLen + 1 , obj.str);
		CStr *temp = new CStr(szBuff);
		delete szBuff;
		return *temp;
	}
	CStr &operator=(CStr &obj){
		unsigned int len = strlen(obj.str);
		delete this->str;
		this->str = new char[ len + 1 ];
		strcpy_s(this->str , len + 1 , obj.str);
		return *this;
	}
	CStr &operator+=(CStr &obj){
		*this = *this + obj;
		return *this;
	}
	char operator[](int i){
		return this->str[ i ];
	}
	bool operator==(CStr &obj){
		return (strcmp(this->str , obj.str) == 0) ? true : false;
	}

	// 重载和const *字符串比较
	bool operator==(const char *szBuff){
		return (strcmp(this->str , szBuff) == 0) ? true : false;
	}
private:
	char *str;
	int strLen;
};

int main(){
	// 第2题 测试用例
	coorAct act = l;
	CMyCoord testCoor(15 , 15 , act);
	++testCoor;
	--testCoor;
	testCoor++;
	testCoor--;
	++testCoor++;
	--testCoor--;
	testCoor.moveStep();

	// 第3 4 5题 测试用例

	CStr myStr("abcdef");
	std::cout << myStr <<std::endl;

	CStr inStr;
	std::cin >> inStr;
	std::cout << inStr << std::endl;

	CStr addStr = myStr + inStr;
	std::cout << addStr << std::endl;

	CStr fuStr = addStr;
	fuStr = addStr;
	std::cout << fuStr << std::endl;

	CStr addFuStr(inStr);
	addFuStr += fuStr;
	std::cout << addFuStr << std::endl;

	std::cout << addFuStr[ 12 ] << std::endl;

	std::cout << (addFuStr == fuStr) << std::endl;
	std::cout << (addStr == fuStr) << std::endl;

	std::cout << (myStr == "abcdef") << std::endl;

	return 0;
}