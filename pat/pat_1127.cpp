#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int val;
    node *left, *right;
};


void build(node*&root, vector<int> in, vector<int>post, int i1, int j1, int i2, int j2){
    if( i1 <= j1){
        int k;
        for(k=i1; k<=j1; k++ ){
            if( in[k] == post[j2] ) break;
        }
        root = new node();
        root->val = post[j2];
        root->left = root->right = nullptr;
        build(root->left, in, post, i1, k-1, i2, i2+k-i1-1);
        build(root->right, in, post, k+1, j1, i2+k-i1,j2-1);
    }
}
void sqe(vector<int> t, int s, int k){
    for (int i = s; i <= s + k - 1; i++){
        if( i )
            cout << ' ';
        cout << t[i];
    }
}

void reseq( vector<int> t, int s, int k){
    for (int i = s + k - 1; i >= s; i--){
        if( i )
            cout << ' ';
        cout << t[i];
    }
}
int main(){
    int n, index = 1, a = 1, c = 0;
    cin>>n;
    vector<int>in(n);
    vector<int>post(n);
    vector<int> ans(n,0);
    vector<int> ss;
    for(int i=0; i<n; i++ ) cin>>in[i];
    for(int i=0; i<n; i++ ) cin>>post[i];
    
    node* root = nullptr;
    build(root, in, post, 0, n-1, 0, n-1);
    
    ans[0] = 1;
    queue<node*> q;
    q.push(root);
    while( q.size() ){
        node* t = q.front();
        q.pop();
        a--;
        ss.push_back(t->val);
        if( t->left ){
            q.push( t->left);
            c++;
        }
        if( t->right ){
            q.push(t->right);
            c++;
        }
        if( a == 0 ){
            ans[index++] = c;
            a = c;
            c = 0;
        }
    }
    int t = 0;
    for(int i=0; ans[i] ; i++){
        if( i%2 ){
            seq(ss, t, ans[i]);
        }else{
            reseq(ss, t, ans[i]);
        }
        t += ans[i];
    }
    return 0;
}