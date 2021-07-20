//Topic: User defined literals
//Literals are constants
//C++ has 4 kinds of literals:
//  1. integer         45     unsigned long long
//  2. floating point  4.5    long double
//  3. character       'z'    char
//  4. string          "Dog"  const char*

//literal operator: int operator ""cm(unsigned long long length)
//pattern:  * operator ""xxx(*)

//Making some simple return function as constexpr can force the function to be done in the compilation time
//It will save cost in runtime
//
#include <iostream>
#include <cstring>
#include "common.h"
#include "literal.h"

constexpr unsigned long long operator "" _cm(unsigned long long length) {
  //std::cout<<"The length is "<<length<<" cm.\n";
  return 10*length;
}

constexpr unsigned long long operator "" _m(unsigned long long length) {
  //std::cout<<"The length is "<<length<<" m."<<std::endl;
  return 1000*length;
}

char* operator "" _toby(const char* str, size_t n) {//****** size_t must to be there
  char* ret = new char[256];
  strcpy(ret,str);
  strcat(ret," Toby");
  return ret;
}

char* operator "" _t(char ch) {
  char* ret = new char[256];
  ret[0] = ch;
  strcat(ret," T");
  return ret;
}

constexpr long double operator "" _Add2(long double val) {
  //std::cout<<"The original is "<<val<<" .\n";
  return (val+2);
}

int main() {
  std::cout<<"The length is "<<1_cm<<" mm.\n";
  std::cout<<"The length is "<<8_m<<" ,,.\n";
  std::cout<<"Excellent"_toby<<std::endl;
  std::cout<<'C'_t<<std::endl;
  std::cout<<"The double value right now is "<<183.68_Add2<<std::endl;

  Dog dog("Lucky");
  dog.Call();

  std::cout<<"Hi, this is "<<"Lucky"_jp<<std::endl;
  
  return 0;
}

