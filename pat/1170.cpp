#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int id, specie;
};
const int inf = 1000000;
const int m = 510;
vector<vector<int>> g(m, vector<int>(m,inf) );
vector<node> info(m);

bool cmp(node a, node b){
    if( a.specie != b.specie ) return a.specie < b.specie;
    else return a.id < b.id;
}

bool judge(vector<node> info ){
    sort(info.begin(), info.end(), cmp);
    for(int i=0; i<info.size(); i++){
        int j;
        for(j = i+1; j<info.size(); j++){
            if( info[j].specie != info[i].specie ) break;
        }
        for (int x = i;  x < j; x++)
        {
            for(int y = x+1; y<j; y++ ){
                if( g[ info[x].id][ info[y].id] != inf ) return false;
            }
        }
        i = j - 1;
    }
    return true;
}

int main(){
    int n, r, k;
    cin>>n >>r >>k;
    while(r--){
        int a, b;
        cin>>a>>b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    int t;
    cin>>t;
    for(int i=0; i< t; i++){
        if( i ) cout<<endl;
        vector<int> vis(m,0);
        vector<node> info;
        int cnt = 0;
        for(int i=1; i<=n; i++ ){
            node a;
            a.id = i;
            cin>>a.specie;
            if( vis[a.specie] == 0 ){
                cnt++;
                vis[ a.specie ] = 1;
            }
            info.push_back(a);
        }
        if( cnt > k ){
            cout<<"Error: Too many species.";
            continue;
        }else if( cnt < k ){
            cout<<"Error: Too few species.";
        }else{
            if( judge(info) ) cout<<"Yes";
            else cout<<"No";
        }
    }
    return 0;
}