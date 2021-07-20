//1. Initialization
//  a. shared_ptr<Dog> p(new Dog("Voltage"));
//  b. shared_ptr<Dog> p2 = p; //operator constructor
//  c. shared_ptr<Dog> p3 = std::make_shared<Dog>(); Dog dg("Voltage"); *p3 = dg;
//  d. shared_ptr<Dog> p4; Dog* dg = new Dog("Voltage") ; p4.reset(dg);
//2. Functions
//  p.use_count(); //the count of shared pointers using the instance
//  p.get();// return the original pointer
//3. cast
//  static_pointer_cast
//  dynamic_pointer_cast
//  const_pointer_cast

//Note:
//  Don't warp an original pointer with multiple shared pointers
//  No shared pointer in functions' parameters
//  Don't wrap this with shared pointer
//  No cycling shared pointers among classes
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
  Dog* p = new Dog("Gunner");
  delete p;
  p->bark();//p is a dangling pointer - undefined behavior
}// memory leak
//Delete too early will make a dangling pointer
//Forgot to delete will lead to memory leak


void foo1() {
  std::shared_ptr<Dog> p(new Dog("Gunner"));//Count = 1
  std::cout<<"The pointer count is "<<p.use_count()<<std::endl;
  {
    std::shared_ptr<Dog> p2 = p; //Count = 2  
    p2->bark();
    std::cout<<"The pointer count is "<<p2.use_count()<<std::endl;
  }
  //Count = 1;
  std::cout<<"The pointer count is "<<p.use_count()<<std::endl;
}//Count = 0, dog will be destroyed

//*** smart pointer will do the tedious work to manage the life cycle of a pointer ***/
int main() {
  foo1();
  //An object should be assigned to a smart pointer as soon as it is crated.
  //Raw pointer should not be used.
  Dog* d = new Dog("Tank");
  std::shared_ptr<Dog> p(d); //p.use_count ==1
  //std::shared_ptr<Dog> p2(d);//p2.use_count ==1 
  //***In this way, after run out of the function d will be destructed twice, it could result problems
  
  std::shared_ptr<Dog> p3;
  //***It's not ok because, dog is created in stack, it will be desctructed after the function
  //But meanwhile, the shared pointer will destruct it again
  //Dog dog("Cui");
  //p3.reset<Dog>(&dog);
  Dog* dog = new Dog("Voltage");
  p3.reset<Dog>(dog);

  std::shared_ptr<Dog> cuiDog= std::make_shared<Dog>("Cui");//Preferred cause safer and faster
  (*cuiDog).bark();
  //std::shared_ptr pd(new Dog("")); 1. create a Dog 2. createpd. more cost, besides, if 2 step failed will lead to memory leak
  return 0;
}

