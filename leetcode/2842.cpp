#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int countKSubsequencesWithMaxBeauty(string s, int k) {
    long long ans = 1, mod = 1e9+7;
    long long ret = 0;
    unordered_map<char,int> ump;
    vector<int> v;
    for(size_t i=0; i<s.size(); ++i){
        ump[ s[i] ]++;
    }  
    if( k > (int)ump.size() ) return 0;
    for( auto & [ x, y] : ump ){
        v.push_back(y);
    }
    sort(v.begin(), v.end(), greater<int>() );
    size_t left = k-1, right = k;
    while( left >= 0 && v[left] == v[k-1] ) left--;
    while( right < v.size() && v[right] == v[k-1] ) right ++;

    for(int i=0; i<k; ++i ){
        ans *= v[i];
        ans %= mod;
    }
    int len = right - left - 1;
    while( len-- ){
        ret += ans ;
        ret %= mod;
    }
    return ret;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << countKSubsequencesWithMaxBeauty(s, k);
    return 0;
}