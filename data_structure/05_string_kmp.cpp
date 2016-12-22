#include <cstdio>
#include <cstring>

typedef struct {
    int len;
    char *text;
} String;

void get_next(const String *T, int *nextArr){
    int i, j;
    i = 0;
    j = -1;
    nextArr[0] = -1;

    while(i < T->len){
        if(j != -1 && T->text[i] != T->text[j])
            j = nextArr[j];
        else
            nextArr[++i] = ++j;
    }
}

int main(){
    char a[] = "ababaaaba";
    String test;
    int nextArr[1000];

    test.len = strlen(a);
    test.text = a;

    get_next(&test, nextArr);

    for(int i = 0; i < test.len; i++)
        printf("%d ", nextArr[i]);

    printf("\n");

    return 0;
}
