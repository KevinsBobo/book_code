/*
 * 寻找最大子矩阵
 * （在这里使用vector仅仅是为了练习）
 *
 * 1. 将矩阵从上到下依次压成一个用数值代表高度的的数组
 *    （把每个数值元素想象成对应高度的矩形柱子）
 * 2. 在每次得到的数组中寻找最大子矩阵，然后得到矩阵的最大子矩阵
 * 3. 遍历数组，对下标进行压栈、弹栈并求最大子矩阵
 *    3.1 遍历时，栈为空或当前柱子比前面（栈顶元素对应的柱子）的高时
 *        将当前柱子的下标压栈
 *    3.2 遇到当前柱子比前面的低或相等时将栈顶元素弹栈，直到遇到比当前
 *        柱子高的柱子或栈为空时再将当前柱子对应的下标压栈
 *    3.3 在弹栈的过程中需要求出弹出元素对应的柱子向左向右所能扩展的最大面积
 *        公式为：(i - k + 1) * height[j]
 *        i 为当前柱子的下标，k 为弹出栈顶元素后的栈顶元素（下标），当弹出
 *        栈顶元素后栈为空的情况下 k 记为 -1，j 为弹出的栈顶元素（下标）
 *    3.4 当遍历完最后一个元素后则认为最后一个元素后面的元素一定是最小的，
 *        于是将栈中元素依次弹出，并进行面积运算
 * */
// #include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int maxRecSize(const vector<vector<int> > &rec);
int maxRecFromBottom(const int height[], const int len);

int main(){
#if 0
    vector<vector<int> > rec = {
        {0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1}
    };
#endif
    int row = 0;
    int col = 0;
    int temp;

    printf("Input row: ");
    while(scanf("%d", &row) != EOF){
        printf("Input col: ");
        scanf("%d", &col);

        // 生成矩阵
        vector<vector<int> > rec(row, vector<int>(col, 0));

        printf("Input your rec:\n");
        // 填充矩阵
        for(int i = 0; i < row; i++){
            // rec.push_back(vector<int>(col, 0));

            for(int j = 0; j < col; j++){
                scanf("%d",&temp);
                rec[i][j] = temp;
            }
        }

        printf("The max rec size is: %d\n", maxRecSize(rec));
        printf("Input row: ");
    }


    return 0;
}

// 将矩阵从上到下依次压成用数值代表高度的数组
// 然后对当前数组求最大子矩阵
int maxRecSize(const vector<vector<int> > &rec){
    if(rec.empty() || rec.size() == 0)
        return 0;

    int maxArea = 0;
    int height[rec[0].size()] = {0};

    for(int i = 0; i < rec.size(); i++){
        for(int j = 0; j < rec[0].size(); j++){
            height[j] = rec[i][j] == 0 ? 0 : height[j] + 1;
        }
        maxArea = max(maxRecFromBottom(height, rec[0].size()), maxArea);
    }

    return maxArea;
}

// 对数组求最大子矩阵
int maxRecFromBottom(const int height[], const int len){
    if(height == NULL || len == 0)
        return 0;

    int maxArea = 0;
    int j, k;
    stack<int> rec;

    // 当栈为空或当前元素对应的柱子高于栈顶元素对应的柱子时
    // 则直接将当前元素的下标压栈
    // 否则进行弹栈操作，并求出弹出元素向左向右的最大扩展，直到
    // 遇到栈顶元素对应的柱子高于当前柱子或栈为空时停止弹栈操作
    // 并将当前元素的下标压栈
    for(int i = 0; i < len; i++){
        while(!rec.empty() && height[i] <= height[rec.top()]){
            j = rec.top();
            rec.pop();
            k = rec.empty() ? -1 : rec.top();

            maxArea = max((i - k - 1) * height[j], maxArea);
        }
        rec.push(i);
    }

    // 遍历完最后一个元素后直接进行弹栈和求向左向右扩展的操作
    while(!rec.empty()){
        j = rec.top();
        rec.pop();
        k = rec.empty() ? -1 : rec.top();

        maxArea = max((len - k - 1) * height[j], maxArea);
    }

    return maxArea;
}
