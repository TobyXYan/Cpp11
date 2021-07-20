//Ways to delete original pointer in the shared_ptr
//  1. p1 = p2;
//  2. p1 = nullptr;
//  3. p1.reset();
//
//Custom Deleter
//  std::shared_ptr<Dog> p(new Dog(Voltage), [](Dog* p){delete[] p;});
//
//Note:
//  Avoid to use raw pointer once using smart pointer
#include <iostream>
#include <string>
#include <memory>

class Dog {
  private:
    std::string m_name;
  public:
    Dog(std::string name){
      std::cout<<"Dog is created: "<<name<<std::endl;
      m_name = name;
    }
    Dog() {
      std::cout<<"Nameless dog created."<<std::endl;
      m_name = "nameless";
    }
    ~Dog() {
      std::cout<<"dog is destroyed: "<<m_name<<std::endl;
    }
    void bark() {
      std::cout<<"Dog "<<m_name<<" rules!"<<std::endl;
    }
};

void foo() {
  std::shared_ptr<Dog> p1 = std::make_shared<Dog>("Gunner");//using default deleter: operator delete
  std::shared_ptr<Dog> pDelete(new Dog("Delete"),[](Dog* p){std::cout<<"Custom deleting";delete p;});
  std::shared_ptr<Dog> p2 = std::make_shared<Dog>("Tank");

  //std::shared_ptr<Dog> p3(new Dog[3]);//p3 points to Dog[0], then dog[1] and dog[2] memory leak
  std::shared_ptr<Dog> p4(new Dog[3], [](Dog* p){delete[] p;});

  p1 = p2;//Gunner is deleted
  p1 = nullptr;//Gunner is deleted
  p1.reset();//Gunner is deleted
}

int main() {
  foo();
  return 0;
}
