#include <stdio.h>
#include <string.h>

#define MAXLEN 20

typedef struct szWord{
    char *pWord;
    szWord *next;
} szWord;

typedef struct szIndex{
    char fWord;
    szIndex *next;
    szWord *wdHead;
}

typedef enum select {
    Input = 1, Check, find, clear
} select;

int main(){
    freopen("./12_struct&pointer_exercises_7.in.test", "r", stdin);
    freopen("./12_struct&pointer_exercises_7.out.test", "w", stdout);

    char szBuff[MAXLEN];
    printf("Please Input A Word: ");
    scanf("%s", szBuff);

    
    return 0;
}
