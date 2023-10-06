#include<iostream>
#include<vector>
using namespace std;

const int inf = 100000000;


int main(){
    int n, m, s, d;
    cin>>n>>m>>s>>d;
    vector<int> dis(n,inf);
    vector<int> cost(n,0);
    vector<int> vis(n,0);
    vector<int> pre(n,-1);
    vector<vector<int>> g_len(n,vector<int>( n, inf ) );
    vector<vector<int>> g_cost(n, vector<int>( n, inf )  );
    while( m -- ){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        g_len[a][b] = c;
        g_len[b][a] = c;
        g_cost[a][b] = d;
        g_cost[b][a] = d;
     }
    
    dis[s] = 0;
    for(int i=0; i<n; i++){
        int u = -1, min = inf;
        for(int j=0; j<n; j++ ){
            if( dis[j] < min && vis[j] == 0 ){
                u = j;
                min = dis[j];
            }
        }
        if( u == -1 ) break;
        vis[u] = 1;
        for(int v = 0; v<n; v++){
            if( g_len[u][v] != inf && vis[v] == 0 ){
                if( dis[u] + g_len[u][v] < dis[v] ){
                    pre[v] = u;
                    dis[v] = dis[u] +g_len[u][v];
                    cost[v] = cost[u] + g_cost[u][v];
                }else if( dis[u] + g_len[u][v] == dis[v] && cost[u] + g_cost[u][v] < cost[v ] ){
                    pre[v] = u;
                    cost[v] = cost[u] + g_cost[u][v];
                }
            }
        }
    }
    vector<int> ans;
    int i = d;
    while( pre[i] != s ){
        ans.push_back(i);
        i = pre[i];
    }
    ans.push_back(i);
    cout<<s;
    for(int j=ans.size()-1; j>=0; j--){
        cout<<' '<<ans[j];
    }
    cout<<' '<<dis[d]<<' '<< cost[d];
    return 0;
}