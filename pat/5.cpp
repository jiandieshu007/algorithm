#include<iostream>
using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;

    string s = s2+s1;
    string ans = "";
    int i = s1.size()/2-1, k = s.size()-1, cnt = 1;
    int n = s.size()/4 ;

    while( n-- ){
        ans += s[i];
        ans += s[ k - i ];
        ans += s[ i + 2*cnt - 1 ];
        ans += s[ k - i - 2*cnt + 1];


        i--;
        cnt++;
    }
    cout<<ans;
        return 0;
}