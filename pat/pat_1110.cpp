#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int left, right;
};

void find( vector<int> v, int & root){
    for(int i=0; i<v.size(); i++){
        if( v[i] == 0 ){
            root = i;
            break;
        }
    }
}
int main(){
    int n, last, root, mid, i = 0;
    char a, b;
    bool flg = false;
    cin>>n;
    vector<node> tree(n);
    vector<int> hash(n,0);
    for(int i=0; i<n; i++){
        cin>> a >> b;
        if( a != '-'){
            tree[i].left = a-'0';
            hash[ a-'0' ] = 1;
        }else
            tree[i].left = -1;
        if( b != '-' ){
            tree[i].right = b -'0';
            hash[ b - '0' ] = 1;
        }else
            tree[i].right = -1;
    }
    find( hash, root);
    mid = (n -1)/ 2;
    queue<int> q;
    q.push(root);
    while( q.size( ) ){
        int t = q.front();
        last = q.back();
        q.pop();
        if( i< mid && (tree[t].left == -1 || tree[t].right == -1 ) ) flg = true;
        if( tree[t].left  != -1) q.push( tree[t].left );
        if( tree[t].right  != -1) q.push( tree[t].right );

        i++;
    }
    if( flg ) cout<<"NO "<<root;
    else cout<<"YES "<<last;
    return 0;
}