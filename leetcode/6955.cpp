#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;


bool cmp(const pair<int,int> &a, const pair<int,int>& b){
    if( a.second != b.second ){
        return a.second > b.second;
    }else return a.first > b.first;
}
int maxIncreasingGroups(vector<int>& usageLimits) {
    int ans = 0, n = usageLimits.size();
    unordered_map<int,int> ump;
    vector<pair<int,int>> q; 
    for(int i=0; i<n; ++i){
        ump[i] = usageLimits[i];
    }
    for( auto k : ump){
        q.push_back( make_pair(k.first, k.second) );
    }
    for(int i=1; i<=n; ++i){
        bool flg =false;
        int cnt = i;
        sort(q.begin(), q.end() ,cmp);
        for(int j = 0; j<i; ++j){
            if( q[j].second > 0 ){
                q[j].second--;
                cnt--;
                if( cnt == 0 ){
                    ans++;
                    flg = true;
                }
            }else break;
        }
        if( flg == false ) break;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> ss(n);
    for (int i = 0; i < n; ++i ){
        cin >> ss[i];
    }
    cout << maxIncreasingGroups(ss);
    return 0;
}