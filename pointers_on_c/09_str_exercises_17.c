#include <stdio.h>
#include <string.h>

// 书中的答案
char *edit(register char *pattern, register char *digits){
	register int  digit;
	register int  pat_char;
	register int  fill;
	register int  signif;
	register char *first_digit;

	if(pattern == NULL || digits == NULL || (fill = *pattern) == '\0')
		return NULL;
	first_digit = NULL;
	signif      = 0;

	while((pat_char = *++pattern) != '\0'){
		switch(pat_char){
			case '#':
			case '!':
				if((digit = *digits++) == '\0'){
					*pattern = '\0';
					return first_digit;
				}
				if(digit == ' ')
					digit  = '0';

				if(digit != '0' || pat_char == '!'){
					if(!signif)
						first_digit = pattern;
					signif = 1;
				}
				break;
			default:
				digit = pat_char;
				break;
		}
		*pattern = signif ? digit : fill;
	}
	return first_digit;
}

// 我的方法
char *my_edit(char *pattern, char const *digits){
	if(pattern == NULL || digits == NULL)
		return NULL;
	int signif = 0;
	char *pattern_p = pattern + strlen(pattern) - 1;
	char *digits_p  = digits + strlen(digits) - 1;
	char *return_p = NULL;
	
	pattern += 1;
	while(digits <= digits_p && pattern <= pattern_p){
		if(signif == 0){

			if(*digits == '0' || *digits == ' '){
				if((*(pattern + 1) == '#' || *(pattern + 1) == '!') && *pattern != '!')
					digits += 1;
				if(*pattern == '!'){
					*pattern = '0';
					return_p = pattern;
					signif = 1;
					digits += 1;
				}else
					*pattern = *(pattern - 1);
			}else if(*pattern == '#' || *pattern == '!'){
				*pattern = *digits++;
				signif = 1;
				return_p = pattern;
			}
 
		}else if(signif == 1 && (*pattern == '#' || *pattern == '!')){
			*pattern = (*digits == ' ') ? '0' : *digits;
			digits += 1;
		}
		pattern++;
	}
	
	if(signif == 1)
		*pattern = '\0';

	return return_p;


}

int main(){
	char menoy[100];
	char type[100];
	char *outputnum;
	char temp;
	printf("input the menoy: ");

	while(scanf("%[^\n]", menoy) != EOF){
		printf("input the type : ");
		scanf("%c", &temp);
		scanf("%[^\n]", type);
		scanf("%c", &temp);

		outputnum = edit(type, menoy);
		printf("output the type: %s\n", type);
		printf("output the nume: %s\n", outputnum ? outputnum : "NULL");

		printf("input the menoy: ");
	}
}
