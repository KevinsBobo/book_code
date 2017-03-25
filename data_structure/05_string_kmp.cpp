#include <cstdio>
#include <cstring>

#define DEBUG

typedef struct {
    int len;
    char *text;
} String;

/**********************************************
 获取next数组：
    从前往后，每个子串前后缀中有 n 个字母相等
    就在next数组中代表子串后一位的位置中记录下 n
***********************************************/
void get_next(const String *T, int *nextArr){
    int i = 0;
    int j = -1; // -1 代表回退到串首
    nextArr[0] = -1;

    int len = T->len;
    while(i < len - 1){ // 需要进行 len - 1 此比较
        // 逻辑关系
        if(j == -1){
            // j = -1 时就将 j 置向串首，将 i 往后推一位
            // 并在对应的next数组中记录 0 （因为这种情况—— j == -1
            // 只会发生在第一次循环或遇到前后缀不相等的情况下）
            nextArr[++i] = ++j; // 这里的 ++j == 0
        }else if(T->text[i] == T->text[j]){
            // 当前子串前缀和后缀相等则在next数组中代表子串后一位
            // 的位置中记录相等的前后缀长度
            nextArr[++i] = ++j;
        }
        else{ // 遇到前后缀不同是 回溯 j
            j = nextArr[j];
        }

        // 简洁写法
        /*
        if(j != -1 && T->text[i] != T->text[j])
            j = nextArr[j];
        else
            nextArr[++i] = ++j;
        */
    }
}

/***************************************************
获取改进版next数组：
    将前缀中内容重复的位置在next数组中赋为同样的值
    减少不必要的匹配
***************************************************/
void get_nextval(const String *T, int *nextArr){
    int i = 0;
    int j = -1;
    nextArr[0] = -1;
    while(i < T->len - 1){
        if( j != -1 && T->text[i] != T->text[j])
            j = nextArr[j];
        else{
            // 若当前字符与已存在的对应前缀字符不同
            if(T->text[++i] != T->text[++j])
                nextArr[i] = j; // 则当前的 j 为nextArr在i位置的值
            else
                nextArr[i] = nextArr[j]; // 否则将前缀字符的nextArr值赋给
                                         // nextArr在i的位置
        }
    }
}

/***************************************************
KMP 算法实现
    返回子串T在朱串S中第pos个字符串之后的位置
    若不存在，则返回 -1
****************************************************/
int indexKMP(const String *S, const String *T, int pos = 0){
    int i = pos; // 将i置为开始匹配的位置，默认为0
    int j = 0;

    int nextArr[255];

#ifdef DEBUG
    get_next(T, nextArr); // 获取 nextArr 回溯数组
    // 打印 nextArr 数组
    for(int i = 0; i < T->len; i++)
        printf("%d ", nextArr[i]);
    printf("\n");
#endif

    get_nextval(T, nextArr); // 获取改进版 nextArr 回溯数组

#ifdef DEBUG
    // 打印改进版 nextArr 数组
    for(int i = 0; i < T->len; i++)
        printf("%d ", nextArr[i]);
    printf("\n");
#endif

    while(i < S->len && j < T->len){
        if(j == -1){
            // j 下标回溯至 -1 时需重置 j 为 0 并将 i 往后推一位
            ++i, ++j;
        }else if(S->text[i] == T->text[j]){
            // 单个字符匹配成功时 同时将 i j 增加 1
            ++i, ++j;
        }else{
            // 单个字符匹配失败时则回溯 j
            j = nextArr[j];
        }

        // 简洁写法
        /*
        if( j != -1 && S->text[i] != T->text[j])
            j = nextArr[j];
        else
            ++i, ++j;
        */
    }

    if(j >= T->len)
        return i - T->len;
    return -1;
}

int main(){
    char S[] = "ababaaababaaabababaaaba";
    String Sstr;
    Sstr.len = strlen(S);
    Sstr.text = S;

    char T[] = "ababaaaba";
    String Tstr;
    Tstr.len = strlen(T);
    Tstr.text = T;

    int a = indexKMP(&Sstr, &Tstr);
    printf("%d\n", a);

    a = indexKMP(&Sstr, &Tstr, 3);
    printf("%d\n", a);

    a = indexKMP(&Sstr, &Tstr, 9);
    printf("%d\n", a);

    return 0;
}
