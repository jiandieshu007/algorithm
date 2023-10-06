#include<iostream>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;

const int inf = 10000000;
struct node{
    double average, index, min_max;
};

bool cmp( node a, node b){
    if( a.min_max != b.min_max ){
        if( a.average != b.average ) return a.average < b.average;
        else return a.index < b.index;
    }else return a.min_max > b.min_max;
}
int main(){
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> g( n+m, vector<int>(n+m, inf) );
    vector<vector<int>> dis(m,vector<int>(n+m, inf) );        
    vector<int> vis(n+m,0 );
    while( k -- ){
        string a, b;
        int c, d , e;
        cin>>a >>b>>c;
        if( a[0] == 'G' ){
            d = a[1]-'0'-1 +n;
        }else d = stoi(a) -1;
        if( b[0] == 'G' ){
            e = b[1] -'0' -1 +n;
        }else e = stoi(b) -1;
        g[d][e] = c;
        g[e][d] = c;
    }
    
    for(int i=0; i<m; i++){
        fill(vis.begin(), vis.end(), 0);
        dis[i][i+n] = 0;
        for(int j = 0; j <n+m; j++){
            int u = -1, min = inf;
            for(int k=0; k<n+m; k++){
                if( min > dis[i][k] && vis[k] == 0){
                    min = dis[i][k];
                    u = k;
                }
            }
            if( u == -1 ) break;
            vis[u] = 1;
            for(int v=0; v<n+m; v++ ){
                if( g[u][v] != inf && vis[v] == 0 ){
                    if( dis[i][u] + g[u][v] < dis[i][v] ){
                        dis[i][v] = dis[i][u] + g[u][v];
                    }
                }
            }
        }
    }
    
    vector<node> ans;
    for(int i=0; i<m; i++){
        double sum = 0, min = inf;
        for(int j =0; j<n; j++){
            if( dis[i][j] < min )
                min = dis[i][j];
            if( dis[i][j] > d ){
                break;
            }else sum += dis[i][j];
            if( j == n-1 ){
                node t;
                t.index = i;
                t.average = sum /n;
                t.min_max = min;
                ans.push_back(t);
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if( ans.size() ){
        double sum = 0;
        int cnt = 0, truth;
        bool flg = true;
        for(int i=0; i<ans.size(); i++ ){
            if( ans[i].min_max == ans[ ans.size()-1 ].min_max ){
                if( flg == true  ){
                    truth = i;
                    flg = false;
                }
                sum += ans[i].average;
                cnt++;
            }
        }
        cout<<'G'<< ans[truth].index+1<<endl;
        cout<<ans[truth].min_max<<' '<< sum/cnt;
        return 0;
    }
    cout<<"No Solution";
    return 0; 
}