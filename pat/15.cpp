#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

const int inf = 1e9;
const int M = 510;
int n, m;

vector< pair<int,int> > ans;
vector<vector<int>> g(M, vector<int>(M, inf ) );

bool cmp( pair<int,int> a, pair<int,int> b){
    if( a.second != b.second ){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}
void dijkstra(){
    vector<int> vis(n+1, 0 );
    vector<int> dis(n+1, inf);
    vector<int> pre(n+1, -1);
    dis[1] = 0;
    for(int i=0; i<n; i++){
        int u = -1, min = inf;
        for(int j=1; j<=n; j++){
            if( vis[j] == 0 && dis[j] < min ){
                u = j;
                min = dis[j];
            }
        }
        if( u == -1 ) return ;

        vis[u] = 1;
        for(int v =1; v<=n ; v++){
            if( g[u][v] !=inf && vis[v] == 0 ){
                dis[v] = dis[u] + g[u][v];
                pre[v] = u;
                if( v == n ){
                    ans.push_back( make_pair( u, dis[v] ) );
                }

            }
        }
    }
}

int main(){
    cin>>n >>m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a >> b>> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    dijkstra();
    int cnt = 0;
    vector<int> vis(n + 1, 0);
    sort(ans.begin(), ans.end(), cmp);

    for (int i = 0; i < ans.size(); i++){
        if( vis[ ans[i].first] == 0 ){
            vis[ans[i].first] = 1;
            cnt++;
        }
    }
    if( cnt <= 1 ){
        cout << "It's a bug!!!";
    }else{
        for (int i = 1; i < ans.size(); i++){
            if( ans[i].first != ans[0].first ){
                cout << ans[i].second;
                return 0;
            }
        }
    }
    return 0;
}