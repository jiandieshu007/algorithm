#include<iostream>
#include<vector>
using namespace std;

const int inf = 100000000;
int c1, c2;


void find_road( vector<int> & ans, vector<int> path){
    for(int i=c2; ; i = path[i] ){
        ans.push_back(i);
        if( path[i] == c1 )
            break;
    ans.push_back(c1);
}

void print( vector<int> ans){
    for(int i = ans.size()-1; i>=0; i--){
        if( i != ans.size()-1 ) cout<<" -> ";
        cout<<ans[i];
    }
}


int main(){
    int n, m;
    cin>>n>>m;

    vector<int> vis(n,0);
    vector<vector<int>> g_len(n,vector<int>(n,inf) );
    vector<vector<int>> g_time(n, vector<int>(n,inf) );
    
    vector<int> dis(n,inf);
    vector<int> dis_patch(n,-1);
    vector<int> weight(n,0);
    vector<int> time(n,inf);
    vector<int> time_patch(n,-1);
    vector<int> node_num(n,0);

    vector<int> dis_ans, time_ans;
    while(m -- ){
        int a, b, c, d ,e;
        cin>>a >>b >> c>> d>> e;
        g_len[a][b] = d;
        g_time[a][b] = e;
        if( c == 0 ){
            g_len[b][a] = d;
            g_time[b][a] = e;
        }
    }
    cin>> c1>> c2;
    
    dis[c1] = 0;
    for(int i=0; i<n; i++){
        int u=-1, min = inf;
        for(int j=0; j<n; j++){
            if( vis[j] == 0 && dis[j] < min){
                min = dis[j];
                u = j;
            }
        }
        if( u == -1 )
            break;
        vis[u] = 1;
        
        for(int v=0; v<n; v++){
            if( vis[v] == 0 && g_len[u][v] != inf){
                if( dis[v] > dis[u] + g_len[u][v] ){
                    dis[v] = dis[u] + g_len[u][v];
                    dis_patch[v] = u;
                    weight[v] = weight[u] + g_time[u][v];
                }else if( dis[v] == dis[u] + g_len[u][v] && weight[u] + g_time[u][v] < weight[v] ){
                    weight[v] = weight[u] + g_time[u][v];
                    dis_patch[v] = u;
                }
            }
        }
    }
    

    time[c1] = 0;
    node_num[c1] = 1;
    fill(vis.begin(), vis.end(), 0);
    for(int i=0; i<n; i++){
        int u = -1, min = inf;
        for(int j=0; j<n; j++){
            if( time[j] < min && vis[j] == 0){
                min = time[j];
                u = j;
            }
        }
        if( u == -1)
            break;
        vis[u] = 1;
        for(int v=0; v<n; v++){
            if( vis[v] ==0  && g_time[u][v] != inf ){
                if( time[u] + g_time[u][v] < time[v] ){
                    time[v] = time[u] + g_time[u][v];
                    node_num[v] = node_num[u] +1;
                    time_patch[v] = u;
                }else if ( time[u] + g_time[u][v] == time[v] && node_num[u] + 1 < node_num[v] ){
                    node_num[v] = node_num[u] +1;
                    time_patch[v] = u;
                }
            }
        }
    }
    
    //无问题
    find_road(dis_ans, dis_patch);
    find_road(time_ans, time_patch);
    
    if( dis_ans == time_ans ){
        printf("Distance = %d ; Time = %d: ", dis[c2], time[c2]);
        print(dis_ans);
    }else{
        printf("Distance = %d: ", dis[c2]);
        print(dis_ans);
        cout<<endl;
        printf("Time = %d: ", time[c2] );
        print(time_ans);
    }
    return 0;
}