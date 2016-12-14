/*
 * 最大值减去最小值小于或等于num的字数组数量(子数组可以是只包含一个元素的数组)
 * */
#include <cstdio>
#include <deque>

using namespace std;

int getNum(const int arr[], const int len, const int num){
    if(arr == NULL || len <= 0)
        return 0;

    int res = 0;
    int i = 0, j = 0;
    deque<int> minNum, maxNum;

    for( ; i < len; i++){
        for( ; j < len; j++){
            // 维护保存最小值的双端队列
            while(!minNum.empty() && arr[j] <= arr[minNum.back()])
                minNum.pop_back();
            minNum.push_back(j);

            // 维护保存最大值的双端队列
            while(!maxNum.empty() && arr[j] >= arr[maxNum.back()])
                maxNum.pop_back();
            maxNum.push_back(j);

            if(arr[maxNum.front()] - arr[minNum.front()] > num)
                break;
        }

        if(!minNum.empty() && minNum.front() == i)
            minNum.pop_front();
        if(!maxNum.empty() && maxNum.front() == i)
            maxNum.pop_front();

        res += j - i;
    }

    return res;
}

int main(){
    int len;
    int arr[1000];
    int num;
    printf("Input arr len: ");
    while(scanf("%d", &len) != EOF){
        printf("Input arr content: ");
        for(int i = 0; i < len; i++)
            scanf("%d", &arr[i]);

        printf("Input the num: ");
        scanf("%d", &num);

        printf("The max children num is: %d\n", getNum(arr, len, num));

        printf("Input arr len: ");
    }
    return 0;
}
