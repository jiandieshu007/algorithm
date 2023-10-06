#include<iostream>
#include<vector>
using namespace std;

const int inf  = 100000000;

void find_root( vector<int> &ans, vector<int> pre, int d){
    int i = d;
    while( pre[i] != 0 ){
        ans.push_back(i);
        i = pre[i];
    }
    ans.push_back(i);
    ans.push_back(0);
}


int main(){
    int M, n, error, m, prefect;
    cin>>M >> n >> error>> m;
    prefect = M/2;
    vector<int> condition(n+1,0);
    vector<int> dis(n+1, inf);
    vector<vector<int>> g(n+1, vector<int> ( n+1, inf) );
    vector<int> vis(n+1, 0);
    vector<int> val(n+1,0);
    vector<int> pre(n+1,-1);
    for(int i=1; i<=n; i++ ) cin>>condition[i];

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>> a>> b>> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    dis[0] = 0;
    
    for(int i=0; i<n; i++){
        int u = -1, min = inf;
        for(int j = 0; j<=n; j++){
            if( dis[j] < min && vis[j] == 0 ){
                min = dis[j];
                u = j;
            }
        }
        if( u == -1 ) break;
        vis[u] = 1;
        for(int v=0; v<=n; v++){
            if( vis[v] == false && g[u][v] != inf){
                if( dis[u] + g[u][v] < dis[v] ){
                    dis[v] = dis[u]+g[u][v];
                    pre[v] = u;
                    val[v] = val[u] + condition[v] - prefect;
                }else if( dis[u] + g[u][v] == dis[v] && val[u] + condition[v] - prefect > val[v] ){
                    val[v] = val[u] + condition[v] -prefect;
                    pre[v] = u;
                }
            }
        }
    }
    vector<int> ans;
    find_root(ans, pre, error);
    if( val[error] <5 ) cout<< 5-val[error];
    else cout<<0;
    cout<<' ';
    for(int i=ans.size()-1; i>=0; i--){
        if( i != ans.size()-1 ) cout<<"->";
        cout<<ans[i];
    }
    cout<<" ";
    if( val[error] > 5 ) cout<< val[error] - 5;
    else cout<<0;
    return 0;
}