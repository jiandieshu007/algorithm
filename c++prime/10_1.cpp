#include<iostream>
#include<vector>
#include<numeric>


int main(){
    std::vector<int> v;
    for (int i = 1; i < 99;i++){
        v.push_back(i);
    }
    auto res = accumulate(v.begin(), v.end(), 0);
    std::cout << res;
    return 0;
}