#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    vector<int> child;
    int depth;
}tree[100010];  

int main(){
    int n, t, s, min = 100010, ans = 0;
    double price, r;

    cin>>n>>price>>r;
    for(int i=0; i<n; i++){
        cin>>t;
        for(int j=0; j<t; j++){
            cin>>s;
            tree[i].child.push_back(s);
        }
    }
    //初始化 树
    queue<int> q;
    tree[0].depth = 0;
    q.push(0);
    while( q.size() ){
        t = q.front();
        q.pop();
        for (int i = 0; i < tree[t].child.size(); i++){
            q.push(tree[t].child[i]);
            tree[tree[t].child[i]].depth = tree[t].depth + 1;
        }
    }
    // 找到最小深度
    for(int i=0; i<n ; i++){
        if( tree[i].child.size() == 0 && tree[i].depth < min ) min =  tree[i].depth;
    }

    q.push(0);
    while( q.size() ){
        t = q.front();
        q.pop();
        for(int i=0; i<tree[t].child.size(); i++){
            q.push( tree[t].child[i] );
        }
        if( tree[t].child.size() == 0 &&  tree[t].depth == min ) ans++;
    }
    price *= ( 1+ r/100 );
    printf("%.4lf %d", price, ans);
    return 0;
}