#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

bool compute( string &s ){
    string s1 = s, s2 = s, ans = "";
    reverse(s2.begin(), s2.end() );
    int i = s.size()-1, t = 0;
    while( i >=0 ){
        t += s1[i] -'0' + s2[i] -'0';
        ans += to_string(t%10);
        t /=10;
        i--;
    }
    if( t ) ans += to_string(t);
    reverse(ans.begin(), ans.end() );
    cout<<s1<<" + "<<s2<<" = "<<ans;
    s = ans;
    int flg = true;
    for(int i=0; i<s.size()/2; i++){
        if( s[i] != s[s1.size()-1-i] ){
            flg = false;
            break;
        }
    }
    return flg;
}

int main(){
    int k = 10;
    string s;
    cin>>s;
    for(int i=0; i<k; i++){
        if( i ) cout<<endl;
        if( compute(s) ){
            cout<<endl<<s<<" is a palindromic number.";
            return 0;
        }
    }
    cout<<endl<<"Not found in 10 iterations.";
    return 0;
}