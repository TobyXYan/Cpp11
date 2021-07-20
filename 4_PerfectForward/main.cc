//Topic: Perfect Forwarding
//Usage of rvalue reference
//  1. Move semantic
//  2. Perfect forwarding


//Reference Collapsing Rules
//  1. T& &   ==> T&
//  2. T& &&  ==> T&
//  3. T&& &  ==> T&
//  4. T&& && ==> T&&
//?? perfect_relay(9); => T= int&&  => T&&=int&& && = int&&
//?? int x; or int& x = y; perfect_relay(x); => T = int& => T&& = int& && = int&

//T&& is universal reference: rvalue, lvalue, const, non-const, etc
//Conditions:
//  1. T is a template type
//  2. type deduction (reference collapsing) happens to T.
//      - T is a function template type, not class template type
//
//Understand std::forward
//Here we have to make sure that both lvalue reference and rvalue reference has std::forward function to handle
//as for  std::remove_reference<T>::type = string, for either string& or string&&
//so the first forward accepts string&, and the second forward accept string&&
//and in these two functions, respective value type will be returned accordingly 
//
//Note:
//std::move(arg)    //turn arg into an rvalue type
//std::forward<T>(arg); //keep it'scurrent type

template <class T>
inline T&& forward(typename std::remove_reference<T>::type& t) noexcept
{
    return static_cast<T&&>(t);
}

template <class T>
inline T&& forward(typename std::remove_reference<T>::type&& t) noexcept
{
    static_assert(!std::is_lvalue_reference<T>::value,
                  "Can not forward an rvalue as an lvalue.");
    return static_cast<T&&>(t);
}

#include <iostream>

class boVector {
  public:
    int size;
    double* arr;
    boVector(int size):size(size){
      arr = new double[size];
      for(int i =0; i<size; ++i)
        arr[i] = i+1;
    }

    boVector(boVector&& bo) {
      arr = bo.arr;
      bo.arr = nullptr;
      size = bo.size;
    }

    boVector(const boVector& bo) = default;
};


void foo(boVector arg) {
  for(int i = 0; i<arg.size; ++i)
    std::cout<<arg.arr[i]<<' ';
  std::cout<<std::endl;
}


//Relay function should meet the requirements -  perfect forwarding
//1. No costly and unnecessart copy ctor of boVector is made
//2. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue
template<typename T>
void relay(T arg){
  foo(arg);
}


//Solution
template<typename T>
void perfect_relay(T&& arg) {//T&& here is an universal reference
  foo(std::forward<T>(arg));
}


int main() {
  boVector bo(5);
  relay(std::move(bo));
  return 0;
}
