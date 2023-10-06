#include<iostream>
#include<string>
#include<vector>
using namespace std;

int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n+1,0);
    if( s[0] == '0' ) dp[1] = 0;
    else dp[1] = 1;
    dp[0] = 1;
    for(int i=1; i<n;i++){
        int a = s[i] -'0';
        int b = ( s[i-1] - '0') *10 + a;
        if( a>=1 && a <=9 ) dp[i+1] = dp[i];
        if( b>=10 && b <= 26 ) dp[i+1] += dp[i-1];
    }
    return dp[n];
}

int main(){
    string s;
    cin >> s;
    cout<<numDecodings(s);
    return 0;
}