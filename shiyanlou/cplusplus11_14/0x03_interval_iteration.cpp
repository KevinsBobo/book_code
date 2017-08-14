#include <iostream>
#include <vector>

int main(){
  // 区间迭代
  int array[] = {1, 2, 3, 4, 5};
  for(auto &x : array){
    std::cout << x << std::endl;
  }

  std::vector<int> arr(5, 100);

  for(std::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i){
    std::cout << *i << std:: endl;
  }

  // & 启用了引用，如果没有则是只读的，不能修改
  for(auto &i : arr){
    std::cout << i << std::endl;
  }

  return 0;
}
