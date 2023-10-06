#include<iostream>
#include<vector>
using namespace std;

struct node{
    int val, next;
}info[100010];


int main(){
    int root1, root2, n;
    cin>>root1 >> root2>> n;
    while( n--){
        int a;
        cin>>a;
        cin>>info[a].val >> info[a].next;
    }
    
    int cnt1 = 0, cnt2 = 0;
    vector<int> info1;
    vector<int> info2;
    for(int i=root1; i != -1; i = info[i].next){
        cnt1++;
        info1.push_back(i);
    }
    for(int i=root2; i!=-1; i= info[i].next ){
        cnt2++;
        info2.push_back(i);
    }
    
    if( cnt1 >= 2*cnt2){
        for(int i=1, j = cnt2-1 ; j>=0 , i<cnt1; i+=2, j-- ){
            info[ info2[j] ].next = info[ info1[i] ].next;
            info[ info1[i] ].next = info2[j];
        }
        
        for(int i=root1; i!=-1; i = info[i].next){
            if( i != root1 ) cout<<endl;
            printf("%05d %d ", i, info[i] );
            if( info[i].next != -1 ) printf("%5d",info[i].next);
            else cout<<"-1";
        }
    }else{
        for(int i=1, j = cnt1-1 ; j>=0 , i<cnt2; i+=2, j-- ){
            info[ info1[j] ].next = info[ info2[i] ].next;
            info[ info2[i] ].next = info1[j];
        }
        
        for(int i=root2; i!=-1; i = info[i].next){
            if( i != root1 ) cout<<endl;
            printf("%05d %d ", i, info[i] );
            if( info[i].next != -1 ) printf("%5d",info[i].next);
            else cout<<"-1";
        }
    }
    return 0;
}