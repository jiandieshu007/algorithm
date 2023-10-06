#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> hash_table;
        int n = s.size();
        for(int i=0;i < (int)wordDict.size(); i++ ){
            hash_table[ wordDict[i] ] = 1;
        }
        vector<int> dp(n,0);
        for(int i=0; i<n ; i++){
            if( hash_table[ s.substr(0,i+1)] ) dp[i] = 1;
        }
        for(int i=0; i<n; i++){
            if( dp[i] ){
                for(int j=i+1; j<n; j++){
                    if( hash_table[ s.substr(i+1,j-i) ] ) dp[j] = 1;
                }
            }
        }
        return dp[n-1] ;
    }

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<string> dict(n);
    for (int i = 0; i < n; i++){
        cin>>dict[i];
    }
    cout << wordBreak(s, dict);
    return 0;
}