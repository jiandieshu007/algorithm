#include<iostream>
#include<vector>
using namespace std;




bool judge( int s, int d, vector<vector<int>> g){
    int n = g.size();
    vector<int> canReach(n,0);
    vector<int> vis(n,0);
    canReach[s] = 1;
    for(int i=0; i<n; i++){
        int u = -1;
        for(int j=0; j<n; j++){
            if( canReach[j] && vis[j] == 0){
                u = j;
                break;
            }
        }
        if( u == -1 ) break;
        vis[u] = 1;
        for(int v =0; v<n; v++){
            if( g[u][v] && vis[v] == 0){
                canReach[v] = 1;
                if( v == d ) return true;
            }
        }
    }
    return false;
}


int main(){
    int n, k;
    cin>>n >>k;
    vector<vector<int>> g(n, vector<int>(n,0) );

    while(--n){
        int a, b;
        cin>>a >> b;
        g[a][b] = 1;
    }

    for(int i=0; i<k; i++){
        int a, b;
        cin>>a >>b;
        if( i ) cout<<endl;
        if( judge( a, b, g) || judge(b,a,g) ) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}   