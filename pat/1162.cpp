#include<iostream>
#include<vector>
using namespace std;

struct node{
    string val;
    int left, right;
};


void postorder( vector<node> info, int root){
    if( root != -1){
        cout<<"(";
        if( info[root].left == -1 && info[root].right != -1){
            cout<<info[root].val;
            postorder(info, info[root].right);
        }else{
            postorder( info, info[root].left);
            postorder( info, info[root].right ) ;
            cout<<info[root].val;
        }
        cout<<")";
    }
}
int main(){
    int n;
    cin>>n;
    vector<node> info(n+1);
    vector<int> vis(n+1,0);
    for(int i=1; i<=n; i++){
        cin>>info[i].val >> info[i].left >> info[i].right;
        if( info[i].left != -1) vis[ info[i].left ] = 1;
        if( info[i]. right != -1) vis[ info[i].right ] = 1;
    }
    int root;
    for(int i=1; i<=n; i++){
        if( vis[i] == 0 ){
            root = i;
            break;
        }
    }
    postorder( info, root);
    return 0;
}