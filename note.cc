//https://www.youtube.com/playlist?list=PL5jc9xFGsL8FWtnZBeTqZBbniyw0uHyaH
/*** Introduction ***/

1. initializer_list
    Dog(initializer_list<int>){} //Dog d{1,2,3}; Dog g = {1,2,3};
2. uniform initialization  //an uniformed initialization way- {}. 1. initializer_list  2. regular ctor  3. Aggregate initializer
3. auto
4. foreach
5. nullptr
6. enum class
7. static_assert          //at compile time
8. delegating constructor //dog(int a):dog()
9. override               //make sure function declared in child class will not create new one  
10. final                 //*** final  forbid inheritance for function or class
11. default constructor   //cat()=default; cat(const cat&)=default; cat(cat&&)=default; cat& operator =(const cat&&) = default;
12. delete                //*** delete
13. constexpr             // constexpr ***, it works at compile time instead of runtime, it will save run time cost
                          // when use constexpr function, the input value should always be constant
14. string literals
15. lambda function       //[](paras){}, [=], [&]   capture variable by value and reference



/*** Move Semantic ***/
1. Passing-by-value can be used for STL containers
        std::vector<int> foo(){int i = 6; return i;}
The main purpose of Move Ctor and Move Assignment operator is conveniently avoid costly and unnecessary deep copying


/*** Perfect Forwarding ***/
1. FuncL(int&) FuncR(int&&) FuncC(const int&)
FuncL can accept lvalues only
FuncR can accept rvalues only
FuncC can accept both lvalues and rvalues

2. template<typename T>
   T&& //this is universal reference

3. The intention of perfect forwarding is keeping values as the type they were



/*** User Defined Literals ***/
Four kinds of input parameters literals: unsigned long long   long double  const char*  char
<return type> operator "" <literals>(<input params>) { ... }


/*** Shared Pointer ***/
Smart pointers will do tedious work to manage the lif cycle of a pointer, and help to safely deal with resource with low cost
Initialization:
   1. shared_ptr<Dog> p(new Dog("V"));
   2. shared_ptr<Dog> p1 = p; //ref count ++
   3. shared_ptr<Dog> p = std::make_shared<Dog>(); // preferred way and inplace construction
   4. p.reset(p1);
 
Functions:
 * p.use_count()    //get the reference count of the original pointer
 * p.get()  //retunr the original pointer of the object


Cast ways of shared pointers:
 *  static_pointer_cast
 *  dynamic_pointer_cast
 *  const_pointer_cast

Ways to delete original pointer in the shared_ptr
 1. p1 = p2   //p1's original object's reference count will --, the object will be destructed if the count == 0
 2. p1 = nullptr  //the same as 1.
 3. p1.reset()    //the same as 1.

Custom deleter:
 * std::shared_ptr<Dog> p(new Dog("V"), [](Dog* p){... delete[] p;});   //define the deleter in the creation of shared pointer


Note:
 1. Avoid use original pointer if it's set to a smart pointer, cuz shared pointer may access violation if orginal pointer got deleted



/*** Weak Pointer ***/
    1. weak_ptr can only access to the object but has no ownership of it
    2. weak_ptr can't delete the object because it doesn't account for reference count, destruction of weak_prt will not entails count--
    3. weak_ptr will be empty if the raw object get deleted
    4. weak_ptr can only be used with lock(), which will create a shared_ptr for the weak pointer to avoid the raw pointer get deleted while using it
    5. expired() of weak_ptr can be used to determine if the raw object is still valid
    6. use_count() of weak_ptr can be used to determine the value of reference count.

Note:
    weak_ptr is a way to resolve cyclic reference, which could leads to memory leak

