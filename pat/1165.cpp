#include<iostream>
#include<vector>
using namespace std;

struct node{
    int val, next;
}info[100000];


int main(){
    int root, n, k;
    cin>> root>> n>> k;
    vector<int> index, ans;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin>> a>> c>> c;
        info[a].val = b;
        info[a].next = c;
    }
    for(int i=root; i != -1; i = info[i].next ){
        index.push_back(i);
    }
    int t = n / k;
    for(int i=t*k; i>=0; i-=k){
        int j;
        if( i+k < n ) j = i+k;
        else j = n;
        for(int x = i; x <j; x++){
            ans.push_back( index[x] );
        }
    }

    for (int i = 0; i < ans.size(); i++){
        if( i + 1 < ans.size() ){
            info[ans[i]].next = ans[i + 1];
        }else
            info[ans[i]].next = -1;
    }
    for (root = ans[0]; root != -1; root = info[root].next ){
        if( root != ans[0] )
            cout << endl;
        printf("%05d, %d ", root, info[root].val);
        if( info[root].next != -1 )
            printf("%05d", info[root].next);
        else
            cout << "-1";
    }
    return 0;
}