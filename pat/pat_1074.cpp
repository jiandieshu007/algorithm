
#include<iostream>
#include<vector>
using namespace std;

struct node{
    int val, next;
}list[100010];

int main(){
    int root, n, k, last;
    cin>>root>>n>>k;
    for(int i=0; i<n; i++){
        int a , b, c;
        cin>> a >> b >> c;
        list[a].val = b;
        list[a].next = c;
    }
    vector<int> li; // 从根开始 每个结点的位置
    for(int i= root;  ; i = list[i].next ){
        li.push_back(i);
        if( list[i].next == -1 ) break;
    }
    root =  li[k-1] ;
    for(int i=0; i+k < n; i += k){
        last = list[ li[i+k-1] ].next;
        for(int j=i+k-1; j>i; j--){
            list[ li[j] ].next = li[j-1];
        }
        list[ li[i] ].next = last;
        if( i ) list[ li[i] ].next = li[i+k];


    }
    //打印
    for(int i= root; ; i = list[i].next ){
        if( i != root ) cout<<endl;
        printf("%05d %d ", i, list[i].val);
        if( list[i].next != -1 ){
            printf("%05d", list[i].next );
        }else{
            printf("%d", list[i].next);
            break;
        }
    }
    return 0;
}