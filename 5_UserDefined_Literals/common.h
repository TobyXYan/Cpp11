#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
#include <cstring>
#include <string>

//No name name space to acoid the error below
//  main.o: In function `operator"" _jp(char const*, unsigned long)':
//  /slowfs/dept5531s/tobyyan/p4/projects/CPP11/5_UserDefined_Literals/common.h:8: multiple definition of `operator"" _jp(char const*, unsigned long)'
//  literal.o:/slowfs/dept5531s/tobyyan/p4/projects/CPP11/5_UserDefined_Literals/common.h:8: first defined here
//  collect2: error: ld returned 1 exit status

//Serveral ways to solve this problem for global function
//1. empty namespace
//2. mark the function as inline
//3. mark the function as static

namespace{
std::string operator "" _jp(const char* str, size_t) {
  std::string name(str);
  name += " sun";
  return name;
}
}
#endif
