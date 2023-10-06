#include<iostream>
#include<vector>
using namespace std;

const int inf = 1e9;
const int M = 1010;
vector<vector<int>> g(M, vector<int>(M, inf) );


bool check( vector<int> road){
    int n =road.size();
    vector<int> vis(n+1, 0);
    vector<int> dis(n+1, inf);
    dis[ road[0] ] = 0;
    for(int i=0; i<n; i++){
        int u = road[i], min = inf;
        if( road[u] == inf || vis[u] == 1 ) return false; // 判断这个点 是否能取到
        
        for(int j = 1; j<=n; j++){
            if( vis[j] == 0 && dis[j] < dis[u] ) return false;
        }
        vis[u] = 1;
        for(int v=1; v<=n; v++){
            if( g[u][v] != inf && vis[v] == 0 ){
                if( dis[v] > dis[u] + g[u][v] ){
                    dis[v] = dis[u] + g[u][v];
                }
            }
        }
    }
    return true;
}
int main(){
    int n, m;
    cin>>n >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>> a>> b>> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    int k;
    cin>>k;
    for(int i=0; i<k; i++){
        if( i ) cout<<endl;
        vector<int> djroad(n);
        for(int j=0; j<n; j++) cin>>djroad[j];
        
        if( check( djroad ) ) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}