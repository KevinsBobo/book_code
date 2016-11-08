/*
 * 使用递归实现将无符号整数转换为英文单词形式
 * */
#include <stdio.h>
#include <string.h>

static char *digits[] = {
	"", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ", "EIGHT ",
	"NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ", "FOURTEEN ", "FIFTEEN ",
	"SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ", "NINETEEN"
};

static char *tens[] = {
	"", "", "TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "EIXTY ", "SEVEnTY ",
	"EIGHTY ", "NINETY "
};

static char *magnitudes[] = {
	"", "THOUSAND ", "MILLION ", "BILLION "
};

void do_one_group( unsigned int amount, char *buffer, char **magnitude){
	int value;

	value = amount / 1000;
	if(value > 0){
		do_one_group( value, buffer, magnitude + 1);
	}
	
	amount %= 1000;
	value  =  amount / 100;
	if(value > 0){
		strcat( buffer, digits[value]);
		strcat( buffer, "HUNDRED ");
	}

	value = amount % 100;
	if(value >= 20){
		strcat( buffer, tens[value / 10]);
		value %= 10;
	}
	if(value > 0){
		strcat( buffer, digits[value]);
	}

	if(amount > 0){
		strcat( buffer, *magnitude);
	}
}

void written_amount( unsigned int amount, char *buffer){
	if(amount == 0){
		strcpy(buffer, "ZERO");
	}else{
		*buffer = '\0';
		unsigned int value = amount;
		do_one_group( value, buffer, magnitudes);
	}
}

int main(){
	unsigned int amount;
	char buffer[100];
	while(scanf("%u", &amount) != EOF){
		written_amount(amount, buffer);
		printf("%s\n", buffer);
	}
	return 0;
}
