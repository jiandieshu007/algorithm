
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int inf  = 1e9;
vector<vector<int>> map(3010,vector<int>(3010,inf) );


int djkstra(int n,int s, int d){
    vector<int> can_go(n, 0); 
    vector<int> min_k(n,inf);
    vector<int> vis(n,0);
    vector<int> pre(n, -1);
    min_k[s] = 0;
    can_go[s] = 1;
    for(int i=0; i<n; i++){
        int u = -1, min = inf;
        for( int j = 0; j<n; j++){
            if( min_k[j] < min && vis[j] == 0 ){
                u = j;
                min = min_k[j];
            }
        }
        vis[u] = 1;
        if( u == -1 ) break;
        for(int v=0; v<n; v++){
            if( map[u][v] != inf && vis[v] == 0){
                if( can_go[v] == 0 ){
                    min_k[v] = max( min_k[u], map[u][v] );
                    can_go[v] = 1; //第一次到达该点
                    pre[v] = u;
                }else{
                    if( max( min_k[u], map[u][v]) < min_k[v] ){
                        min_k[v] = max(min_k[u], map[u][v]);
                        for (int j = 0; j < n; j++){
                            if( pre[j] == v){
                                min_k[j] = max(min_k[v], map[v][j]);
                            }
                        }
                        pre[v] = u;
                    }

                }
            }
        }
    }
    return min_k[d];
}
int main(){
    int n, m, s , d;
    cin>> n>>m >> s >> d;

    while( m--){
        int a, b, c;
        cin>>a >>b >> c;
        map[a][b] = c;
        map[b][a] = c;
    }
    int ans = djkstra(n ,s, d) ;
    cout<<ans;
    return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    int m;
    cin>>m;
    int src,dest;
    cin>>src>>dest;
    vector<vector<pair<int,int>>> edges(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[u].push_back(make_pair(v,w));
    }   
    vector<int> dis(n+2,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> myheap;
    myheap.push(make_pair(0,src));
    vector<bool> vis(n,false);
    while(myheap.size()>0){
        auto tmp=myheap.top();
        myheap.pop();
        if(vis[tmp.second]){
            continue;
        }
        dis[tmp.second]=tmp.first;
        vis[tmp.second]=true;
        for(int i=0;i<edges[tmp.second].size();i++){
            if(vis[edges[tmp.second][i].first]==false&&max(edges[tmp.second][i].second,tmp.first)>dis[edges[tmp.second][i].first]){
                myheap.push(make_pair(max(edges[tmp.second][i].second,tmp.first),edges[tmp.second][i].first));
            }
        }
    }
    cout<<dis[dest];
    return 0;
}
