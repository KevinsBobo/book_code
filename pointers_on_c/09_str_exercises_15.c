#include <stdio.h>
#include <string.h>

void dollars(char *dest, char const *src){
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
