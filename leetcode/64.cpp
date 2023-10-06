#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = grid[0][0];
    for(int i=1; i<n; i++){
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }
    for(int i=1; i<m; i++){
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = grid[i][j] + min( dp[i][j-1], dp[i-1][j] );
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> k(m, vector<int>(n));
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n; j++){
            cin >> k[i][j];
        }
    }
    cout << minPathSum(k);
    return 0;
}