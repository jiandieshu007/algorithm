#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool judge( vector<int> ans){
    sort(ans.begin(), ans.end() );
    if( ans[2] - ans[1] < ans[0] && ans[2] - ans[0] < ans[1] && ans[0] + ans[1] > ans[2])return false;
    else return true;
}
vector<string> dic =  {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    vector<int> ans;
    for(int i=0; i<3; i++){
        string s;
        int t, x = 0;
        cin>>t;
        while( t--){
            cin>>s;
            for(int j=0; j<10; j++){
                if( dic[j] == s){
                    x *= 10;
                    x += j;
                }
            }
            
        }
        ans.push_back( x );
    }
    if( judge(ans) ) cout<<"NO";
    else cout<<"YES";
    return 0;
}