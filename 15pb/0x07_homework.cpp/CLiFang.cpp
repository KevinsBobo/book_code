#include "CLiFang.h"
void CLiFang::siteNum(int l , int w , int h){
	lenght = l;
	width = w;
	hight = h;
}
int CLiFang::getLiFang(){
	return lenght * width * hight;
}