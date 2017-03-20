#include <iostream>
#include <cstring>

// 2. 设计一个CTime类
class CTime
{
public:
	CTime(int h , int m , int s) :m_nHour(h) , m_nMin(m) , m_nSec(s){}
	void setHour(int y);
	void setMin(int m);
	void setSec(int s);
	int getHour();
	int getMin();
	int getSec();

private:
	int m_nHour;
	int m_nMin;
	int m_nSec;
};
void CTime::setHour(int y){
	m_nHour = y;
}
void CTime::setMin(int m){
	m_nMin = m;
}
void CTime::setSec(int s){
	m_nSec = s;
}
int CTime::getHour(){
	return m_nHour;
}
int CTime::getMin(){
	return m_nMin;
}
int CTime::getSec(){
	return m_nSec;
}

// 3. 4. 5. 6. 7. 学生、老师类
class CTeacher
{
public:
	int getStuId(CStudent stu);
	void setStuId(CStudent &stu, int id);
};

class CStudent
{
public:
	CStudent() :m_nAge(0) , m_nId(0) , m_szName(NULL){};
	CStudent(char *szName , int nAge , int nId){
		unsigned int nSize = strlen(szName);
		m_szName = new char[ nSize + 1 ];
		strcpy_s(m_szName , nSize + 1 , szName);
		++nCount;
	}
	CStudent(CStudent &cpyObj){
		unsigned int nSize = strlen(cpyObj.m_szName);
		m_szName = new char[nSize + 1];
		strcpy_s(m_szName , nSize + 1 , cpyObj.m_szName);
		m_nAge = cpyObj.m_nAge;
		m_nId = cpyObj.m_nId;
		++nCount;
	}
	~CStudent(){
		if(m_szName != NULL){
			delete m_szName;
			m_szName = NULL;
		}
	}
	friend CTeacher;

private:
	char *m_szName;
	int   m_nAge;
	int   m_nId;
	static int nCount;
};

int CStudent::nCount = 0;

int CTeacher::getStuId(CStudent stu){
	return stu.m_nId;
}

void CTeacher::setStuId(CStudent &stu, int id){
	stu.m_nId = id;
}

int main(){

	return 0;
}