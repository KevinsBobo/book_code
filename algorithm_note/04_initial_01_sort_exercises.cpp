/*
 * 排序练习题：对学生信息以学生成绩进行排序，
 *              要求输出总排名，和以考场为单位的排名
 *
 * 我的方法：
 *      将所有学生信息获取后进行一次排序，
 *      然后遍历一次学生信息数组，通过三个辅助数组算出
 *      学生在其考场的排名；
 *      每个辅助数组的大小是总考场数，分别保存遍历过程中
 *      当前遍历过的每个考场最后一名学生的成绩、考场排名
 *      和已排名学生的数量
 *
 * 书中的答案：
 *      在一个考场学生信息输入完成后对当前考场中
 *      所有的学生信息进行排序，并将考场排名保存在学生
 *      信息中；
 *      然后在所有学生信息录完之后在将所有的数据进行一次
 *      排序
 *
 * 方法对比：
 *      由于所有的排序使用的是C++的sort函数，这个函数是跟
 *      据不同情况选择不同的排序算法，因此无法判定排序的时
 *      间复杂度和产生的额外空间复杂度。
 *
 *      在时间复杂度上我的方法在排序操作上最少比书中的方法
 *      快一倍；因为我的方法中只进行了一次总体排序，和整体
 *      遍历，但书中的方法可以看作进行了两次整体排序和两次
 *      整体遍历（这里将所有的考场排序和遍历视为一次整体操
 *      作）
 *
 *      在空间复杂度上，在不考虑每次排序产生的额外空间复杂
 *      度的情况下，我的方法产生的额外空间复杂度可以记为：
 *      O(M)  M为考场的数量；
 *
 *      因此我的方法可以算作用时间换取空间（但是在sort函数
 *      选择的排序算法产生了大于等于O(N)的额外空间复杂度，
 *      我的方法就由绝对的优势了，因为我方法中的O(M)比O(N)
 *      要小得多，要小N * sizeof(id)）
 *
 * 运行对比：
 *      由于无法确定两种方法中sort函数选择的排序策略是否相
 *      同，所以两种方案的执行相率不能仅凭上面的时间复杂度
 *      来判定，所以我使用了8917个数据（91个考场）对两种方
 *      分别进行了测试，采用CPU在执行过程中的累计的时钟滴答
 *      累计数进行计时（计时过程没有输出排序后的学生信息，
 *      以减减小无用计时对数据结果的影响）。13次运行结果：
 *
 *      书中的方法：            我的方法：
 *          10430               8904
 *          5708                13651
 *          5511                4153
 *          20544 (max)         4947
 *          5696                4265
 *          13936               4649
 *          7036                6154
 *          5746                13999 (max)
 *          11322               4280
 *          20210               4230  (min)
 *          5439  (min)         4747
 *          5742                4335
 *          13091               6030
 *      平均值：
 *          10031               6510
 *      去掉一个最大值和一个最小值后的平均值：
 *          104428              5759
 *      （数值为执行过程中的clock滴答累计数）
 * 结果已经很明显了，和上面的推测基本是一致的
 * */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <sys/time.h>

// #define SHOW_TIME // 打印运行中产生的始终滴答累计数
// #define NOT_PRINT // 不打印排序后的结果
// #define USE_BOOK  // 使用书中的方法

using namespace std;

// 学生信息结构
typedef struct Student{
    char id[15];    // 准考证号
    int score;      // 成绩
    int localtion;   // 考场
    int local_rank; // 考场内排名
} stu;

// 自定义比较函数
bool cmp(stu a, stu b){
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

// 我的方法
void stuSort(stu arr[], int num, int localtion_num){
    sort(arr, arr + num, cmp);

    // 保存每个考场遍历过的最后一名学生的排名
    int theSame[num] = {0};
    // 保存每个考场遍历过的学生数量
    int localRank[num] = {0};
    // 保存每个考场遍历过的最后一名学生的成绩
    int localScore[num] = {0};
    // 辅助变量，用于每个保存考场对应的下标
    int localNum;

    for(int i = 0; i < num; i++){
        // 更新考场下标
        localNum = arr[i].localtion - 1;

        // 如果当前学生成绩与对应考场遍历过的最后一名学生的
        // 成绩不同，则更新保存的排名为该考场遍历过的学生数
        if(arr[i].score != localScore[localNum])
            theSame[localNum] = localRank[localNum];
        // 更新该学生的考场排名
        arr[i].local_rank = theSame[localNum] + 1;

        // 更新该考场中应保存的成绩
        localScore[localNum] = arr[i].score;
        // 更新该考场遍历过的学生数量
        localRank[localNum]++;
    }
}

int main(){
    // 重定向标准输入输出到文件
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

#ifdef SHOW_TIME // 计时开始
    long seconds = clock();
    /*
    struct timeval tv;
    gettimeofday(&tv, NULL);
    seconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    */
    printf("begClock: %ld\n", seconds);
#endif

    stu allstu[10000];
    int localtion_num; // 考场数量
    int localtion_stu; // 考场学生数
    int theStu = 0;    // 保存遍历过的学生数量

    // 输入数据
    while(scanf("%d", &localtion_num) != EOF){
        for(int i = 0; i < localtion_num; i++){
            scanf("%d", &localtion_stu);

            for(int j = 0; j < localtion_stu; j++){
                scanf("%s %d", allstu[theStu].id, &allstu[theStu].score);
                allstu[theStu].localtion = i + 1;
                theStu++;
            }

#ifdef USE_BOOK // 书中的方法
            // 对当前考场进行排序
            sort(allstu + theStu - localtion_stu, allstu + theStu, cmp);
            // 将当前考场第一名的考场排名设置为1
            allstu[theStu - localtion_stu].local_rank = 1;

            // 遍历考场中第一名后面的学生，并设置其考场排名
            for(int m = theStu - localtion_stu + 1; m < theStu; m++){
                // 如果当前学生成绩和前面学生的相同，则考场排名和前面的相同
                // 否则考场排名为当前考场已遍历过的学生数
                if(allstu[m].score == allstu[m - 1].score)
                    allstu[m].local_rank = allstu[m - 1].local_rank;
                else
                    allstu[m].local_rank = m + 1 - (theStu - localtion_stu);
            }
        }
        // 在执行完所有的数据输入后对整个数据再进行一次排序
        sort(allstu, allstu + theStu, cmp);
#else
        }
        // 我的方法，调用排序函数
        stuSort(allstu, theStu, localtion_num);
#endif

#ifndef NOT_PRINT
        // 打印排序后的数据及每个学生的排名

        printf("%d\n", theStu);

        // 保存遍历过的最后一个学生的排名
        int r = 1;
        for(int i = 0; i < theStu; i++){
            // 如果当前学生的成绩和前面学生的成绩不同则将更新保存的排名
            if(i > 0 && allstu[i].score != allstu[i-1].score)
                r = i + 1;
            // 打印
            printf("%4s %3d %3d %2d %3d\n",
                    allstu[i].id, allstu[i].score, r, allstu[i].localtion,
                    allstu[i].local_rank);
        }
#endif
    }

#ifdef SHOW_TIME // 计时结束，并打印始终滴答数
    long preSeconds = seconds;
    seconds = clock();
    printf("endClock: %ld\nuseClock: %ld\n", seconds, seconds - preSeconds);
#endif
    return 0;
}
