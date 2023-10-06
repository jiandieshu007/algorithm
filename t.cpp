#include <iostream>
#include<unordered_map>

using namespace std;

    void change(string& s){
        int n = s.size();
        while( n >1 && s[n-1] == '*'  && s[n-1] == s[n-2] ) 
            n--;
        s = s.substr(0,n);
        int i = 0;
        while( i+1 < n && s[i] == '*' && s[i] == s[i+1]){
            i++;
        }
        s = s.substr(i);
    }

int main() {
    string s = "***";
    change(s);
    cout << s << endl;
    string t = "**a";
    change(t);
    cout << t << endl;
    string k = "**a**";
    change(k);
    cout << k << endl;
    string y = "a**";
    change(y);
    cout << y;
    return 0;
}

/*
class hasptr{
public:
    hasptr(const std::string &s = std::string()) : ps(new std::string(s)) {};
    ~hasptr();
private:
    std::string *ps;
}
    
hasptr f(hasptr hp){
    hasptr ret = hp;
    return ret;
}
*/