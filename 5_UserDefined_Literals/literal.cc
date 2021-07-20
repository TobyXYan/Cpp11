#include "literal.h"

Dog::Dog(const char* name) {
  strcpy(m_name, name);
}

void Dog::Call() {
  std::cout<<"This is Dog::Call()"<<std::endl;
  //std::cout<<m_name_jp<<std::endl; //variable is not allowed
  std::cout<<"m_name"_jp<<std::endl;
}
