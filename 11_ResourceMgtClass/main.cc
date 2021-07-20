//TOPIC: Resource Managing Class
//1. Like vector push_back is a shallow copy, for class object the pointer pointing to will not be deep copied.
//If the desctructor delete the resouce, the existed copies may fail to acess to that resource.
//2. emplace_back support in place constructor
//3. We can use smart pointer to manage the resouce
//4. If we defined destructor, we have to define move ctor explicitly, refer to course 6*

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Person {
  private:
    //std::string* m_pName;
    //4. shared_ptr solution
    //std::shared_ptr<std::string> m_pName;
    //5. unique_ptr solution, as the p is not needed afterwards
    std::unique_ptr<std::string> m_pName;
    int m_id;
  public:
    Person(std::string name, int id):m_pName(new std::string(name)),m_id(id) {}
    void printName() {
      std::cout<<"Just enter print name"<<std::endl;
      std::cout<<"The id is "<<m_id<<std::endl;
      std::cout<<*m_pName<<std::endl;
    }
    //4. 5. don't need the destructor
    //~Person() {std::cout<<"Person destructed"<<std::endl;  delete m_pName;  }
};

int main() {
  std::vector<Person> persons;

  //1. Segmentation fault when call printName, because push_back will trigger copy ctor, and that temporary object will
  //be destructed immediately. In that case, ~Person will delete m_pName. While the copy ctor just
  //conducted a shallow copy, hence the temporary object and copied object sharing the same content of m_pName
  //finally, it will leads to the error
  /*persons.push_back(Person("George",6));
  std::cout<<"Here"<<std::endl;
  persons.front().printName();
  std::cout<<"Goodbye"<<std::endl;*/

  //2. Segmenyayion fault when end of main, like before, person object is copied, but both of p and the copied one
  //in persons sharing the same string object they pointing to, hence when calling the destructor, the pointer will be
  //deleted twice, it will trigger the error
  /*Person p("George", 6);
  persons.push_back(p);
  persons.front().printName();
  std::cout<<"Goodbye"<<std::endl;*/

  //3. construct the object in place (in the space allocated to the vector)
  //persons.emplace_back("Toby",29);

  //4. use shared_ptr to solve the problem - using shared_ptr to manage the resource
  /*Person p("George", 6);
  persons.push_back(p);
  persons.front().printName();
  std::cout<<"Goodbye"<<std::endl;*/

  //5. use unique_ptr to solve the problem, more light-cost, and p will not be used after that
  Person p("George", 6);
  //It will trigger move ctor
  persons.push_back(std::move(p));
  persons.front().printName();
  std::cout<<"Goodbye"<<std::endl;
  //p.printName();//*** it will fail because, after the move ctor, it's set as empty
  return 0;
}

