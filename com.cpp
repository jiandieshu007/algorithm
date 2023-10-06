#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> v;
vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(vector<vector<int>> &grid, vector<vector<int>> &dis, int x, int y, int &ans, int k)
{
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid.size() || grid[x][y] == 3 || grid[x][y] == 2 || x + y >= grid.size())
    {
        return;
    }

    k = min(k, dis[x][y]);
    if (k <= ans)
        return;
    if (x + y == grid.size() - 1)
    {
        ans = max(ans, k);
        return;
    }

    grid[x][y] = 2;

    for (int i = 0; i < 4; ++i)
    {
        int nex = x + dir[i][0], ney = y + dir[i][1];
        dfs(grid, dis, nex, ney, ans, k);
    }
    grid[x][y] = 0;
        
}

int maximumSafenessFactor(vector<vector<int>>& grid) {

    int ans = 0, n =grid.size();
    vector<vector<int>> dis(n,vector<int>(n, 1010));
    for(int i=0; i< n; ++i){
        for(int j=0; j< n ; ++j){
            if(grid[i][j] == 1){
                if( i+j <n ) v.push_back( {i,j} );
                else v.push_back( {n - j-1, n -i -1} );
            }
        }
    }
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<v.size();++k){
                dis[i][j]  = min(dis[i][j], abs(i-v[k][0]) + abs(j-v[k][1]) );
            }
        }
    }
    dfs( grid,dis, 0, 0, ans, 1010);
    return ans;
}


int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> v[i][j];
        }
    }
    cout << maximumSafenessFactor(v);
    return 0;
}