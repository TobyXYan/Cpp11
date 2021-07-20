//Topic: Tuple
/* 1. std::tuple<int, string> t(23,"24");  //way to create an object 
 * 2. std::tuple<int, string> t1 =std::make_tuple(24, "24"); t1 = t; //Assign one to another
 * 3. std::get<0>(t);  //way to get property value
 *      //tuple can store references
 * 4. std::string s; std::tuple<string&> t(s);   //Way 1
 *    t = std::make_tuple(std::ref(s));          //Way 2
 *    std::tie(s) = t;                           //Way 3
 *      //tuple can be concatenated
 * 5. auto t3 = std::tuple_cat(t, t1);
 * 6. std::tuple_size<decltype(t4)>::value
 *    std::tuple_element<1, decltype(t4)>::type d
 * 7. if(t1 > t) ... //lexicographical comaprison
 */

//Note:
//  tuple is more convenient as a one-time only structure to transfer a group of data
//  As for a group of data which is sused widely in different functions, it's better to use
//  structure, as it's more readable with class name and member names.

 
#include <iostream>
#include <tuple>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <map>


/*int main() {
  std::pair<int, std::string> p = std::make_pair(23, "hello");
  std::cout<<p.first<<" "<<p.second<<std::endl;
  
  std::tuple<int, std::string, char> t(32, "Penny Wise", 'a');
  std::cout<<std::get<0>(t)<<std::endl;
  std::cout<<std::get<1>(t)<<std::endl;
  std::cout<<std::get<2>(t)<<std::endl;
  
  std::get<1>(t) = "Pound foolish"; //what get return is a reference
  std::cout<<std::get<1>(t)<<std::endl;


  std::string& s = std::get<1>(t);
  s = "Patience is virtue"; //changes t
  std::cout<<std::get<1>(t)<<std::endl;

  std::tuple<int, std::string, char> t2; //default ctor
  t2 = std::tuple<int, std::string, char>(12, "Curiosity kills the cat", 'd');
  t2 = std::make_tuple(12, "Curiosity kills the cat", 'd');

  if(t>t2){ //lexicographical comparison
    std::cout<<"t is larger than t2"<<std::endl;
    t = t2; // member by member copying
  }
    
  // Tuple can stores references
  std::string st = "In for a penny";
  std::tuple<std::string&> t3(st);
  //t3 = std::make_tuple(std::ref(st));  //Another way to pass reference to tuple
  std::get<0>(t3) = "In for a pound";//st contains "In for a pound" ***

  t2 = std::make_tuple(12, "Curiosity kills the cat", 'd');
  int x;
  std::string y;
  char z;
  std::make_tuple(std::ref(x), std::ref(y),std::ref(z)) = t2;
  std::tie(x,y,z) = t2; //Doing the same thing as preceeding line
  std::tie(x, std::ignore, z) = t2;//We can ignore some elements

  //tuple can be concatenated
  auto t4 = std::tuple_cat(t2,t3); //t4 is a tuple<int,std::string,char,std::string>

  // dedicated type traits
  std::cout<<std::tuple_size<decltype(t4)>::value<<std::endl;//4
  std::tuple_element<1, decltype(t4)>::type d; // d is a string

  return 0;
}*/


std::tuple<std::string,int> getNameAge() {
  return std::make_tuple("Bob", 34);
}

int main() {
  struct Person {std::string name; int age;}p;
  std::tuple<std::string, int> t;

  std::cout<<p.name<<" "<<p.age<<std::endl; //struct is more readable
  std::cout<<std::get<0>(t)<<" "<<std::get<1>(t)<<std::endl;

  std::string name;//tuple is more convenient as a one-time only structure to transfer a group of data
  int age;
  std::tie(name, age) = getNameAge();


  //Comparison of tuples
  std::tuple<int, int, int> time1, time2;//hours, mins, seconds
  if(time1>time2)
    std::cout<<"time1 is a later time"<<std::endl;

  //Multi Index Map
  std::map<std::tuple<int, char, float>, std::string> m;
  m[std::make_tuple(2,'a',2.3)] = "Faith will move moountains";
  //std::unordered_map<std::tuple<int, char, float>, std::string> hashtable;

  int a, b, c;
  std::tie(b,c,a) = std::make_tuple(a,b,c);

  return 0;
}
