#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

struct alpha{
    vector<string> x;
};

vector<alpha> list(26);
vector<vector<int>> ans;
int main(){
    string s;
    // 读入字母
    for(int i=0; i<26; i++){
        alpha t;
        string k;
        for(int j=0; j<7;j++){
            cin >> k;
            t.x.push_back(k);
        }
        list[i] = t;
    }
    cin>>s;
    for(int i=0; i<s.size(); i++){
        vector<int> t;
        if( isupper(s[i]) ){
            int j = i;
            while( isupper(s[j]) ){
                t.push_back( s[j] -'A' );
                j++;
            }
            i = j;
            ans.push_back(t);
        }
    }
    
    for(int i=0; i<ans.size(); i++){
        if( i ) cout<<endl<<endl;
        for(int j=0; j<7; j++){
            for(int k=0; k<ans[i].size(); k++){
                if( k ) cout<<' ';
                cout<<list[ ans[i][k] ].x[j];
            }
            if( j != 6 )cout<<endl;
        }
    }

    
    return 0;   
}