//Topic: Compiler Generated Functions


/*
 * C++ 03:
 *  1. default ctor (generated only if no ctor is declared by user)
 *  2. copy ctor (generated only if 5,6 not declared by user)
 *  3. copy assignment operator (generated only if 5, 6 not declared by user)
 *  4. destructor
 */

/*
 * C++ 11:
 *  5. move ctor (generated only if 2,3,4,6 not declared by user)
 *  6. move assignment operator(generated only 2,3,4,5 not declared by user)
 */


class Dog{};//generate 1,2,3,4,5,6

class Cat { //generate 3,4
  public:
    Cat(const Cat& cat){}// copy ctor

};

//Only be moved and can't be copied
class Duck{//generate 4
  public:
    Duck(Duck&& duck){}
};

class Frog{//generate 4
  public:
    Frog(Frog&& frog, int = 0){}//move ctor
};


class Fish{// generate 1,2,3
  public:
    ~Fish(){}
};

class Cow{//generate 1,2,4 => delete also a kind of declaration
  public:
    Cow operator =(const Cow& cow)=delete;
};




