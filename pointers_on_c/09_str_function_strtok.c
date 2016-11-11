/*
 * 从一个字符数组中提取空白分隔符的标记并把他们打印出来（一行一个）
 * strtok找到line的下一个标记，并将其用NUL结尾（替换标记）
 * 返回一个指向这个标记前面第一个字符串的指针，如果没有匹配到则返回NULL
 *
 * 如果第一个参数不是NULL，那么函数将执行功能，并记录替换的标记的位置
 * 如果第一个参数是NULL，那么函数将从记录的位置后开始继续执行功能
 *
 * 如果line以设定的标记开头，那开头的标记将被忽略（即不用NUL替换），
 * 但该标记不计入返回的字符串中（即该标记被完全忽略），
 * 所以该函数也具有去除字符串开头的某些标记的功能
 * */
#include <stdio.h>
#include <string.h>

void print_tokens(char *line){
	static char whitespace[] = " \t\f\r\v\n";
	char *token;

	for(token = strtok(line, whitespace);
			token != NULL;
			token = strtok(NULL, whitespace))
		printf("Next token is %s\n", token);
}

int main(){
	char line[100] = " this is my space";
	print_tokens(line);
	return 0;
}
