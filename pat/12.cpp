#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void dfs( int i, int cnt, int &ans, vector<int> info, int k){
    for(int j=i+1; j<info.size(); j++){
        if( abs( info[j] - info[i] ) <= k ){
            if( j < info.size()-1  ){
                cnt++;
                dfs(j, cnt, ans, info, k );
                cnt--;
            }else{
                if( cnt + 1 > ans )
                    ans = cnt+1;
            }
        }else if( j == info.size()-1 && cnt > ans )
            ans = cnt;
    }
}

int main(){
    int n, k, ans = 1;
    cin>>n>>k;
    vector<int> info(n);
    for(int i=0; i<n; i++ ) cin>>info[i];

    for(int i=0; i<n; i++){
        int t = 0, cnt = 1;
        dfs(i, cnt, t, info, k);
        if( t > ans ) ans = t;
    }
    cout<<ans;
    return 0;
}