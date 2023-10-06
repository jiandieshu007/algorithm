#include<iostream>
#include<cstring>
#include<vector>

int main(){
    const std::string s("qaqonijiang");
    for(int i=0; i<s.size(); i++ ){
        std::cout<<s[i];
    }
    std::cout<<std::endl;
    for(decltype(s.size() ) i = 0; i<s.size(); i++){
        std::cout<<s[i];
    }
    std::cout<<std::endl;
    for(auto &c : s){
        std::cout<<c;
    }
    std::cout<<std::endl;
    std::vector<int> v{1,2};
    auto it1 = v.begin(), it2 = v.end();
    std::cout<< it2-it1;
    return 0;
}