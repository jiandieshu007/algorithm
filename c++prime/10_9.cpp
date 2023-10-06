#include<iostream>
#include<vector>
#include<algorithm>

void elimDups(std::vector<int> &v){
    sort(v.begin(), v.end());
    auto end_unique = unique(v.begin(), v.end());
    v.erase(end_unique, v.end());
}


void fun(){
    int v = 1;
    auto f = [v]
    { return v; };
    std::cout << f();
    v = 0;
    std::cout << f();
}
int main()
{
    fun();
    return 0;
}