#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k, ans = 0; // 第一步能分成多少个段
    cin>>n>>k;
    vector<int> info(n);
    for(int i=0; i<n; i++) cin>>info[i];
    
    sort(info.begin(), info.end() );
    for(int i=0; i<n; i++){
        int j = i+1, flg = 0; // flg = 0 对应一个人成一组 flg != 0 
        while( j < n &&  info[j] - info[j-1] <= k ){
            j++;
            flg = 1;
        }

        ans++;

        i = j-1;
    }

    if( ans > 1) cout<< ans-1;
    else cout<<"0";
    return 0;
}