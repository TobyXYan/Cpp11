#ifndef _LITERAL_H_
#define _LITERAL_H

#include "common.h"

class Dog{
  public:
    char m_name[256];
    Dog(const char* name);
    void Call();
};

#endif
