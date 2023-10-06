#include<iostream>
#include<vector>
using namespace std;

    void dfs(string s, int a, int b, vector<string>& ans){
        if( a > b ) return ;
        if( a == 0 && b == 0 ){
            ans.push_back(s);
            return ;
        }
        if( a )
            dfs(s + '(', a - 1, b, ans);
        if( b > a )
            dfs(s + ')', a, b - 1, ans);
    } 

int main(){
    int n = 3;
    vector<string> ans;
    dfs("", n, n, ans);


    return 0;
}