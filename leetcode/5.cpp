#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

    int judge( string s, int i, int k){
        string tmp = s.substr(i, k-i+1 );
        string t = tmp;
        reverse(tmp.begin(), tmp.end() );
        if( t == tmp ) return k-i+1;
        else return 0;
    }
    string longestPalindrome(string s) {
        string ans;
        int max = 0;
        for(int i=0; i<s.size(); i++){
            for(int j= s.size()-1; j >= i ; j--){
                if( s[i] == s[j] ){
                    if( judge(s, i, j) > max ){
                        ans = s.substr(i,j-i+1);
                        max = judge(s,i,j);
                    }
                }
            }
        }
        return ans;
    }

int main(){
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}