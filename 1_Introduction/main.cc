#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <cassert>
//#include <assert>

/*** 1. Initializer List   ***/
/*
//Define your own initializer_list constructor
class boVector{
  std::vector<int> m_Vec;
  public:
  boVector(const std::initializer_list<int>& v){
    for(std::initializer_list<int>::iterator it = v.begin(); it != v.end(); ++it){
      m_Vec.push_back(*it);
    }

    std::cout<<"Here is the ctor with initializer_list:"<<std::endl;
    for(auto &e:m_Vec){
      std::cout<<e<<' ';
    }
    std::cout<<std::endl;
  }
};

int main() {

  //1. Initializer list
  //C++ 03 initializer list:
  int arr[4] = {2,3,4,5};
  for(auto &e:arr){
    std::cout<<e<<' ';
  }
  std::cout<<std::endl;

  //There is no initializer list in C++ 03 for classes like vector
  std::vector<int> v;
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  //C++ 11 extended the support for STL classes
  //All the relevant STL containers have been updated to accept initializer_list
  std::vector<int> v1 = {2,3,4,5};

  //Self defined class support initializer_list
  boVector bVec = {2,3,4,5};
  boVector bVec1{6,7,8,9};// effectively the same
  
  return 0;
}*/


/***2. Uniform Initialization ***/
/*
// 在c++11之前的版本，初始化是一个没有被统一的写法，有时候用小括号，有时候用大括号，有时候还用赋值号，
// c++11中就统一了初始化的形式——“{ }”，直接在对象名后面跟大括号，并在大括号中写入需要初始化的值，并用逗号隔开。
// In C++ 11, we can use {} to provide a uniform initialization. {} is the point
//C++ 03 
class dog {//Aggregate class or struct
  public:
    int age;
    std::string name;
};

class bird {
  private: 
    int m_Weight;
    std::string m_Name;
  public:
    bird(std::string name, int weight):m_Name(name), m_Weight(weight) {
      std::cout<<m_Name<<" is "<<m_Weight<<" kilogram"<<std::endl;
    }
};

int main() {
  //This is called  Aggregate Initialization
  dog d1 = {5, "Henry"};
  std::cout<<d1.name<<" is "<<d1.age<<" years old"<<std::endl;

  bird b1 = {"Voltage", 38};
  return 0;
}
//Uniform Initialization Search Order:
//  1. Initializer_list ctor
//  2. Regular ctor that takes the appropriate parameters
//  3. Aggregate initializer
//Conclusion: C++ specifies to use {} as uniform initialization
class Pig{
  public: 
    //1st choice with initializer_list
    Pig(std::initializer_list<int>& vec){
      age = *(vec.begin());
    }

    //2nd choice with input parameter
    Pig(int a){
      age = a;
    }

  public:
    //3rd choice with aggregate initialization when 1st and 2nd choice are not defined
    int age;
};*/



/***3. auto type ***/
//auto type save time to specify type
/*
std::vector<int> vec = {2,3,4,5};

int main() {
  //C++ 03
  for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    std::cout<<*it<<' ';
  std::cout<<std::endl;

  //C== 11 auto type
  //auto type can automatically infer the type
  for(auto it = vec.begin(); it != vec.end(); ++it)
    std::cout<<*it<<' ';
  std::cout<<std::endl;

  auto a = 6;   //a is an integer
  auto b = 9.6; //b is a double
  auto c = a;   //c is a integer

  return 0;
}*/


/***4. foreach ***/
/*std::vector<int> v = {5,6,7,8,9};

int main() {
  //C++ 03
  for(std::vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
    std::cout<<*it<<' ';
  std::cout<<std::endl;

  //C++ 11:
  for(int i:v)  // works on any class that has begin() and end()
    std::cout<<i<<' '; //readonly access
  std::cout<<std::endl;

  for(auto& i: v)
    --i; //we can change value of the element as reference operator & is used

  for(auto i:v)
    std::cout<<i<<' ';
  std::cout<<std::endl;

  return 0;
}*/


/***5. nullptr ***/
//To replace NULL in C++ 03
//NULL not only means null ptr but also equals to 0
/*void foo(int i){
  std::cout<<"foo_int"<<std::endl;
}

void foo(char* pc){
  std::cout<<"foo_char*"<<std::endl;
}

int main() {
  //foo(NULL); //Ambiguity

  //C++ 11
  foo(nullptr);
  
  return 0;
}*/


//***6. enum class ***/

/*
//C++ 03
enum apple {green_a, red_a};
enum orange {big_o, small_o};

//C++ 11
enum class ecapple{green, red};
enum class ecorange{big, small};

int main() {
  apple a = green_a;
  orange o = big_o;
  if(a == o)
    std::cout<<"green apple and big orange are the same\n";
  else
    std::cout<<"green apple and big orange are not the same\n";

  ecapple eca = ecapple::green;
  ecorange eco = ecorange::big;
  //compile fails because we haven't define == (ecapple, ecorange)
  if(eca == eco)
    std::cout<<"green apple and big orange are the same \n";
  else
    std::cout<<"gren apple and big orange are not the same\n";
 
  return 0;
}*/

/***7. static assert ***/
/*int main() {
  int* inPtr = nullptr;
  //run-time assert
  assert(inPtr != nullptr);

  //compile time assert (C++11)
  static_assert(sizeof(int) == 8, "The size is not right");

  return 0;
}*/


/***8. Delegating Constructor ***/
class dog {
  private:
    void saySth(){
      std::cout<<"Here is dog"<<std::endl;
    }
  public:
    dog(){}
    //In typical C++, two instances of dog will be created 
    //Here this is a *** java style code ***
    dog(int a){
      dog();
      saySth();
    }
};

//C++ 03
class bird {
  private:
  void init() {
    std::cout<<"Here is bird's init"<<std::endl;
  }
  void saySth(){
    std::cout<<"Here is a bird"<<std::endl;
  }

  public:
  bird(){init();}
  bird(int a) {init(); saySth(); }
};
// Cons:
//  1. Cumbersome code
//  2. init() could be invoked by other functions


//C++ 11:
class cat {
  public:
    //C++ 11 - Allow in-class data member initialization
    int age = 40;
  public:
    cat(){std::cout<<"This is cat ctor"<<std::endl;}
    cat(std::string name):cat(){
      std::cout<<"My name is "<<name<<std::endl;
      std::cout<<name<<" will die at age of "<<age<<std::endl;
    }
};
//limitation: cat() has to be called first

int main(){
  cat sbCat("VoltageSB");
  return 0;
}
