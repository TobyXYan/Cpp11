//Unique pointer: exclusive ownership, light weight smart pointer
//It's preferrable to use unique pointer if the pointer is not shared 

//Initialization
//  a. std::unique_ptr<Dog> p(new Dog(""));
//  b. std::unique_ptr<Dog> p2(std::move(p1));
//  c. std::unique_ptr<Dog> p3 = std::move(p2);
//  d. std::unique_ptr<Dog> func(); //as return value of a function
//  e. std::make_unique<Dog>("Voltage");
//
//Delete raw instance
//  1. p.reset()
//  2. p = nullptr
//  3. delete p;
//
//p.release(); //return the raw pointer, and set p as nullptr
//
//std::unique_ptr<Dog[]> dogs(new Dog[3]); // right way for array unique pointer
//
//unique_ptr can be used as input parameter


#include <iostream>
#include <memory>
#include <string>

class Bone {
};

class Dog {
  public:
    std::unique_ptr<Bone> m_pBone;//Prevents memory leak even constructor fails
    std::string m_name;
    void bark() {std::cout<<"Dog "<<m_name<<" rules!"<<std::endl;}
    Dog() {std::cout<<"Nameless dog created."<<std::endl; m_name = "nameless";}
    Dog(std::string name) {std::cout<<"Dog is created: "<<name<<std::endl; m_name = name;}
    ~Dog() {std::cout<<"dog is destroyed: "<<m_name<<std::endl;}
};

void test() {
  Dog* pD = new Dog("Gunner");
  //... Do sth.
  //If it returned before the end of the socpe
  //or some exceptions trowed here, it will leads to memory leak because pD is not well removed
  pD->bark();
  delete pD;
}

void f1(std::unique_ptr<Dog> p) {
  //in the end of the function, the unqie pointer and its original pointer will de destructed
  p->bark();
}

std::unique_ptr<Dog> getDog() {
  std::unique_ptr<Dog> p(new Dog("Cui"));
  return p;
}

void rightTest() {
  std::unique_ptr<Dog> pD(new Dog("Gunner"));
  pD->bark();
  Dog* p = pD.release();//release of unique pointer will give up its ownership of the raw pointer
  if(!pD)
    std::cout<<"pD is empty\n";
  pD.reset(new Dog("Smokey"));
  if(!pD)
    std::cout<<"Smokey is empty\n";
  else
    std::cout<<"Smokey is not empty\n";

  std::unique_ptr<Dog> p3(new Dog("Voltage"));
  pD->bark();
  pD = std::move(p3);
  //1. Smokey destoryed  2. p3 becomes empty  3. pD owns Voltage
  pD->bark();

  f1(std::move(pD));//pD is empty because it move owner to f1's parameter
  if(!pD)
    std::cout<<"pD is empty\n";

  pD = getDog();//*** function return is automatically using std::move
  //When certain criteria are met, an implementation is allowed to omit the copy/move 
  //construction of a class object [...] This elision of copy/move operations, called copy elision,
  

  std::unique_ptr<Dog[]> dogs(new Dog[3]);
  //No need to sepecify custom deleter like shared ptr, cause it will do this automatically once <Dog[]> used

}

int main() {
  //test();
  rightTest();
  return 0;
}
