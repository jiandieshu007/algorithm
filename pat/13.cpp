#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


void dfs( vector<int> info, int k, int sum , set<int> & ans, int Max){
    for(int i=k; i<info.size(); i++){
        sum += info[i];
        if( sum > Max/2 )
            return;
        ans.insert( sum );
        dfs( info, i+1, sum, ans, Max);
        sum -= info[i];
    }
}
// 1 2 3 // 1 3 6 4 2 5 3
int main(){
    int n, sum = 0;
    cin>>n;
    vector<int> info(n);
    for(int i=0; i<n; i++){
        cin>>info[i];
        sum += info[i];
    }
    sort(info.begin(), info.end());
    set<int> ans;
    dfs(info, 0, 0 , ans, sum);
    auto it = ans.end();
    it--;
    cout << sum - *it;
    return 0;
}