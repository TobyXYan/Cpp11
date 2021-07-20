  //Topic: Clocks and Timers
  /* <chrono> -- A precision-neutral library for time and date
   * Clock: std::chrono::system_clock: current time according to the system - is not steady
   *        std::chrono::steady_clock: goes at a uniform rate
   *        std::high_resolution_clock: provides smallest possible tick period.
   *
   *        std::chrono::duration<>: represents time duration
   *        duration<int, ratio<1,1>> // number of seconds stored in a int
   *        duration<double, ratio<60,1>>// number of minutes stored in a double
   *            //nanoseconds, microseconds, milliseconds, seconds,minutes,hours
   *        system_clock::duration -- duration<T, system_clock::period>
   */

    //1. std::chrono::nanoseconds   std::chrono::milliseconds   std::chrono::microseconds
    //2. std::chrono::duration_cast<std::chrono::milliseconds>(x) //* duratrion_cast required for hight resolution to low resolution
    //.count()
    
    //3. std::chrono::time_point<>: represents a point of time
    //system_clock::time_point  --  time_point<system_clock,system_clock::duration>
    //steady_clock::time_point  --  time_point<steady_clock, stead_clock::duration>

    //4. std::chrono::system_clock::time_point p = std::chrono::system_clock::now();
    //5. std::chrono::steady_clock::time_point p = std::chrono::steady_clock::now();
    //6. std::chrono::duration_cast<std::chrono::microseconds>(x).count();

#include <iostream>
#include <ratio>
#include <chrono>

int main() {
  std::ratio<2,10> r;//1/5
  std::cout<<r.num<<"/"<<r.den<<std::endl;

  std::cout<<std::chrono::system_clock::period::num<<"/"<<std::chrono::system_clock::period::den<<std::endl;

  std::chrono::microseconds mi(2700);
  mi.count(); //it returns 2700
  std::chrono::nanoseconds na = mi;
  na.count();//it returns 2700000
  //From hight resolution to low resolution requires duration_cast
  std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(mi);// 2 milliseconds

  std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();//current time of system clock
  std::cout<<tp.time_since_epoch().count()<<std::endl;
  tp += std::chrono::seconds(2);
  std::cout<<tp.time_since_epoch().count()<<std::endl;

  std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
  std::cout<<"I am bored"<<std::endl;
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::chrono::steady_clock::duration d  =   end - start;
  if(d == std::chrono::steady_clock::duration::zero())
    std::cout<<"no time elapsed";
  else
    std::cout<<std::chrono::duration_cast<std::chrono::microseconds>(d).count()<<std::endl;

  return 0;
}
