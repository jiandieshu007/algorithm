#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, ans = 0 ;
    cin>>n;
    vector<int> rid(n);
    for(int i=0; i<n; i++ ) cin>>rid[i]; // 骑行距离 大于 rid[i] 的天数 有 n-i 天
    sort(rid.begin(), rid.end());
    for (int i = 0; i < n; i++){
        if( n-i -1== rid[i] )
            ans = rid[i];
    }
    cout << ans;
}