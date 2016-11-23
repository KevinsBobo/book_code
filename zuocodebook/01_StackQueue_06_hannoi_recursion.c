#include <stdio.h>

int hannoi(int num, char left, char mid, char right, char from, char to){
	if(num == 1){
		if(from == mid || to == mid){
			printf("Move 1 from %c to %c\n", from, to);
			return 1;
		}else{
			printf("Move 1 from %c to %c\n", from, mid);
			printf("Move 1 from %c to %c\n", mid, to);
			return 2;
		}
	}
	if(from == mid || to == mid){
		char another = (from == left || to == left) ? right : left;
		int part1 = hannoi(num - 1, left, mid, right, from, another);
		printf("Move %d from %c to %c\n", num, from, to);
		int part2 = 1;
		int part3 = hannoi(num - 1, left, mid, right, another, to);
		return part1 + part2 + part3;
	}else{
		// 我的方法
		int part1 = hannoi(num, left, mid, right, from, mid);
		int part2 = hannoi(num, left, mid, right, mid, to);
		return part1 + part2;
		/* // 左神的方法
		int part1 = hannoi(num - 1, left, mid, right, from, to);
		printf("Move %d from %c to %c\n", num, from, mid);
		int part2 = 1;
		int part3 = hannoi(num - 1, left, mid, right, to, from);
		printf("Move %d from %c to %c\n", num, mid, to);
		int part4 = 1;
		int part5 = hannoi(num - 1, left, mid, right, from, to);
		return part1 + part2 + part3 + part4 + part5;
		*/
	}
}

int main(){
	int num;
	while(scanf("%d", &num) != EOF)
		printf("Move %d floor\n%d\n", num, hannoi(num, 'A', 'B', 'C', 'A', 'C'));

	return 0;
}
