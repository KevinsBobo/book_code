#include <stdio.h>
#include <string.h>

// 书中提供的效率高的解决方法
void dollars(register char *dest, register char const *src){
	if(dest == NULL || src == NULL)
		return;

	int menoylen = strlen(src);
	*dest++ = '$';
	
	if(menoylen >= 3){
		for(int i = menoylen - 2; i > 0; ){
			*dest++ = *src++;
			if(--i > 0 && i % 3 == 0)
				*dest++ = ',';
		}
	}else
		*dest++ = '0';
	*dest++ = '.';
	*dest++ = menoylen < 2 ? '0' : *src++;
	*dest++ = menoylen < 1 ? '0' : *src;
	*dest = '\0';

}

// 实现效果差的方法
void my_dollars(char *dest, char const *src){
	int menoylen = strlen(src);
	strcpy(dest, "$");
	if(menoylen == 0)
		strcat(dest, "0.00");
	else if(menoylen == 1){
		strcat(dest, "0.0");
		strcat(dest, src);
	}else if(menoylen == 2){
		strcat(dest, "0.");
		strcat(dest, src);
	}else{
		menoylen -= 2;
		int first = 0;
		if(menoylen % 3 > 0){
			first = menoylen % 3;
			strncat(dest, src, first);
			src += first;
		}
		while(menoylen - first > 0){
			if(dest[1] != '\0')
				strcat(dest, ",");
			strncat(dest, src, 3);
			src += 3;
			menoylen -= 3;
		}
		if(*src != '\0'){
			strcat(dest, ".");
			strcat(dest, src);
		}
	}
}

int main(){
	char menoy[100];
	while(scanf("%s", menoy) != EOF){
		char dest[100];
		dollars(dest, menoy);
		printf("%s\n", dest);
	}
}
