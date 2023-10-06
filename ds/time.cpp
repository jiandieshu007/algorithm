
#include<iostream>
#include "time.h"


time::time(){
    hour = mins = 0;
}

time::time(const int & h, const int & m = 0){
    hour = h;
    mins = m;
}

time::addh(const int & h){
    hour += h;
}

time::addm(const int & m ){
    mins += m;
    hour += mins/60;
    mins %= 60;
}

time::reset(const int & h , const int & m ){
    hour = h;
    mins = m;
}

"""time::operator+(const time & t ){
    hour += t.hour;
    mins += t.mins;
    hout++ mins / 60;
    mins %= 60;
}
time::operator=(const time& t ){
    hour = t.hour;
    mins = t.mins;
}"""

time::show() const{
    std::cout<< hour<<" "<<mins<<std::endl;
}