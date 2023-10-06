#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


    vector<int> smallestRange(vector<vector<int>>& nums) {
        int left=0, right=0, n = nums.size(), cnt = 0, k = 2*1e5+1;
        vector<pair<int,int>> v;
        pair<int,int> ans ;
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size(); ++i){
            cnt += nums[i].size();
            for(int j=0; j<nums[i].size(); ++j){
                v.push_back( {nums[i][j], i} );
            }
        }
        sort(v.begin(), v.end() );
        while( right < cnt ){
            ump[ v[right].second ]++;
            while( ump.size() == n){
                if( v[right].first - v[left].first < k ){
                    ans = {v[left].first, v[right].first};
                    k =  v[right].first - v[left].first;
                }
                ump[ v[left].second]--;

                if( ump[v[left].second] == 0 ){
                    ump.erase( v[left].second );
                }
                left++;
            }
            right++;
        }
        return {ans.first,ans.second};
    }

int main(){
    int n, m, k;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i){
        cin >> m;
        for (int j = 0; j < m; ++j){
            cin >> k;
            v[i].push_back(k);
        }
    }
    auto ans = smallestRange(v);
    return 0;
}