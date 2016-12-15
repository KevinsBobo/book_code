#include <cstdio>
// 简单的排序函数
void selectionSort(int arr[],int len){
    for(int i = 0; i < len; i++){
        int k = i;
        for(int j = i; j < len; j++){
            if(arr[j] < arr[k])
                k = j;
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

void insertSort(int arr[], int len){
    for(int i = 1; i < len; i++){
        int temp = arr[i], j = i;
        while(j > 0 && arr[j - 1] > temp)
            arr[j] = arr[j-- - 1];
        arr[j] = temp;
    }
}

int main(){
    int arr[8] = {2, 4, 6, 8, 57, 4, 6, 2};
    for(int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // selectionSort(arr, 8);
    insertSort(arr, 8);

    for(int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
