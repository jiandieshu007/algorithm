#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


    int Leetcode(vector<string>& words) {
        int n = words.size(), ans = 0, cnt = 0, count = 0;
        string key = "helloleetcode";
        unordered_map<char,int> need;
        vector<int> v(n,0);
        for(int i=0; i<key.size(); ++i ) need[ key[i] ]++;

        while(cnt < n && count != 13){
            for(int i=0; i<n; ++i){
                if( words[i].size() == 0 || v[i] == words[i].size() ) continue;
                int j = v[i];
                cout << words[i][j] << endl;
                while( j<words[i].size() && need.find( words[i][j]) != need.end() && need[words[i][j]] ){
                    cout << words[i][j];
                    need[words[i][j]]--;
                    count++;
                    ans += v[i] * ( words[i].size() - v[i] - 1);
                    words[i].erase(words[i].begin()+v[i]);
                }
                cout << endl;
                v[i]++;
                if(  words[i].size() == 0 || v[i] == words[i].size() || j == words[i].size() ) cnt++;
            }
        }
        return count == 13 ? ans : -1;
    }

    int main(){
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; ++i )
            cin >> v[i];
        cout << Leetcode(v);
        return 0;
    }