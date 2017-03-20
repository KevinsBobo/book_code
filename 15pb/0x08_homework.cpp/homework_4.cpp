#include <iostream>
#include <string.h>

class CStr
{
public:
	CStr() :str(NULL);
	CStr(char *szBuff){
		unsigned int len = strlen(szBuff);
		str = new char[ len + 1 ];
		strcpy_s(str , len + 1 , szBuff);
	}
	CStr(CStr &cStr){
		unsigned int len = strlen(cStr.str);
		str = new char[ len + 1 ];
		strcpy_s(str , len + 1 , cStr.str);
	}
	~CStr(){
		if(str != NULL){
			delete str;
			str = NULL;
		}
	}
	void setStr(char *szBuff){
		delete str;
		unsigned int len = strlen(szBuff);
		str = NULL;
		str = new char[ len + 1 ];
		if(str != NULL){
			strcpy_s(str , len + 1 , szBuff);
		}
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
	int getStrLen();
private:
	char *str;
};