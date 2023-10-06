#include<iostream>
#include<vector>
using namespace std;


int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    int m = fruits.size(), n = fruits[m-1][0], ans = 0;
    vector<int> dp(n+1);
    for(int i=0; i<fruits.size(); ++i){
        dp[fruits[i][0] ] = fruits[i][1];
    }
    for(int i=startPos+1; i<=n; ++i){
        dp[i] += dp[i-1];
    }
    for(int i=startPos-1; i>=0; --i){
        dp[i] += dp[i+1];
    }

    int left = startPos-k <= 0 ? 0 : startPos-k;
    int right = startPos+k >=n ? n : startPos+k, Max = n-startPos ;
    for(int i=left; i<=startPos; ++i){
        int x , y = 0, ri = startPos;
        x = dp[i];
        int kk = k - 2*(startPos - i); // 多的步数往右走
        kk = min(kk, Max); //多了多少步数
        if( kk >0 ) ri += kk, y= dp[ri]-dp[startPos];
        ans = max(ans, x+y);
    }
    return ans;
}

int main(){
    int n, s, k;
    cin >> n >> s >> k;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n;++i){
        cin >> v[i][0] >> v[i][1];
    }
    cout << maxTotalFruits(v, s, k);
    return 0;
}