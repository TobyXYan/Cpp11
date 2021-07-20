#include <iostream>
#include <string>

void RunCode(int&& m) {
  std::cout<<"rvalue ref"<<std::endl;
}

void RunCode(int& m) {
  std::cout<<"lvalue ref"<<std::endl;
}

void RunCode(const int&& m) {
  std::cout<<"const rvalue ref"<<std::endl;
}

void RunCode(const int& m) {
  std::cout<<"const lvalue ref"<<std::endl;
}

void myforward(int&& i) {
  std::cout<<"myforward2(int&& i): "<<i<<std::endl;
  RunCode(std::forward<int&&>(i));
}

void myforward(int& i) {
  std::cout<<"myforward1(int& i): "<<i<<std::endl;
  //RunCode(std::forward<int>(i)); //*** it will leads to RunCode(int&&), as the type we put is int
  RunCode(std::forward<int&>(i));
}

void myforward(const int& i) {
  std::cout<<"myforward3(int& i): "<<i<<std::endl;
  RunCode(std::forward<const int&>(i));
}

template<typename T>
void perfectforward(T&& i) {
  std::cout<<"perfectforward(T&& i)"<<std::endl;
  RunCode(std::forward<T>(i));
}

int main() {
  int a = 0;
  int b = 0;
  const int c = 0;
  const int d = 0;
  myforward(a);
  myforward(std::move(b));
  myforward(c);             
  //myforward(std::move(d));  //error no matching function
  perfectforward(a);
  perfectforward(std::move(b));
  perfectforward(c);
  perfectforward(std::move(d));
  return 0;
}
