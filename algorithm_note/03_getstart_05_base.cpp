#include <cstdio>

int main(){
    int a, b, d;
    while(scanf("%d %d %d", &a, &b, &d) != EOF){
        int sum = a + b;
        int ans[31], num = 0;
        do{
            ans[num++] = sum % d;
            sum /= d;
        }while(sum != 0);

        printf("%d base is: ", d);

        while(num > 0)
            printf("%d", ans[num-- - 1]);

        printf("\n");
    }
    return 0;
}
