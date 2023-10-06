#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool choice[10010][110];

int cmp1(int a, int b){return a > b;}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> w(n+1,0), dp(m+1, 0);
    for(int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    sort(w.begin() +1 , w.end() , greater<int>() );
    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= w[i]; j--) {
            if(dp[j] <= dp[j-w[i]] + w[i]) {
                choice[i][j] = true;
                dp[j] = dp[j-w[i]] + w[i];
            }
        }
    }
    if(dp[m] != m) printf("No Solution");
    else {
        vector<int> arr;
        int v = m, index = n;
        while(v > 0) {
            if(choice[index][v] == true) {
                arr.push_back(w[index]);
                v -= w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}