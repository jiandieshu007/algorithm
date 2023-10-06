#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>

bool check(const std::string & s , std::string::size_type sz ){
    return s.size() > sz;
}

int main(){
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::vector<int> v(in_iter, eof);
    for(auto it : v){
        std::cout << it << " ";
    }
    return 0;
}   