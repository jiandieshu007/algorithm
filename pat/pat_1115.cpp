#include<iostream>
using namespace std;

int max_h = -1;
struct node{
    int w, height;
    node *left, *right;
};

void insert( node* & root, int t, int h){
    if( root == nullptr ){
        root = (node*) new node;
        root -> w = t;
        root -> height = h;
        if( h > max_h ) max_h = h;
        root->left = nullptr;
        root->right = nullptr;
    }else{
        if( t <= root->w ) insert( root->left, t, root->height+1);
        else insert( root->right, t, root->height+1);
    }
}

node* build_Tree( int n){
    node* root = nullptr;
    while( n -- ){
        int t;
        cin>>t;
        insert( root, t, 0);
    }
    return root;
}

void in(node* root){
    if( root ){
        in(root->left);
        cout << root->w<<' ';
        in(root -> right);
    }
}

int main(){
    int n, n1=0, n2=0;
    cin >> n;
    node* root = build_Tree( n ) ;
    return 0;
}