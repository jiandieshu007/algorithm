#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

string evaluate(string s, vector<vector<string>>& knowledge) {
    int j = 0; // 初始化 后指针位置
    string ans = "", t;
    for(int i=0; i<s.size(); i++){
        if( s[i] == '(' ){
            if( i-j-1 >0) ans += s.substr(j+1, i-j-1);
            for( j =i; j<s.size(); j++){
                if( s[j] == ')' )
                    break;
            }
            t = s.substr(i+1, j-i-1);
            for(int k=0; k<knowledge.size(); k++){
                if( t == knowledge[k][0] ){
                    ans +=knowledge[k][1];
                    break;
                }
                if( k == 1 ) ans += '?';
            }
            i = j;
        }
    }
    if( j != s.size() ) ans += s.substr(j+1, s.size() - j);
    return ans;
}

int main(){
    string s;
    cin >> s;
    vector<vector<string>> t;
    cout << evaluate( s, t);
    return 0;
}