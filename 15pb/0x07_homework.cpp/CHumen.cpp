#include "CHumen.h"

void CHuman::setInfo(std::string n , int a , int h , int t){
	name = n;
	age = a;
	high = h;
	tizhong = t;
	health = pow((tizhong / high), 3);
}

std::string CHuman::getName(){
	return name;
}
int CHuman::getAge(){
	return age;
}
int CHuman::getHigh(){
	return high;
}
int CHuman::getTizhong(){
	return tizhong;
}
double CHuman::getHealth(){
	return health;
}