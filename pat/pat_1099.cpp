#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int index = 0 ;
struct node{
    int val;
    int left, right;
};
void pre( vector<node> & k, vector<int> &t, int i, int n){
    if( i<n && i >= 0){
        pre(k,t, k[i].left, n);
        k[i].val = t[index++];
        pre(k,t,k[i].right,n);
    }
}
int main(){
    int n, tmp;
    cin>>n;
    vector<node> k(n);
    vector<int> t(n);
    for(int i=0; i<n; i++){
        k[i].val = 0;
        cin>> k[i].left>> k[i].right;
    }
    for(int i=0; i<n; i++ ) cin>>t[i];
    sort(t.begin(), t.end());
    stack<int> s;
    s.push(0);
    pre( k, t, 0, n);
    queue<int> q;
    q.push(0);
    while( q.size() ){
        tmp = q.front();
        if( k[tmp].left != -1 ) q.push( k[tmp].left );
        if( k[tmp].right != -1 ) q.push( k[tmp].right );
        q.pop();
        if( tmp != 0 ) cout<<' ';
        cout<<k[tmp].val;
    }
    return 0;
}