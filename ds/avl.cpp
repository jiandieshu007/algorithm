#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct node{
    int val;
    node *left, *right;
};

int getH( node*root){
    if( root == nullptr)
        return 0;
    return max(getH(root->left), getH(root->right)) + 1;
}
void R(node*& root){
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    root = t;
}

void L(node*& root){
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    root = t;
}

void insert(node*& root, int k){
    if( root == nullptr){
        root = new node();
        root->val = k;
        root->left = root->right = nullptr;
    }else if( k > root->val){
        insert(root->right, k);
        if( getH(root->right) - getH(root->left) == 2 ){
            if( k > root->right->val){
                L(root);
            }else{
                R(root->right);
                L(root);
            }
        }
    }else{
        insert(root->left, k);
        if( getH(root->right) - getH(root->left) == -2 ){
            if( k < root->left->val){
                R(root);
            }else{
                L(root->left);
                R(root);
            }
        }
    }
}

node* build( int n){
    node *root = nullptr;
    while( n--){
        int t;
        cin >> t;
        insert(root, t);
    }
    return root;
}


int main(){
    int n;
    bool flg = true;
    cin >> n;
    node *root = build(n); // 构造avl
    queue<node *> q;
    n--;
    q.push(root);
    while(q.size()){
        node *t = q.front();
        q.pop();
        cout << t->val << ' ';
        if( t->left ){
            q.push(t->left);
            n--;
        }else if( n ){
            flg = false;
        }
        if( t->right ){
            q.push(t->right);
            n--;
        }else if( n ){
            flg = false;
        }
    }
    cout << endl;
    if( flg )
        cout << "YES";
    else
        cout << "NO";
    return 0;
}