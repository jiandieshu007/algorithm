#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int l = intervals[0][0], r = intervals[0][1];
    for (auto &i : intervals)
    {
        if (i == *intervals.begin())
            continue;
        else if (i == *intervals.end())
        {
            ans.push_back( {l,r} );
        }
        else
        {
            if (i[0] <= r && i[0] >= l)
            {
                r = i[1] > r ? i[1] : r;
            }
            else if (i[0] < l)
            {
                l = i[0];
                r = i[1] > r ? i[1] : r;
            }
            else
            {
                ans.push_back( {l , r } );
                l = i[0];
                r = i[1];
            }
        }
    }
    ans.push_back({l, r});
    return ans;
}

int main(){
    vector<vector<int>> v(4, vector<int>(2));
    for (int i = 0; i < 4; i++ ){
        for (int j = 0; j < 2; j++ ){
            cin >> v[i][j];
        }
    }
    auto ans = merge(v);
    return 0;
}