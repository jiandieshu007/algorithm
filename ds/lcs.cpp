#include<iostream>
#include<vector>
using namespace std;

const int n = 5, m = 12;

vector<int> a(n, 0);
vector<int> b(m, 0);

vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

int main(){
    for (int i = 0; i < n; i++ )
        cin >> a[i];
    for (int j = 0; j < m; j++ )
        cin >> b[j];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i] == b[j])
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]) + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    int ans = dp[n][m];

    cout << ans;
    return 0;
}
