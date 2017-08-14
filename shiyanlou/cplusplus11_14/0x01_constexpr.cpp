#include <stdio.h>
#define LEN 10

constexpr int len_foo(int i){
  int a = 3 + i;
  return a;
}

int main(){
  char arr_1[10];
  char arr_2[LEN];
  int len = 5;
  char arr_3[len + 5];
  const int len_2 = 10;
  char arr_4[len_2 + 5];
  char arr_5[len_foo(0) + 2] = {'a', 'b', 'c', 'd' , '\0'};

  printf("%d %d %d %s\n", LEN, len, len_2, arr_5);
  return 0;
}
