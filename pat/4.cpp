#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int M = 2000;

vector<vector<int>> map(M,vector<int>(M,1));

int main(){
    int k;
    cin>> k;
    while( k--){
        int a, b, r;
        cin>>a >>b >> r;
        a += 1000;
        b += 1000;
        for(int i=a-r; i<=a+r; i++){
            for(int j=b-r; j <= b+r; j++){
                if( pow( i-a, 2) + pow( j-b, 2) <= pow(r,2) ) map[i][j] = 0; // 找到可以屏蔽信号的点
            }
        }
    }
    int i1, j1, i2, j2;
    cin>>i1>> j1>> i2>> j2;
    i1 += 1000, i2+= 1000, j1 += 1000, j2+= 1000;
    cout << map[1014][ 1001];
    if( i1  >= i2 && j1 <= j2 ){// 左上
        int n = i1- i2, m = j2 - j1;
        vector<vector<int>> dp(n+1, vector<int>(m+1) );
        dp[0][0] = 0;

        for(int i=1; i<n+1; i++){
            dp[i][0] = dp[i-1][0] + map[i1-i][j1];
        }
        for(int i=1; i<m+1; i++){
            dp[0][i] = dp[0][i-1] + map[i1][j1+i];
        }
        for(int i=1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1] ) + map[i1-1][j1+j];
            }
        }
        printf("%.2f",(float)dp[n][m]);
    }else if( i1 >= i2 && j1 >= j2 ){ //左下
        int n = i1- i2, m = j1 - j2;
        vector<vector<int>> dp(n+1, vector<int>(m+1) );
        dp[0][0] = 0;

        for(int i=1; i<n+1; i++){
            dp[i][0] = dp[i-1][0] + map[i1-i][j1];
        }
        for(int i=1; i<m+1; i++){
            dp[0][i] = dp[0][i-1] + map[i1][j1-i];
        }
        for(int i=1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1] ) + map[i1-i][j1-j];
            }
        }
        printf("%.2f",(float)dp[n][m]);
    }else if( i1 <= i2 && j1 <= j2){ // 右上
        int n = i2- i1, m = j2 - j1;
        vector<vector<int>> dp(n+1, vector<int>(m+1) );
        dp[0][0] = 0;

        for(int i=1; i<n+1; i++){
            dp[i][0] = dp[i-1][0] + map[i1+i][j1];
        }
        for(int i=1; i<m+1; i++){
            dp[0][i] = dp[0][i-1] + map[i1][j1+i];
        }
        for(int i=1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1] ) + map[i1+i][j1+j];
            }
        }
        printf("%.2f",(float)dp[n][m]);
    }else { // 右下
        int n = i2- i1, m = j1 - j2;
        vector<vector<int>> dp(n+1, vector<int>(m+1) );
        dp[0][0] = 0;

        for(int i=1; i<n+1; i++){
            dp[i][0] = dp[i-1][0] + map[i1+i][j1];
        }
        for(int i=1; i<m+1; i++){
            dp[0][i] = dp[0][i-1] + map[i1][j1-i];
        }
        for(int i=1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1] ) + map[i1+i][j1-j];
            }
        }
        printf("%.2f",(float)dp[n][m]);
    }
    return 0;
}

