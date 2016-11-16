#include <stdio.h>
#include <string.h>

/*
 * 将digit_string中的数字按照format_string中的格式
 * 输出到format_string中去
 *
 * 格式字符串中 # 代表数字 . 代表小数点 其他是分隔符
 * 如果格式字符串中的 # 数量小于将输出的数字，则视为错误输入
 * 如果格式字符串中的 # 数量大于将输出的数字，多余的用空格代替
 * 多余的分隔符也将用空格代替
 *
 * 例：
 *     输入的金额数为：1234567
 *     格式字符串内容：#,###,###.##
 *     格式化后保存为：   12,345.67
 *
 * 成功输出返回真
 * 否则返回假
 *
 * 书中答案与此程序的不同（下面进行了相应修改，或在注释中体现）：
 * 1. 在寻找字符串末尾采用开始指针加上字符串长度-1。
 * 2. 没有按照题目要求的方式测试格式中 # 的数量是否大于或等于金额字符串长度。
 * 3. 增加了判断金额字符串是否合法，即 money >= digit_string 为合法。
 * 4. 在执行替换 # 操作的循环条件中加入了 type >= format_string 的判断，
 *    即防止格式字符串指针超出界限，但如果前面测试了 # 数量需要大于
 *    金额字符串长度的话这一步判断则不是必须的。
 * 5. 在执行替换 # 的循环中加入判断，如果是 # 则替换，否则指针向左移动，
 *    不同于我才用的如果不是 # 则直接替换当前指针左边指针指向的值，
 *    如果分隔符是两个或两个以上的话我写的操作将产生错误的结果。
 * 6. 将处理小数点的操作和执行将多余格式符号替换为空格的操作放在了一起，
 *    即先进行将多余的非小数点符号替换为空格，当碰到小数点时再将小数点右边
 *    的空格替换为0，最后将小数点左边第一位数替换为0，将指针指向小数点左边第二位，
 *    然后继续将多余的符号替换为空格。此方法在效率和可读性上都比我写的好，
 *    因为我写的操作中必须提前找到小数点的位置，增加了机器执行的指令。
 * */
int format( char *format_string,
		char const *digit_string){
	
	// 验证传入字符串
	if(format_string == NULL || digit_string == NULL)
		return 0;
	
	// 新建指针用于操作字符串，从而保存字符串初始指针
	char *type   = format_string;
	char *menoy;  //= digit_string; // 这里编译器警告指针digit_string内容为不可修改的
	// 计算待格式化的字符串大小
	int menoylen = strlen(digit_string);
	// 用于保存格式字符串中 # 的数量
	int typenumlen = 0;
	
	// 计算格式字符串中 # 的数量
	while(1){
		type = strchr(type, '#');
		if(type != NULL){
			typenumlen++;
			type++;
		}else
			break;
	}
	
	// 将type指针重置为字符串开头
	type = format_string;
	
	// 如果格式字符串中 # 的数量小于金额字符串的数量返回假
	if(menoylen > typenumlen)
		return 0;
	
	// 将type和menoy指针分别只想对应的字符串末尾
	// 更好的方法：
	type  = format_string + strlen(format_string) - 1;
	// 仍旧有警告
	menoy = digit_string  + strlen(digit_string)  - 1;
	/*
	while(*type != '\0')
		type++;
	type -= 1;
	while(*menoy != '\0')
		menoy++;
	menoy -= 1;
	*/
	
	// 将格式字符串中的 # 替换为数字
	while(menoy >= digit_string){
		if(*type == '#')
			*type-- = *menoy--;
		/*
		 else{
			*(--type) = *menoy--;
			type--;
		}
		*/
		// 更好地方法：
		else
			type--;
	}

	/*
	// 将doll指针指向小数点的位置
	char *doll = strchr(format_string, '.');
	// 如果存在小数点，则检查小数点左边的值是否为 #
	// 如果是则代表金额小于1，将小数点左右的 # 替换为 0
	if(doll++ != NULL && *(doll - 2) == '#'){
		// 将type指针指向小数点前2位，即从右到左第一位 # 的位置
		type = doll - 3;
		*(doll - 2) = '0';
		while(*doll == '#'){
			*doll++ = '0';
		}
	}
	
	// 将未替换的 # 及无效的分隔符替换为空格
	while(type - format_string >= 0){
		*type-- = ' ';
	}
	*/

	// 更好地方法（将以上两块结合）：
	
	 while(type >= format_string){
	 	if(*type == '.'){
			char *doll = type + 1;
			while(*doll == ' ')
				*doll++ = '0';
			*(type - 1) = '0';
			type -= 2;
		}
		*type-- = ' ';
	 }
	 

	return 1;
}

int main(){
	char menoy[100];
	char type[100];
	printf("input the menoy: ");

	while(scanf("%s", menoy) != EOF){
		printf("input the type : ");
		scanf("%s", type);

		if(format(type, menoy))
			printf("output the type: %s\n", type);
		else
			printf("input was wrong!\n");
	
		printf("input the menoy: ");
	}
}
