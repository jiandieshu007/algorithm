#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

void dfs_( vector<vector<int>> & graph, int i, vector<int> & hash){
    if( i < hash.size() ) hash[i] = 1 ;
    for(int j=0; j< graph[i].size(); j++){
        if( hash[ graph[i][j] ] == 0 ){
            dfs_( graph,graph[i][j], hash );
        }
    }
}

int level( vector<vector<int>> &graph, int i, int n){\
    int pre = 1, bac=0, len = 0;
    vector<int> hash(n+1,0);
    queue<int> q;
    q.push(i);
    hash[i] = 1;
    while( q.size() ){
        int t= q.front();
        for(int j=0; j<graph[t].size(); j++){
            if( hash[ graph[t][j] ] == 0  ){
                q.push( graph[t][j] );
                hash[ graph[t][j] ] = 1;
                if( pre ) bac ++;
            }
        }
        q.pop();
        pre--;
        if( pre == 0 ){
            pre = bac;
            bac = 0;
            len++;
        }
    }
    return len;
}

struct node{
    int start, len;
};

bool cmp( node a, node b){
    if( a.len != b.len ) return a.len>b.len;
    else return a.start < b.start;
} 

int main(){
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    vector<node> ans;
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // 判断是否联通 
    int cnt = 0;
    vector<int> hash(n+1, 0);
    for(int i=1; i<=n; i++){
        if( hash[i] == 0 ){
            dfs_(graph, i, hash );
            cnt ++;
        }
    }
    if( cnt > 1 ){
        cout<<"Error: "<<cnt<<" components";
        return 0;
    }
    for(int i=1; i<=n; i++){
        node a;
        a.start = i;
        a.len = level( graph, i,  n );
        ans.push_back(a);
    }
    sort(ans.begin(), ans.end(), cmp );
    
    cout<<ans[0].start;
    for(int i=1; i<n; i++){
        if( ans[i].len == ans[i-1].len ) cout<<endl<<ans[i].start;
        else break;
    }
    return 0;
}