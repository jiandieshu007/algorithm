#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 1010;

int main(){

    int n, m;


    vector<int> w(N), v(N);
    cin >> n >> m;
    vector<vector<int>> f(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n;i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m;j++){
            f[i][j] = f[i - 1][j]; // 0的时候
            if( j >= w[i] ) // 针对第i个物品
                f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i]); // f[i][ j-v[i] ] 即 在前 i个物品中 背包容量剩余 j-v[i] 能装下的最大价值 
        }
    }
    cout << f[n][m];
    return 0;
}