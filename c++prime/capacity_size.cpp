#include<iostream>
#include<vector>


int main(){
    std::vector<int> v;
    const char *s1 = "aaaabb";
    char s2[] = {'x', 'x','\0'};
    std::cout << s2 << std::endl;
    std::string s3(s2);
    std::cout << s3 << std::endl;
    s3.erase(0, 1);
    std::cout << s3 <<std::endl;
    s3.append("xx");
    std::cout << s3 << std::endl;
    if( s3.find("xxxx") == std::string::npos )
        std::cout << "1";
    return 0;
}