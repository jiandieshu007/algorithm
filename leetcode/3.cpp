#include<iostream>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int ans = 0, start = 0, end = 0;
    map<char,int> m;
    for(int i=0; i<s.size(); i++){
        if(m.find(s[i]) == m.end() ){
            end = i;
            m[s[i] ] = i;
        }else{
            if( end - start > ans ) ans = end - start;
            start = m[ s[i] ]  ;
            m[s[i] ] =i;
        }
    }
    if( end - start > ans ) ans = end - start;
    return ans;
}


int main(){
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}