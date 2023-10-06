#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<functional>
#include<cstdlib>
#include<cstring>
using namespace std;


    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), ind = 0, t = 0;;
        vector<vector<int>> vis(m,vector<int>(n,0) );
        unordered_map<int,int> ump;
        for(int i=0; i<queries.size(); ++i ) ump[ queries[i] ] = i;
        sort(queries.begin(), queries.end() );

        vector<int> ans(queries.size());
        
        queue<pair<int,int>>q;
        
        auto cmp = [&](const pair<int,int>&x, const pair<int,int> & y){
            return grid[x.first][x.second] > grid[y.first][y.second];
        } ;
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp) > qq(cmp);

        function<void(int)> f = [&](int idx) ->void {

            while( !q.empty() ){
                auto k = q.front();
                q.pop();
                int x = k.first, y = k.second;
                if( vis[x][y] ) continue;
                vis[x][y] = 1;
                if( y < n-1 && vis[x][y+1] == 0 ){
                    if( grid[x][y+1] < queries[idx]  ) q.push({x,y+1});
                    else qq.push({x,y+1} );
                }
                if( x < m-1 &&  vis[x+1][y] == 0 ){
                    if( grid[x+1][y] < queries[idx] ) q.push({ x+1,y} );
                    else qq.push({x+1,y} );
                }
                if( y > 0 &&  vis[ x][y-1] == 0 ) {
                    if( grid[x][y-1] < queries[idx] ) q.push({x,y-1});
                    else qq.push({x,y-1});
                }
                if( x > 0 &&  vis[x-1][y] == 0  ) {
                    if( grid[x-1][y] < queries[idx] ) q.push({x-1,y});
                    else qq.push({x-1,y} );
                }
                t++;
            }
        };
        function<int(pair<int,int>)> ff = [&] (const pair<int,int> & a) ->int{
            return grid[a.first][a.second];
        };
        while( ind < queries.size() && queries[ind] <= grid[0][0] ){
            ans[ ump[ queries[ind++]] ] = 0;
        }
        q.push({0,0});
        while( ind < queries.size() ){
            f(ind);
            ans[ ump[queries[ind]] ] = t;
            ind++;
            if( ind < queries.size() )
                while( !qq.empty() &&ff(qq.top()) < queries[ind] ){
                    q.push(qq.top()), qq.pop();
                }
        }
        return ans;
    }


int main(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> v(m, vector<int>(n));
    vector<int> vv(k);
    for (int i = 0; i < m; ++i){
        for (int j = 0; j<n; ++j){
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < k; ++i)
        cin >> vv[i];
    auto ss = maxPoints(v, vv);
    for( auto kk : ss){
        cout << " " << kk;
    }
    return 0;
}