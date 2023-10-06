#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

void get(vector<string> &s, unordered_map<char,string> dir, string d, int i, string &t){
    if( i < d.size() ){
        for(int j = i; j<dir[ d[i]-'0'].size(); j++){
            t += dir[ d[i] ][j];
            get(s,dir, d, i+1, t);
            t.pop_back();
        }
    }else s.push_back(t);
}

vector<string> letterCombinations(string digits) {
    unordered_map<char,string> letters{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    string t;
    vector<string> ans;
    get(ans, letters, digits, 0, t);
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = letterCombinations(s);
    return 0;
}