#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void Build( TreeNode* &root,vector<int>& preorder, vector<int>& inorder,int i1,int j1, int i2, int j2 ){ // i1 j1 to preorder i2 j2 to inorder 
    if( i1 <= j1 ){
        int k, len;
        for( k = i2; k<= j2; k++){
            if( inorder[k] == preorder[i1]  ) break; //找到位置
        }
        len = k-i2;
        root = (TreeNode*) new(TreeNode);
        root->val = preorder[i1];
        root->left = nullptr;
        root->right = nullptr;
        Build(root->left, preorder, inorder,i1+1, i1+len,i2,k-1 );
        Build(root->right,preorder,inorder, i1+len+1, j1, k+1, j2);
    }
}

int main(){
    vector<int> pre(5, 0);
    vector<int> in(5, 0);
    for (int i = 0; i < 5;i++)
        cin >> pre[i];
    for (int i = 0; i < 5; i++ )
        cin >> in[i];
    TreeNode *root = nullptr;
    Build(root, pre, in, 0, pre.size()-1, 0, in.size()-1);
    return 0;
}