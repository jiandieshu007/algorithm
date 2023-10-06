#include<iostream>
#include<vector>
using namespace std;

int n, m;
const int M = 210;
vector<vector<int>> g(M, vector<int>(M,0));
vector<int> vis(M,0);
vector<int> info(M);

bool judge( int t){
    if( info[0] != info[ t-1] ) return false;
    fill(vis.begin(), vis.end(), 0);
    for(int i=1; i<t; i++){
        if( info[i] < 1 || info[i] > n ) return false; //非法结点
        if( g[ info[i] ][ info[i-1] ] ){ 
            if( vis[info[i]] ) return false;
            vis[ info[i] ] = 1;
        }else return false;
    }
    return true;
}

int main(){
    cin>>n >>m;
    while( m--){
        int a, b;
        cin>>a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    cin>>m;
    for(int i=0; i<m; i++){
        if( i ) cout<<endl;
        int t;
        cin>>t;
        for(int i=0; i<t; i++) cin>>info[i];
        
        if( t != n+1){
            cout<<"NO";
            continue;
        }

        
        if( judge(t) ) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}