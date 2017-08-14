#include <iostream>

int arr[3] = {1, 2 , 3}; // 初始化列表

class Foo {
  private:
    int value;
  public:
    Foo(int){}
};

class Magic {
  public:
    Magic(std::initializer_list<int> list){}
};

void func(std::initializer_list<int> list){
  return;
}

struct A {
  int a;
  float b;
};

struct B {
  B(int _a, float _b): a(_a), b(_b) {}

private:
  int a;
  float b;
};

int main(){
  Foo foo(1);
  Magic magic = {1, 2, 3, 4, 5};

  func({1, 2, 3});

  A a {1, 1.1f};
  B b {2, 2.2f};

  return 0;
}
