#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Data{
    int id, cnt, v;
};

struct node{
    int id, people;
    double ave, num, val;
    node(){
        id = 0;
        people = 0;
        num = 0;
        ave = 0;
        val = 0;
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
    if( a.ave != b.ave )
        return a.ave > b.ave;
    else
        return a.id < b.id;
}

int main(){
    int n, m, count = 0;
    cin >> n;
//    vector<vector<int>> dic(n);
    vector<Data> dic(n);
    vector<node> ans(10010);
    vector<int> vis(10010, 0);
    for (int i = 0; i < 10010; i++)
        father[i] = i;
    for (int i = 0; i < n; i++)
    {
        vector<int> info;
        int b,c,k, t;
        cin>>dic[i].id >> b>> c >> k;
        info.push_back( dic[i].id );
        if( b != -1 ) info.push_back(b);
        if( c != -1 ) info.push_back(c);
        for (int j = 0; j < k; j++)
        {
            cin >> t;
            info.push_back(t);
        }
        vis[ info[0] ] = 1;
        for (int j = 1; j < info.size(); j++)
        {
            vis[ info[j] ] = 1;
            Union(info[j], info[0]);
        }
        cin>>dic[i].cnt>>dic[i].v;
    }
    for (int i = 0; i < n; i++ ){
        int j = find( dic[i].id );
        ans[j].id = j;
        ans[j].num += dic[i].cnt;
        ans[j].val += dic[i].v;
    }
    for (int i = 0; i < 10010; i++){
        if( vis[i] )
            ans[find(i)].people++;
    }
    for(int i=0; i<ans.size(); i++){
        if( ans[i].people ) ans[i].ave = ans[i].val/ans[i].people;
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i=0; i<ans. size(); i++){
        if( ans[i].num == 0 ) break;
        count++;
    }
    cout<<count<<endl;
    for(int i=0; i<count; i++){
        if( i  ) cout<<endl;
        printf("%04d %d %.3f %.3f", ans[i].id, ans[i].people, ans[i].num/ans[i].people, ans[i].ave);
    }
    return 0;
}