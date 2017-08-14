#include <iostream>

template<typename R, typename T, typename U>
R add(T x, U y){
  return x + y;
}

// C++ 11
template<typename T, typename U>
auto sub(T x, U y) -> decltype(x-y){
  return x + y;
}

// C++ 14
template<typename T, typename U>
auto sum(T x, U y){
  return x + y;
}

int main(){
  auto i = 5;

  int arr[10] = {0};
  auto auto_arr = arr;
  // auto auto_arr2[10] = arr; // 不能用来推导数组
   
  auto x = 1;
  auto y = 2;
  decltype(x+y) z;

  return 0;
}
