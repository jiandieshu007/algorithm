#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<vector>
using namespace std;

void fenjie( int &n, int &m){
    m = sqrt(n) + 1;
    while( n%m ){
        m--;
    }
    n = n/m;
}

bool cmp( int a, int b){
    return a>= b;
}
int main(){
    int n, m, index = 0 , flg = 1, i=0, j=0;
    cin>>n;
    vector<int> k(n);
    for(int i=0; i<n; i++){
        cin>>k[i];
    }
    unordered_map<int,bool> hash;
    sort( k.begin(), k.end(), cmp );
    fenjie(n, m);
    vector<vector<int>> ans( m, vector<int>( n) );
    while( index < k.size() ){
         if( flg == 1){
             while( j < n ){
                 int t = 100 * i + j;
                 if( hash[t] == 0 ){
                     ans[i][j++] = k[index++];
                     hash[t] = 1;
                 }else break;
             }
             j--;
             i++;
             flg = 2;
         }else if( flg == 2){
             while( i < m ){
                 int t = 100 * i + j;
                 if( hash[t] == 0 ){
                     ans[i++][j] = k[index++];
                     hash[t] = 1;
                 }else break;
             }
             i--;
             j--;
             flg = 3;
         }else if( flg == 3){
             while( j >= 0  ){
                 int t = 100 * i + j;
                 if( hash[t] == 0 ){
                     ans[i][j--] = k[index++];
                     hash[t] = 1;
                 }else break;
             }
             i--;
             j++;
             flg = 4;
         }else{
             while( i >= 0 ){
                 int t = 100 * i + j;
                 if( hash[t] == 0 ){
                     ans[i--][j] = k[index++];
                     hash[t] = 1;
                 }else break;
             }
             i++;
             j++;
             flg = 1;
         }
    }
    
    for(int i=0; i<m; i++){
        if( i ) cout<<endl;
        for(int j=0; j<n; j++){
            if( j ) cout<<' ';
            cout<<ans[i][j];
        }
    }
    return 0;
}