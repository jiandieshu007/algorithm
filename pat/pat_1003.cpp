#include<iostream>
#include<vector>
using namespace std;
//最小路径问题

const int INF = 100000000;


int main(){
    int n, m, c1, c2;
    cin>> n>> m>> c1>> c2;
    vector<int> teams(n), dis(n,INF),max_team(n,0), road(n,0);
    vector<vector<int>> g(n, vector<int>(n,INF));
    for( int i=0; i<n; i++)
        cin>>teams[i];
    for( int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] =  c;
        g[b][a] = c;
    }
    dis[c1] = 0;
    max_team[c1] = teams[c1];
    vector<int> hash(n,0);
    vector<int> pre(n, -1);
    road[c1] = 1;
    for(int i=0; i<n; i++){
        int start=-1, min = INF;
        for(int i=0; i<n; i++){
            if( dis[i] <= min && hash[i] == 0 ){
                min = dis[i];
                start = i;
            }
        }
        if( start == -1 ) break;
        hash[ start ] = 1;
        for(int i=0; i<n; i++){
            if( hash[i] == false && g[start][i] !=INF )
                if( dis[start] + g[start][i] < dis[i] ){
                    pre[i] = start;
                    dis[i] = dis[start] + g[start][i];
                    max_team[i] = max_team[start] + teams[i];
                    road[i] = road[start];
                }else if( dis[start] + g[start][i] == dis[i]  ){
                    road[i] += road[start];
                    if(  max_team[start] + teams[i] > max_team[i]);
                        max_team[i] = max_team[start] + teams[i];
                }
        }

    }
    cout<<road[c2]<<' '<<max_team[c2];
    return 0;
}