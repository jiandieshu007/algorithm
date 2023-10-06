#include<iostream>
using namespace std;

typedef struct nd{
    nd(){
        sum = 0;
        left = right = nullptr;
    }
    int sum;
    nd *left, *right;

} *node;

class dst{
public:
    node root;
    int size;
    dst(int sz){
        root = new nd();
        size = sz;
    }
    void add(int i,int v){
        add(root, 1, size, i, v);
    }
    void add(node root, int le, int ri, int i,int v){
        if( le==ri ){
            root->sum += v;
        }
        int mid = (le + ri) >> 1;
        if( i < mid){
            if( root->left == nullptr){
                root->left = new nd();
            }
            add(root->left, 1, mid, i, v);
        }else{
            if( root->right == nullptr){
                root->right = new nd();
            }
            add(root->right, mid, size, i, v);
        }
        root->sum = (root->left ? root->left->sum : 0) + (root->right ? root->right->sum : 0);
    }
    int query(int s, int r){
        return query(root, 1, size, s, r);
    }
    int query(node root, int l, int r, int s, int e){
        if( root == nullptr )
            return 0;
        if( s<=l && e>=r ){
            return root->sum;
        }
        int mid = (l + r) >> 1;
        if( e <= mid){
            return query(root->left, 1, mid, s, e);
        }else if( s >= mid){
            return query(root->right, mid, size, s, e);
        }else{
            return query(root->left, l, mid, s, mid) + query(root->right, mid, size, mid, e);
        }
    }
};

int main(){
    cout << "yes";
    return 0;
}