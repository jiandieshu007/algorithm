#include<iostream>
#include<vector>
using namespace std;
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(), flg = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=0; i<=m; ++i ) dp[0][i] = 1;
        for(int i=0; i<n; ++i){
            if( p[i] == '*' ){
                flg = 1;
                for(int j=0; j<=m; ++j){
                    if( dp[i][j] ){
                        for(int k=j; k<=m; ++k){
                            dp[i+1][k] = 1;
                        }
                        if( m && j == m ){
                            dp[i+1][m] = dp[i][m-1];
                        }
                        break;
                    }
                }
                continue;
            }
            for(int j =0; j<m; ++j){
                if( p[i] == '?' || p[i]== s[j]) dp[i+1][j+1] = dp[i][j];
            }
        }
        return dp[n][m] && (flg || m == n);
    }

int main(){
    string s = "", p;
    cin >>s >> p;
    cout << isMatch(s, p);
    return 0;
}