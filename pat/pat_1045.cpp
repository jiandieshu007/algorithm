#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


int main(){
    int n, m, k, index = 1, ans=0;
    cin>>n>>m ; 
    unordered_map<int,int> mapp;
    vector<int> s;
    while( m -- ){
        int t;
        cin>>t;
        mapp[t] = index++;
    }
    cin>>m;
    while( m--){
        int t;
        cin >> t;
        if( mapp[t] ) s.push_back(t);
    }
    
    for(int i=0; i<s.size(); i++){
        int t = 1;
        for(int j=i+1; j<s.size(); j++){
            if( mapp[ s[j] ] > mapp[s[j-1] ]) t++;
        }
        if( t > ans ) ans = t;
    }
    cout<<ans;
    return 0;
}