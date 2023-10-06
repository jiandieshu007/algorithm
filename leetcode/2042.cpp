#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;
bool areNumbersAscending(string s) {
    istringstream t(s); // sstream 标准库
    string beh;
    int pre = -1;
    while( t >> beh ){
        if ( 0 <= beh[0] -'0'  && beh[0] -'0' <= 9){
            int k = stoi(beh); // cstdlib 标准库
            if( pre >= k) return false;
            pre = k ;
        }
    }
    return true;
}

int main(){
    string s;
    getline(cin,s); // string 标准库
    cout << areNumbersAscending(s);
    return 0;
}