#include<iostream>
#include<vector>
using namespace std;

const int N = 1010;
vector<vector<int>> graph(N);

void dfs( int i,int check, vector<int> & hash){
    for(int j=0; j<graph[i].size(); j++ ){
        if( graph[i][j] != check){
            hash[ graph[i][j] ] = 1;
            dfs( graph[i][j], check, hash );
        }
    }
}
int main(){
    int n, m , k, a, b, check ;
    cin>>n >> m>> k;
    while( m -- ){
         cin>> a>> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<k; i++ ){
        if( i ) cout<<' ';
        int res = 0;
        vector<int> hash(n+1,0);
        cin>>check;
        for(int j=1; j<=n; j++){
            if( hash[j] == 0 && j != check ){
                hash[j] = 1;
                dfs(j, check, hash);
                res++;
            }
        }
        cout<<res-1;
    }
    return 0;
}