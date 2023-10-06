#include<iostream>
#include<vector>
using namespace std;
const int inf = 10000010;

int dijsktra(int n, vector<vector<int>>& gh, int source, int destination, int target ){
    int cnt = 0;
    vector<int> vis(n,0), dis(n, inf), path(n, inf);
    dis[source] = 0;
    for(int i = 0; i<n; i++){
        int min = inf, u = -1;
        for(int j = 0; j<n; ++j){
            if( vis[j] == 0 && dis[j] < min){
                min = dis[j];
                u = j;
            }
        }
        if( u == -1 ) break;
        vis[u] = 1;
        
        for(int v = 0; v<n; ++v){
            if( vis[v] == 0 )
                if( gh[u][v] != inf && dis[u] + gh[u][v] < dis[v] ){
                    dis[v] = dis[u] + gh[u][v];
                    path[v] = u;
                }
        }
    }
    for( int i = destination; ; i = path[i] ){
        if( i == source ) break;
        
        if( gh[i][path[i] ] < 0 ) cnt++;
    }
    
    target -= ( dis[destination] + cnt );
    if( target < cnt && cnt  ) return 0;
    else if( target && cnt == 0 ) return 0;
    else if( target == 0 && cnt == 0 ) return 2;
    for( int i = destination; ; i = path[i] ){
        
        if( gh[i][ path[i] ] == -1 ){
            if( cnt == 1){
                gh[i][path[i]] = gh[ path[i] ][i] = target;
                break;
            }else{
                cnt--;
                target--;
                gh[i][path[i]] = gh[ path[i] ][i] = 1;
            }
        }
    }
    return 1;
}

vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    int cnt = 0;
    vector<vector<int>> gh(n,vector<int>(n,inf));
    for(size_t i = 0; i<edges.size(); i++){
        gh[ edges[i][0] ][ edges[i][1] ] = gh[ edges[i][1] ][ edges[i][0] ] = edges[i][2];
    }
    for( int k =  dijsktra(n, gh, source, destination, target); k ; k = dijsktra(n, gh, source, destination, target) ){
        if( k == 2){
            vector<vector<int>> ans;
            for(int i=0; i<n; ++i){
                for(int j = i; j <n; ++j){
                    if( gh[i][j] != inf){
                        if( gh[i][j] == -1){
                            ans.push_back( { i, j, 1} );
                        }else ans.push_back( { i, j , gh[i][j] } );
                    }
                }
            }
            return ans;
        }
    }
    return {  };
}

int main(){
    int n, sou, des, tar, k;
    cin >> n >> sou >> des >> tar >> k;
    vector<vector<int>> v;
    while( k-- ){
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
    auto ans = modifiedGraphEdges(n, v, sou, des, tar);
    return 0;
}