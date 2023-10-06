#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

const int N = 100010;
struct node{
    int val, next;
};


int main(){
    int begin, n, t, pre;
    bool flg = true;
    vector<node> v(N);
    vector<int> remove;
    unordered_map<int,int> Hash;
    cin>>begin>>n;

    for(int i=0; i<n; i++){
        cin>>t;
        cin>>v[t].val>>v[t].next;
    }
    
    for(int i=begin, j=0; j<n ; j++ ){
        if( Hash[  abs(v[i].val) ] == 0 ){
            Hash[ abs(v[i].val) ] = 1;
            pre = i;
            i = v[i].next;
            
        }else{
            remove.push_back(i);
            v[pre].next = v[i].next;
            i = v[i].next;
        }
    }
    
    // 输出
    for(int i=0; i<n-remove.size(); i++){
        if( flg == true ) flg = false;
        else cout<<endl;
        printf("%05d %d ", begin, v[begin].val);
        if( v[begin].next == -1 ) cout<<-1;
        else printf("%05d", v[begin].next);
        begin = v[begin].next;
    }
    for(int i=0; i<remove.size(); i++){
        printf("\n%05d %d ",  remove[i], v[remove[i]].val);
        if( i == remove.size() -1 ) cout<<"-1";
        else printf("%05d", remove[i+1]);
    }
    return 0;
}