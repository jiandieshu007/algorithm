#include<iostream>
#include<vector>
using namespace std;

const int m = 100000;
struct node{
    int val, next;
}info[m];

struct da{
    int postion, val;
};

int main(){
    int root, n , k;
    cin>> root>> n>> k;
    for(int i=0; i<n; i++){
        int t;
        cin>>t;
        cin>> info[t].val>> info[t].next;
    }
    vector<da> ans1;
    vector<da> ans2;
    vector<da> ans3;
    while( root != -1){
        da s;
        s.postion = root;
        s.val = info[root].val;
        if( info[root].val < 0 ){
            ans1.push_back(s);
        }else if( info[root].val <= k){
            ans2.push_back(s);
        }else ans3.push_back(s);
        root = info[root].next;
        
    }
    for(int i=0; i<ans2.size(); i++)
        ans1.push_back( ans2[i] );
    for(int i=0; i<ans3.size(); i++ )
        ans1.push_back( ans3[i] );
    
    for(int i=0; i<ans1.size(); i++){
        if( i ) cout<<endl;
        if( i+1 < ans1.size()) printf("%05d %d %05d", ans1[i].postion, ans1[i].val, ans1[i+1].postion);
        else printf("%05d %d -1", ans1[i].postion, ans1[i].val );
    }
    return 0;
}