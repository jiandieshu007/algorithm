#include<iostream>
#include<vector>
using namespace std;
/*
int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        if( i ) cout<<endl;
        vector<vector<int>> vis(n,vector<int>(n,0) );
        int cnt = 0, k;
        cin>>k;
        vector<int> info(k);
        for(int j=0; j<k; j++ ) cin>>info[j];
        
        for(int p=0; p<k; p++){
            for(int j=0; j<g[ info[p] ].size(); j++){
                if( vis[ info[p] ][ g[info[p]][j] ] == 0){
                    cnt++;
                    vis[ info[p] ][ g[info[p]][j] ] = 1;
                    vis[ g[info[p]][j] ][ info[p] ] = 1;
                }
            }
        }
        if( cnt == m ) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main()
{
    int n, m, count = 0;
    cin>>n>>m;
    vector<vector<int>> g(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0; i<n; i++){
        if( g[i].size() ) count++;
    }
    int t;
    cin>>t;
    reverse()
    for(int i=0; i<t; i++){
        vector<int> vis(n,0);
        if( i ) cout<<endl;
        int cnt = 0, k;
        cin>>k;
        vector<int> info(k);
        for(int j=0; j<k; j++ ) cin>>info[j];
        
        for(int p=0; p<k; p++){
            if( g[ info[p] ].size() ){
                if( vis[ info[p] ] == 0 ) {
                    cnt++;
                    vis[ info[p] ] = 1;
                }
                for(int j=0; j <g[ info[p] ].size(); j++){
                    if( vis[ g[info[p] ][j] ] == 0 ){
                        cnt++;
                        vis[ g[info[p] ][j] ] = 1;
                    }
                }
            }
        }
        if( cnt == count ) cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}