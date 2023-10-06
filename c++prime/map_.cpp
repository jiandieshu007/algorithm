#include<iostream>
#include<map>

int main(){
    std::pair<int, int> ii;
    ii = std::make_pair(1,1);
    std::cout << ii.first << ' ' << ii.second;
    return 0;
}