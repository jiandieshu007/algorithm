#include<iostream>
#include<vector>
#include<list>
#include<deque>

std::list<std::string> au = {"xx", "xxx", "xxxx"};
std::vector<const char *> art = {"x", "99", "999"};


int main(){
    if( art.begin() == art.cbegin() )
        std::cout << '1';
    return 0;
}   