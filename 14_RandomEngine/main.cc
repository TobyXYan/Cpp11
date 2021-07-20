//Topic: Random Engine and Distribution
//  - Random Engine: Stateful generator that generates random values within predefined min and max. Not truely random -- pseudorandom

/*Random Engine
     *1. std::default_random_engine eng;
     *2. eng.min(), eng.max()
     *3. std::stringstream state; state<<eng; ... state>>eng;
     *4. std::default_random_engine es(seed);//seed based random
*/

/*Random Distribution 
     *1. std::default_random_engine e; std::uniform_int_distribution<int> distr(0,5); distr(e);
     *2. std::uniform_real_distribution<double> distrR(0,5); distrR(e);
     *3. std::poisson_distribution<int> distrP(1.0); distrP(e);
     *4. std::normal_distribution<double> distrN(10.0,3.0); distrN(e);
*/

#include <iostream>
#include <sstream>
#include <random>
#include <chrono>
#include <vector>

void printRandom(std::default_random_engine e) {
  for(int i = 0; i<10;++i){
    std::cout<<e()<<" ";
  }
  std::cout<<std::endl;
}

//Random Engine
/*
int main() {
  std::default_random_engine eng;
  std::cout<<"Min:"<<eng.min()<<std::endl;
  std::cout<<"Max:"<<eng.max()<<std::endl;
  std::cout<<eng()<<std::endl;
  std::cout<<eng()<<std::endl;

  std::stringstream state;
  state<<eng; //Save current state

  std::cout<<eng()<<std::endl;
  std::cout<<eng()<<std::endl;

  state>>eng; //Restore state
  std::cout<<eng()<<std::endl;
  std::cout<<eng()<<std::endl;

  //At the same state they are creayed, hence the random values are the same
  std::default_random_engine e1;
  std::default_random_engine e2;
  printRandom(e1);
  printRandom(e2);


  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::default_random_engine e3(seed);
  printRandom(e3);

  e1.seed(); //reset engine e to initial state
  e1.seed(109); //set engine e1 to a state according to seed 109
  e2.seed(109);
  if(e1==e2)
    std::cout<<"e1 and e2 have the same state"<<std::endl;

  std::vector<int> d{1,2,3,4,5,6,7,8,9};
  for(auto e:d)
    std::cout<<e<<" ";
  std::cout<<std::endl;
  //std::shuffle(d.begin(), d.end(), std::default_random_engine());
  //for(auto e:d)
  //  std::cout<<e<<" ";
  return 0;
}*/

//Random Distribution
int main() {
  unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
  std::default_random_engine e(seed);
  std::cout<<e()<<std::endl; //range: [e.min(), e.max()]

  //Range: [0,5]
  std::cout<<e()%6<<std::endl;
  //1. Bad quality of randomness
  //2. Can only provide uniform distribution
  
  std::uniform_int_distribution<int> distr(0,5);// Range: [0,5]
  std::cout<<distr(e)<<std::endl;
  
  std::uniform_real_distribution<double> distrR(0,5);// Range: [0,5)
  std::cout<<distrR(e)<<std::endl;
  
  std::poisson_distribution<int> distrP(1.0);// mean
  std::cout<<distrP(e)<<std::endl;

  std::cout<<" normal_distribution: "<<std::endl;
  std::normal_distribution<double> distrN(10.0,3.0);//mean and standard deviation

  std::vector<int> v(20);
  for(int i = 0; i<800; ++i){
    int num = distrN(e); //Convert double to int implicitly
    if(num >= 0 && num <20)
      v[num]++; //E.g., v[10] records number of times 10 appeared
  }
  for(auto e:v)
    std::cout<<std::string(e, '*')<<std::endl;
  std::cout<<std::endl;


  return 0;
}
