#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string strName;
	string strAddress;

public:
	Person() = default;
	Person(const string &name, const string &add): strName(name), strAddress(add) { }
	Person(istream &is){ is >> this->strName; }
	string getName() const { return strName; }
	string getAddress() const { return strAddress; }
};
