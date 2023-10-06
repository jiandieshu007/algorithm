#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> relation_map(210,vector<int>(210,0));
vector<vector<int>> friends(210);

int main(){
    int n, m;
    cin>> n>> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a >> b;
        relation_map[a][b] = 1;
        relation_map[b][a] = 1;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    int k;
    cin>>k;
    for(int i=1; i<=k; i++){
        if( i != 1 ) cout<<endl;
        int t, f = 1;
        cin>>t;
        vector<int> info(t);
        for(int i=0; i<t; i++ ) cin>>info[i];
        
        for(int i=0; i<t; i++){
            for(int j = i+1; j<t; j++){
                if( relation_map[ info[i] ][ info[j] ] == 0 ){
                    f = 0;
                    break;
                }
            }
            if( f == 0 ) break;
        }
        if( f == 0){
            cout<<"Area "<<i<<" needs help.";
            continue;
        }
        
        bool flg = true;
        int cnt = 0, min = 250;
        vector<int> ff; // 存储应该有的人;
        vector<int> vis(210,0);
        for(int i=0; i<t; i++){
            if( i == 0 ){
                for (int j = 0; j < friends[info[i]].size(); j++)
                 {
                    ff.push_back( friends[info[i] ][j] );
                    cnt++;
                    vis[friends[info[i]][j]] = 1;
                }
            }else{
                for (int j = 0; j < friends[info[i]].size(); j++)
                {
                    if( vis[friends[info[i] ][j]] == 0 ){
                        ff.push_back( friends[info[i] ][j] );
                        cnt++;
                        vis[friends[info[i]][j]] = 1;
                    }
                }
            }
            vis[info[i]] = 1;
        }
        
        sort(ff.begin(), ff.end() );
        for(int i=0; i<ff.size(); i++){
            if( vis[ ff[i] ] == 0){
                flg = false;
                if( ff[i] < min ) min = ff[i];
            }
        }
        if( flg == true ){
            cout<<"Area "<<i<<" is OK.";
        }else{
            cout<<"Area "<<i<<" may invite more people, such as "<<min<<".";
        }
    }
    return 0;
}