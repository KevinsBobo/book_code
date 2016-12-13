#include <iostream>
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

        vector<vector<int> > rec(row, vector<int>(col, 0));

        printf("Input your rec:\n");
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

int maxRecFromBottom(const int height[], const int len){
    if(height == NULL || len == 0)
        return 0;

    int maxArea = 0;
    int j, k;
    stack<int> rec;

    for(int i = 0; i < len; i++){
        while(!rec.empty() && height[i] <= height[rec.top()]){
            j = rec.top();
            rec.pop();
            k = rec.empty() ? -1 : rec.top();

            maxArea = max((i - k - 1) * height[j], maxArea);
        }
        rec.push(i);
    }

    while(!rec.empty()){
        j = rec.top();
        rec.pop();
        k = rec.empty() ? -1 : rec.top();

        maxArea = max((len - k - 1) * height[j], maxArea);
    }

    return maxArea;
}
