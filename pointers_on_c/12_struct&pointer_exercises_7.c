/**************************
 *
 * 用链表建立一个快速索引表
 *
 * ************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

#define MAXLEN 20

// 以字母归类的单词表的结构体
typedef struct szWord{
    char word[MAXLEN];
    struct szWord *next;
} szWord;
typedef struct hdWord{
    szWord *next;
} hdWord;

// 以首字母归类的索引表结构体
typedef struct szIndex{
    char fWord;
    struct szIndex *next;
    hdWord wdHead;
} szIndex;
typedef struct hdIndex{
    szIndex *next;
} hdIndex;

// 操作模式
enum select {
    input = 1, check, find, clear, quit
};

// 自定义输入函数，要求输入单词要以字母开头
void myScanf(char *szBuff, char *fWord){
    printf("Please Input A Word: ");
    scanf("%s", szBuff);
    *fWord = szBuff[0];
    while(!isalpha(*fWord)){
        printf("Input not right, Input again:");
        scanf("%s", szBuff);
        *fWord = szBuff[0];
    }
}

// 插入单词表函数
void insertWord(hdWord *fWdHead, const char *szBuff){
    szWord *newWord = NULL;
    if(fWdHead->next == NULL){
        newWord = (szWord *)malloc(sizeof(szWord));
        strncpy(newWord->word, szBuff, MAXLEN);
        fWdHead->next = newWord;
        fWdHead->next->next = NULL;
        return;
    }
    int cmp = 0;
    szWord *temp = fWdHead->next;
    for(int i = 0; temp != NULL; i++){
        cmp = strcmp(szBuff, temp->word);
        if(cmp < 0 && i == 0){
            newWord = (szWord *)malloc(sizeof(szWord));
            strncpy(newWord->word, szBuff, MAXLEN);
            temp = fWdHead->next;
            fWdHead->next = newWord;
            newWord->next = temp;
            break;
        }else if(cmp == 0){
            printf("单词已存在！\n");
            break;
        }else if(temp->next != NULL && strcmp(temp->next->word, szBuff) <= 0){
            temp = temp->next;
        }else{
            newWord = (szWord *)malloc(sizeof(szWord));
            strncpy(newWord->word, szBuff, MAXLEN);
            temp = fWdHead->next->next;
            fWdHead->next->next = newWord;
            newWord->next = temp;
            break;
        }
    }
}

// 插入索引结点
szIndex *insertIdst(hdIndex *fIndex, szIndex *theIndex,const char fWord){
    szIndex *newIndex = NULL;
    szIndex *temp = NULL;
    newIndex = (szIndex *)malloc(sizeof(szIndex));
    
    newIndex->fWord = fWord;
    newIndex->wdHead.next = NULL;
    // 判断传入结点指针是否为空指针
    if(theIndex == NULL && fIndex->next == NULL){
        fIndex->next = newIndex;
        newIndex->next = NULL;
    }else if(theIndex == NULL){
        temp = fIndex->next;
        fIndex->next = newIndex;
        newIndex->next = temp;
    }else{
        // 将新节点插入
        temp = theIndex->next;
        theIndex->next = newIndex;
        newIndex->next = temp;
    }
    return newIndex;
}

// 插入索引表函数
void insert(hdIndex *fIndex){
    char szBuff[MAXLEN];
    char fWord;
    myScanf(szBuff, &fWord);

    if(fIndex->next == NULL){
        // 如果索引表为空则建立一个索引表，并将首字母插入
        fIndex->next = insertIdst(fIndex, NULL, fWord);
        insertWord(&fIndex->next->wdHead, szBuff);
    }else{
        // 寻找结点，找不到则建立一个结点
        szIndex *temp = fIndex->next;
        for(int i = 0; temp != NULL; i++){
            if(fWord < temp->fWord && i == 0){
                temp = insertIdst(fIndex, NULL, fWord);
                break;
            }else if(temp->fWord == fWord){
                break;
            }else if(temp->next != NULL && temp->next->fWord <= fWord)
                temp = temp->next;
            else{
                temp = insertIdst(fIndex, temp, fWord);
                break;
            }
        }
        insertWord(&(temp->wdHead), szBuff);
    }
}



// 打印所有单词
void checkAll(hdIndex fIndex){
    szIndex *theIndex = fIndex.next;
    if(theIndex == NULL){
        printf("索引表为空！\n");
        return;
    }
    szWord *tempWd = NULL;
    while(theIndex != NULL){
        tempWd = theIndex->wdHead.next;
        while(tempWd != NULL){
            printf("%s\n", tempWd->word);
            tempWd = tempWd->next;
        }
        theIndex = theIndex->next;
    }
}

// 寻找单个单词
void findOne(hdIndex fIndex){
    szIndex *theIndex = fIndex.next;
    if(theIndex == NULL){
        printf("索引表为空！\n");
        return;
    }
    char szBuff[MAXLEN];
    char fWord;
    myScanf(szBuff, &fWord);
    szWord *tempWd = NULL;
    while(theIndex != NULL){
        if(theIndex->fWord == fWord){
            tempWd = theIndex->wdHead.next;
            while(tempWd != NULL){
                if(strcmp(tempWd->word, szBuff) == 0){
                    printf("%s\n", tempWd->word);
                    return;
                }
                tempWd = tempWd->next;
            }
        }
        theIndex = theIndex->next;
    }
}

// 清空索引表
void clearAll(hdIndex *fIndex){
    if(fIndex->next == NULL)
        return;

    szIndex *idTemp = fIndex->next;
    szIndex *idTempA;
    szWord  *wdTemp = idTemp->wdHead.next;
    szWord  *wdTempA;

    while(idTemp!= NULL){
        idTempA = idTemp->next;
        while(wdTemp != NULL){
            wdTempA = wdTemp->next;
            free(wdTemp);
            fIndex->next->wdHead.next = wdTemp;
            wdTemp = wdTempA;
        }
        free(idTemp);
        idTemp = idTempA;
    }
    fIndex->next = NULL;
}

int main(){
    //freopen("./12_struct&pointer_exercises_7.in.test", "r", stdin);
    //freopen("./12_struct&pointer_exercises_7.out.test", "w", stdout);

    hdIndex myIndex = { NULL };
    enum select  userSet;
    int setTemp;

    char szPrint[][30] = {
        "(1) Insert a word",
        "(2) Print all word",
        "(3) Find a word",
        "(4) Clear all word",
        "(5) Quit",
        "Please Input Your Select:"
    };
    while(1){
        for(int i = 0; i < sizeof(szPrint) / sizeof(szPrint[0]); i++)
            printf("%s\n", szPrint[i]);
        
        scanf("%d", &setTemp);
        userSet = setTemp;
        switch(userSet){
            case input:
                insert(&myIndex); break;
            case check:
                checkAll(myIndex); break;
            case find:
                findOne(myIndex); break;
            case clear:
                clearAll(&myIndex); break;
            case quit:
                clearAll(&myIndex); exit(0); break;
            default:
                printf("Input Not Right!\n");
        }
    }
    
    return 0;
}
