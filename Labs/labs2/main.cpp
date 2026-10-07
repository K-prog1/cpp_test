#include "Time.hpp"
#include <iostream>

int main() {
    Time t1;                
    Time t2(5);              
    Time t3(5, 2, 9);        
    t1.info();
    t2.info();
    t3.info();

    t3.addSeconds(3600);     
    t3.info();

    t3.subSeconds(7);        
    t3.info();

    Time a(23, 50, 30);
    Time b(0, 15, 45);
    a.addTime(b);           
    a.info();

    a.subTime(b);            
    a.info();

    std::cout << a.toSeconds() << std::endl;   
}