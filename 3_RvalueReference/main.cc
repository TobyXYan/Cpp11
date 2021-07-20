//1. Moving semantic
//2. Perfect Forwarding


//Note
//1. The most useful place for rvalue reference is overloading copy
//ctor and copy assignment operator, to achieve move semantic.  move ctor, move assignment ctor
//
//2. Move semantics is implemented for all STL containers, which mean:
//  a. Move to C++ 11, your code will be faster without changing a thing
//  b. Passing-by-value can be used for STL containers
//      std::vector<int> foo() {int a; return a;}
//
//3. Pass by reference if you use arg to carry data back from the function
//
//4*. The main purpose of Move Ctor and Move Assignment operator is conveniently avoid costly and unnecessary deep copying
//  a. They are particularly powerful where passing by reference and passing by value are both used.
//  b. They give you finer control of which part of your object to be moved.


#include <iostream>
#include <string>
#include <utility>
#include <vector>

//overload only allows for int& and int&&, as int will make it ambiguous for int a between printInt(int) and printInt(int&)
//and for constant between int and int&& 

/*void printInt(int& i) {std::cout<<"lvalue reference: "<<i<<std::endl;}
void printInt(int&& i) {std::cout<<"rvalue reference: "<<i<<std::endl;}
//void printInt(int i){}

int main() {
  int a = 5; //a is lvalue
  int& b = a; //b is lvalue reference
  //int &&c //c is rvalue reference

  printInt(a);
  printInt(6);
  return 0;
}*/

class boVector {
  private:
    int size;
    double* arr;
  public:
    boVector() {
      size = 5;
      arr = new double[size];
      for(int i = 0; i<size; ++i)
        arr[i] = i;
    }
    //copy ctor
    boVector(const boVector& rhs) {
      size = rhs.size;
      arr = new double[size];
      for(int i = 0; i<size; ++i) {
        arr[i] = rhs.arr[i];
      }
    }

    //move constructor
    boVector(boVector&& rhs) {
      size = rhs.size;
      arr = rhs.arr;
      rhs.arr = nullptr;
    }
    ~boVector() {delete arr;}
};

void foo(boVector v){}
void foo_by_ref(boVector& v){}

  std::vector<int> getVec() {
    return {1,2,3,4,5};
  }

int main() {
  boVector reusable;// = createBoVector();

  foo_by_ref(reusable); //no ctor
  foo(reusable); //Call copy ctor
  foo(std::move(reusable)); //Call move ctor
  // C++ 03 will use copy ctor to get a copy of reusable 
  // C++ 11 will use move ctor to get it

  for(auto i:getVec())
    std::cout<<i<<' ';
  std::cout<<std::endl;
  return 0;
}
