#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool judge(string s, int i, int k){
    string t = s.substr(i, k);
    string t1 = t;
    reverse(t1.begin(), t1.end());
    if( t1 == t )
        return true;
    else
        return false;
}

int main(){
    int k;
    string s;
    cin>>s >> k;
    int n = s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0; i<n+1; i++) dp[i][0] = 1;

    for(int i=1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(  j >=  i+k-1  ){
                if( judge(s, i-1, j-i+1 ) )
                    dp[i][j] = 1 * dp[i][i - 1];
            }
            dp[i][j] = max(dp[i - 1][j], dp[i][j]); //继承上一行的结果
        }
    }

    if( dp[n][n] == 1 ) cout<<"Yes";
    else cout<<"No";
    return 0;
}