#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int k;
    string s;
    vector<char> ans;
    unordered_map<char,int> hash;
    cin>>k>> s;
    for(int i=0; i<s.size(); i++){
        if( i +k -1 < s.size() ){
            if( hash[ s[i] ] == 1){
                continue;
            }else if( hash[ s[i] ] == 2){
                i += k - 1;
                continue;
            }
            for(int j = i+1; j< i+k; j++){
                if( s[j] != s[i] ){
                    hash[ s[i] ] = 1;
                    break;
                }
                if( j == i+k-1){
                    i += k-1;
                    ans.push_back( s[i] );
                    hash[s[i]] = 2;
                    break;
                }
            }
        }
        else hash[i] = 1;
    }
    for(int i=0; i<ans.size(); i++) cout<<ans[i];
    cout<<endl;
    for(int i=0; i<s.size(); i++){
        cout<<s[i];
        if( hash [ s[i] ] == 1 ) continue;
        else i += k-1;
    }
    return 0;
}