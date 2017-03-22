#include <iostream>
#include <string>

// 三、上机题
// 2. 编写一个学生和教师数据输入和显示的函数
class CPerson
{
public:
	virtual ~CPerson();
protected:
	int m_id;
	char *m_name;
};
class CStudent: CPerson
{
public:
	CStudent(int id, char *szBuff , int classId , int source) :
		m_classId(classId), m_source(source){
		m_id = id;
		int len = strlen(szBuff);
		m_name = new char[ len + 1 ];
		strcpy_s(m_name , len + 1 , szBuff);
	}
	~CStudent(){
		delete m_name;
		m_name = NULL;
	}
private:
	int m_classId;
	int m_source;
};
class CTeacher : CPerson
{
public:
	CTeacher(int id , char *szName , char *zhi , char *bu){
		m_id = id;
		int len = strlen(szName);
		m_name = new char[ len + 1 ];
		strcpy_s(m_name , len + 1 , szName);
		len = strlen(zhi);
		m_zhicheng = new char[ len + 1 ];
		strcpy_s(m_zhicheng, len + 1, zhi);

		len = strlen(bu);
		m_bumen = new char[ len + 1 ];
		strcpy_s(m_bumen , len + 1 , bu);
	}
	~CTeacher(){
		delete m_name;
		delete m_zhicheng;
		delete m_bumen;
		m_name = NULL;
		m_zhicheng = NULL;
		m_bumen = NULL;
	}

private:
	char *m_zhicheng;
	char *m_bumen;
};


// 4. 计算教师工资
class CTeacherMenoy
{
public:
	virtual ~CTeacherMenoy();
protected:
	int m_menoy;
	int m_butie;
};
class CJaoshou : public CTeacherMenoy
{
public:
	CJaoshou(){
		m_menoy = 3000;
		m_butie = 30;
	}
};
class CJiangshi : public CTeacherMenoy
{
public:
	CJiangshi(){
		m_menoy = 2000;
		m_butie = 20;
	}
};


// 6. 带查询功能的类模板
template <typename T>
class CSearch
{
public:
	CSearch(){
		i = 0;
	}
	void setA(T m){
		a[ i++ ] = m;
	}
	int search(T m){
		for(int j = 0; j < i; j++){
			if(a[ j ] == m)
				return j;
		}
	}
private:
	T a[ 100 ];
	int i;
};


// 8. 继续完善字符串类
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
	friend std::istream &operator>>(std::istream &i , CStr &obj){
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

	// 查找
	int find(char a){
		for(int i = 0; i < strLen; i++){
			if(str[ i ] == a)
				return i;
		}
		return -1;
	}

	int find(char *a){
		char *f = strstr(str, a);
		if(f != NULL)
			return f - str;
		else
			return -1;
	}

	// 插入
	void insert(char a, int i){
		char *temp = new char(strLen + 2);
		char t = str[ i ];
		str[ i ] = '\0';
		strcpy_s(temp , i+1 , str);
		temp[ i ] = a;
		str[ i ] = t;
		strcpy_s(temp + i + 1 , strLen - i + 1 , str + i);
		delete str;
		str = temp;
		++strLen;
	}
	void insert(char *a , int i){
		int aLen = strlen(a);
		char *temp = new char(strLen + aLen + 1);
		char t = str[ i ];
		str[ i ] = '\0';
		strcpy_s(temp , i + 1 , str);
		str[ i ] = t;
		strcpy_s(temp + i , aLen + 1 , a);
		strcpy_s(temp + i + aLen , strLen - i + 1 , str + i);
		delete str;
		str = temp;
		strLen += aLen;
	}
private:
	char *str;
	int strLen;
};



int main(){
	CStr myStr("abcdefghijklmnopqrstuvwxyz");
	int i = myStr.find('k');
	if(i != -1)
		myStr.insert('k' , i);

	i = myStr.find("stu");
	if(i != -1)
		myStr.insert("stu" , i);

	return 0;
}