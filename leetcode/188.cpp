#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int k = 2;

int maxProfit(vector<int> &prices)
{
    int n = prices.size(), ans = 0;
    int dp[n][k][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = -prices[0];
    for (int i = 1; i < n; ++i)
    {
        dp[i][0][0] = max(dp[i - 1][0][0], -prices[i]);
        dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] + prices[i]); // 第一笔交易
        ans = max(ans, dp[i][0][1]);
        for (int j = 1; j < k; ++j)
        {
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] - prices[i]);
            if (dp[i - 1][j][0])
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] + prices[i]);
            ans = max(ans, dp[i][j][1]);
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; ++i){
        cin >> v[i];
    }
    maxProfit(v);
    return 0;
}