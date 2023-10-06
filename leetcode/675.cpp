#include<iostream>
#include<vector>
#include<functional>
using namespace std;



int cutOffTree(vector<vector<int>>& forest) {
    int m = forest.size(), n = forest[0].size(), mn = m*n, ans = 0;
    vector<vector<int>> dir {{-1,0},{1,0},{0,1},{0,-1}};
    function<int(pair<int,int>,pair<int,int>)> dij = [&] (const pair<int,int>& a, const pair<int,int>& b){
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(m, vector<int>(n, 0));
        dis[a.first][a.second] = 0;
        for(int i=0; i<mn; ++i){
            int d = INT_MAX;
            pair<int,int> u {-1,-1};
            for(int j=0; j<m; ++j){
                for(int k=0; k<n; ++k){
                    if( vis[j][k] == 0 && dis[j][k] < d && forest[j][k] ){
                        u = {j,k};
                        d = dis[j][k];
                    }
                }
            }
            if( d == INT_MAX ) return dis[b.first][b.second] == INT_MAX ? -1 : dis[b.first][b.second];
            int xx = u.first, yy = u.second;
            vis[xx][yy] = 1;
            for(int j=0; j<4; ++j){
                int x = x + dir[j][0], y = yy + dir[j][1];
                if( x>=0 && x <m && y>=0 && y<n && vis[x][y] == 0 && d + 1 < dis[x][y] && forest[x][y]  ) dis[x][y] = d + 1 ;
            }
        }
        return dis[b.first][b.second] == INT_MAX ? -1 : dis[b.first][b.second];
    };
    vector<vector<int>> v;
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if( forest[i][j] ) v.push_back({forest[i][j], i, j});
        }
    }
    sort(v.begin(), v.end(), [](vector<int>a, vector<int>b){
        return a[0] < b[0];
    });
    if( v[0][1]  || v[0][2] ) return -1;
    for(int i=1; i<v.size(); ++i){
        int cnt = dij({v[i-1][1],v[i-1][2]}, {v[i][1], v[i][2]});
        if( cnt == -1 ) return -1;
        else ans += cnt;
    }
    return ans ;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; ++i ){
        for (int j = 0; j < n; ++j){
            cin >> v[i][j];
        }
    }
    cout << cutOffTree(v);
}