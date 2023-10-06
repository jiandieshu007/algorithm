#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

void init( vector<int> &isprime){
    isprime[1] = 0;
    isprime[0] = 0;
    for(int i=2; i<=(isprime.size()/2); i++){
        if( isprime[i] ){
            for(int j = 2*i; j <=(isprime.size()/2) ; j+=i){
                isprime[j] = 0;
            }
        }
    }
}



int main(){
    int x, cnt = 0 ;
    cin>>x;
    vector<int> isprime(x+1, 1);
    init( isprime ); // 初始化质数表x`
    vector<int> p, p_ans; 
    for(int i=2; i<=x/2; i++ ){
        if( isprime[i] ){
            p.push_back(i);
        }
    }
    for(int i=0; i<p.size(); i++){
        for(int j = i; j<p.size(); j++){
            p_ans.push_back( p[i]*p[j] );
        }
    }
    sort(p_ans.begin(), p_ans.end() );
    for(int i=0; p_ans[i] <= x; i++){
        if( x % p_ans[i] == 0 ){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}