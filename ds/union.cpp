#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct node{
    int id, num;
    node(){
        id = 0;
        num = 0;
    };
};
int father[10010];

int find( int x )
{
    while( father[x] != x )
        x = father[x];
    return x;
}

int Union( int x, int y){
    int fx = find(x);
    int fy = find(y);
    if( fx > fy )
        father[fx] = fy;
    else if( fy > fx )
        father[fy] = fx;
}

bool cmp( node a, node b){
    if( a.num != b.num )
        return a.num > b.num;
    else
        return a.id < b.id;
}

int main(){
    int n, m;
    cin >> n;
    vector<vector<int>> dic(n);
    vector<node> ans(10010);
    vector<int> vis(10010, 0);
    for (int i = 0; i < 10010; i++)
        father[i] = i;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> t;
            vis[t] = 1;
            dic[i].push_back(t);
        }
        for (int j = 1; j < m; j++)
        {
            Union(dic[i][0], dic[i][j]);
        }
    }
    for (int i = 0; i < n; i++ ){
        if( dic[i].size() ){
            int j = find( dic[i][0] );
            ans[j].id = j;
        }
    }
    for (int i = 0; i < 10010; i++){
        if( vis[i] )
            ans[find(i)].num++;
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++){
        if( ans[i].num == 0 )
            break;
        cout << ans[i].id << ' ' << ans[i].num << endl;
    }
    return 0;
}