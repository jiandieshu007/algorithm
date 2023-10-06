#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int l;
const int m = 1010;
vector<vector<int>> g( m );

void dfs( int id, int &cnt, vector<int> &hash, int level){
    for(int i=0; i<g[id].size(); i++){
        if( hash[ g[id][i] ] == 0 ){
            if( level+1 <= l){
                cnt++;
                hash[ g[id][i] ] = 1;
            }
            if( level+1 <= l ) dfs( g[id][i], cnt, hash, level+1);
        }
    }
}
int main(){
    int n, id;
    cin>>n>>l;
    for(int i=1; i<=n; i++){
        int a, b;
        cin>>a;
        while( a--){
            cin>>b;
            g[b].push_back(i);
        }
    }
    cin>>n;
    while( n -- ){
        cin>>id;
        int cnt = 0, pre=1, bck = 0, le = l;
        vector<int> hash( m, 0);
        hash[id] = 1;
        queue<int> q;
        q.push(id);
        while( q.size() && le ){
            int t = q.front();
            for(int i=0; i<g[t].size(); i++){
                if( hash[ g[t][i] ] == 0 ){
                    cnt++;
                    hash[ g[t][i] ] = 1;
                    q.push( g[t][i] );
                    bck ++;
                }
            }
            q.pop();
            pre--;
            if( pre == 0 ){
                pre = bck;
                le--;
                bck = 0;
            }
        }
        cout<<cnt;
        if( n ) cout<<endl;
    }
    return 0;
}