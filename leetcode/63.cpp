#include<iostream>
#include<vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n,0));
    // 初始化状态
    dp[0][0] = 1;
    for(int i=1; i< n; i++){
        if( obstacleGrid[0][i] ) dp[0][i] = 0;
        else dp[0][i] = dp[0][i-1];
    }
    for(int i=1; i<m; i++){
        if( obstacleGrid[i][0] ) dp[i][0] = 0;
        else dp[i][0] = dp[i-1][0];
    }
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if( obstacleGrid[i][j] == 0){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> dp(m, vector<int>(n,0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> dp[i][j];
        }
    }
    cout << uniquePathsWithObstacles(dp);
    return 0;
}