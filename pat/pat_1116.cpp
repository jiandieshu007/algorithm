#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;


bool is_prime(int t){
    if( t == 1) return false;
    if( t == 2 ) return true;
    for(int i=2; i<t; i++){
        if( t%i == 0 ) return false;
    }
    return true;
}
int main(){
    int n;
    unordered_map<int,int> rank;
    vector<int> hash(10010, 0);
    cin>>n;
    for(int i=1; i<=n; i++){
        int t;
        cin>>t;
        rank[t] = i;
    }
    cin>>n;
    for(int i=0; i<n; i++){
        if( i ) cout<<endl;
        int t;
        cin>>t;
        if( rank[t] && hash[t] == 0 ){
            if( rank[t] == 1 ){
                printf("%04d: Mystery Award", t);
            }else if( is_prime( rank[t] ) ){
                printf("%04d: Minion",t);
            }else{
                printf("%04d: Chocolate", t);
            }
            hash[t] = 1;
        }else if( rank[t] && hash[t] == 1 ){
            printf("%04d: Checked", t);
        }else{
            printf("%04d: Are you kidding?", t);
        }
    }
    return 0;
}