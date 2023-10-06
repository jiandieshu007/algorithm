
#include<iostream>
#include "timee.h"


timee::timee(){
    hour = mins = 0;
}

timee::timee(const int & h, const int & m){
    hour = h;
    mins = m;
}

void timee::addh(const int & h){
    hour += h;
}

void timee::addm(const int & m ){
    mins += m;
    hour += mins/60;
    mins %= 60;
}

void timee::reset(const int & h , const int & m ){
    hour = h;
    mins = m;
}

void timee::operator+(const timee & t ){
    hour += t.hour;
    mins += t.mins;
    hour += mins / 60;
    mins %= 60;
}
void timee::operator=(const timee& t ){
    hour = t.hour;
    mins = t.mins;
}

void timee::show() const{
    std::cout<< hour<<" "<<mins<<std::endl;
}

timee operator*(const double& m, const timee& t) {
    timee res;
    res.hour = t.hour * m;
    res.mins = t.mins * m;
    res.hour += res.mins / 60;
    res.mins %= 60;
    return res;
}

std::ostream & operator<<(std::ostream& os, const timee& t) {
    os << t.hour << ' ' << t.mins << std::endl;
    return os;
} // 重载<< 运算符 作为友元 

std::istream& operator<<(std::istream& is, const timee& t) {
    is << t.hour << t.mins;
    return is;
}