#include <iostream>
#include <vector>

/***9. override  (for virtrual function) ***/
//To avoid inadvertently create new function in derived classes.
/*
class dog {
  public:
    virtual void A(int);
    virtual void B() const;
};

class yellowDog:public dog{
  public:
    //New functions introduced cause the functions are different with those in its base class in some ways
    virtual void A(float);//Created a new function
    virtual void B();//Created a new function
};

class balckDog:public dog{
  public:
    virtual void A(float) override; //Error: no function to override
    virtual void B() override;      //Error: no function to override
    void C() override;              //Error: no function to override
}

//Advantages
//  1. Avoid inadvertently create new function in derived classes
//  2. When base class change the function, make sure the compile will report error if foggot to 
//  modify child classes' functions accordingly
*/


/***10. final (for virtual function and for class)***/
/*  
// no class can be derived from dog
  class dog final {
  };

  class cat {
    //no class can override bark()
    virtual void bark() final;
  };
//Note: It's similar sealed in C#
*/


/***11. Compiler Generated Default Constructor ***/
/*
class dog {
  public:
    dog(int age){
      std::cout<<"This is a dog of age of "<<age<<std::endl;
    }
};

class cat {
  public:
    cat(int age){
      std::cout<<"This is a cat of age of "<<age<<std::endl;
    }
    cat() = default;
};

int main() {
  //dog d1; //Error: Compiler will not generate the defult constructor
  cat c1; //Force compiler to generate the default constructor
  return 0;
}
//Make it more handy to construct an instance
*/

/***12. delete ***/
/*class dog {
  public:
    dog(int age) {}
};

//C++ 11
class cat {
  public:
    cat(int age) {}
    cat(double ) = delete;
    cat& operator = (const cat& ) = delete;
};

int main() {
  dog a(2);
  dog b(3.0); // 3.0 is converted from double to int
  a = b;      // Compiler generated assignment operator

  cat c(2);
  //cat d(3.0);
  //c = d;
  return 0;
}
//Note:
//  1.delete means the function can't be used
//  2.It's helpful for some functions, of which the input paramertes can be converted automatically
*/

/***13. constexpr ***/
/*
int A() {return 3;}

//C++ 11
constexpr int A1(){//Forces the computation to happen at "compile time".
  return 3;
}

//Write faster program with constexpr
//When the input parameter of the function is always a constant
constexpr int cubed(int x) {return x*x*x;}

int main() {
  int arr[6]; //OK
  int arr1[A() + 3];// Compile Error


  int arr2[A1() + 3]; //Create an array of size 6

  int y = cubed(1789);// computed at compile time
  std::cout<<"The cube of 1798 is "<<y<<std::endl;

  return 0;
}
//Note
//  1. It can make some code more intuitive
//  2. it can make program faster, as some computation are done during the compile
*/

/***14. new string literals ***/
/*
int main() {
  //C++ 03:
  char* a = "string";

  //C++ 11
  char* a1 = u8"string"; //to define an UTF-8 string.
  char16_t* b = u"string"; //to define an UTF-16 string.
  char32_t* c = U"string"; //to define an UTF-32 string.
  //char* d = R"string"; //to define a raw string.
  return 0;
}*/


/***15. lambda function ***/
template<typename func>
void filter(func f, std::vector<int> arr) {
  for(auto i:arr){
    if(f(i)){
      std::cout<<i<<' ';
    }
  }
  std::cout<<std::endl;
}

int main() {
  std::cout<<[](int x, int y){return x+y;}(3,4)<<std::endl;//Output: 7
  auto f = [](int x, int y){return x+y;};//*** like function pointer ***
  std::cout<<f(3,4)<<std::endl; //Output: 7


  std::vector<int> v = {1,2,3,4,5,6};
  filter([](int x){return (x>3);}, v); //Output: 4,5,6
  filter([](int x){return (x>2 && x<5);}, v);//Output: 3,4
  int y = 4;
  filter([&](int x){return (x>y);}, v);//Output: 5,6
  //Note: [&] tells compiler that we want variable capture
  //If we don't use & here, error will be reported during the compile
  //error: 'y' is not captured
  //It means if you want to use some variable in lambda, you have to use [&] or [=]
  //[&] captures variable by reference, [=] captures variable by value
  int mock = 8;
  auto byValue = [=](){std::cout<<mock<<std::endl;};
  auto byRef = [&](){std::cout<<mock<<std::endl;};
  --mock;
  byValue();//Output: 8
  byRef();//Output: 7
  return 0;
}
