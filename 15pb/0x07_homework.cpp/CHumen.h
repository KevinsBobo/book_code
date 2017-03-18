#pragma once
#include <iostream>
#include <string>
#include <cmath>

class CHuman
{
private:
	std::string name;
	int age;
	int high;
	int tizhong;
	int health;
public:
	void setInfo(std::string n , int a , int h , int t);
	std::string getName();
	int getAge();
	int getHigh();
	int getTizhong();
	double getHealth();
};