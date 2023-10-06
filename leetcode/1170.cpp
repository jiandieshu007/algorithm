#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int query(string s){
    sort(s.begin(), s.end());
    int cnt = 1;
    for(size_t i=1; i<s.size() && s[i] == s[0]; ++i){
        cnt++;
    }
    return cnt;
}
vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    int n = words.size();
    vector<int> ans, t;
    for(size_t i=0; i<n; ++i){
        int k = query( words[i] );
        t.push_back(k);
    } 
    unordered_map<int,int> mp;
    sort(t.begin(), t.end() );
    for(int i=0; i<n; ++i){
        int j = i+1;
        while( j < n && t[j] == t[i] ){
            j++;
        }
        mp[ t[i] ] = j-i; // t[i] 1-10
        i = j - 1;
    }
    vector<int> yy(11,0);
    for(int i=1; i<11; ++i){
        yy[i] = yy[i-1] + mp[i];
    }
    for(size_t i=0; i<queries.size(); ++i){
        int k = query(queries[i] );
        ans.push_back( n-yy[k] );
    }
    return ans;
}

int main(){
    vector<string> q, w;
    int n, m;
    string s;
    cin >> n >> m;
    while( n--){
        cin >> s;
        q.push_back(s);
    }
    while( m--){
        cin >> s;
        w.push_back(s);
    }
    auto i = numSmallerByFrequency(q, w);
    return 0;
}