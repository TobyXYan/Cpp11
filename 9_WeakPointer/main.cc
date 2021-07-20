//TOPIC: Weak Pointer
//1. Unlike shared_ptr, weak_ptr only access to the object  but has no ownership of that object
//2. Weak pointer  - similar to have a raw pointer according to 1.  When and how object will be deleted doesn't intrest weak pointer. 
//3. Weak pointer - is protected from delete
//4. Weak pointer will be emepty if the object is deleted.
//5. Can't use weak pointer without lock(), lock() will create a shared_ptr for the weak pointer
//  It helps to 1. check the object is still alive  2. Makes sure the object will not be deleted while acessing this object
//  If lock found the object is invalid, it will trhow an exception
//6. weakPtr.expired() to determine if the object is still valid
//7. weakPtr.use_count() to determine how many pointers are pointing to the object
//
#include <iostream>
#include <memory>
class Dog {
  private:
    //std::shared_ptr<Dog> m_pFriend;//! Cyclic reference
    //Solution: Weak point only wants to access but don't have ownership of that object
    std::weak_ptr<Dog> m_pFriend;
  public:
    std::string m_name;
    Dog(const char* name):m_name(name){}
    void bark() {std::cout<<"Dog "<<m_name<<" rules!"<<std::endl;}
    ~Dog(){std::cout<<"dog is destroyed: "<<m_name<<std::endl;}
    void makeFriend(std::shared_ptr<Dog> f){m_pFriend = f;}
    void showFriend() {
      if(!m_pFriend.expired())//making sure the objects is till alive
        std::cout<<"My friend is: "<<m_pFriend.lock()->m_name<<std::endl;
      std::cout<<"He is owned by "<<m_pFriend.use_count()<<" pointers."<<std::endl;
    }
};

int main() {
  std::shared_ptr<Dog> pD(new Dog("Gunner"));
  std::shared_ptr<Dog> pD2(new Dog("Smokey"));
  pD->makeFriend(pD2);
  pD2->makeFriend(pD);
  pD->showFriend();
  return 0;
}

