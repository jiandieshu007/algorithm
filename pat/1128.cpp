#include<iostream>
#include<vector>
using namespace std;



void set_val( vector<vector<int>> & g, int row, int col){
    for(int i=0; i<g.size(); i++){
        g[row][i] = 1;
        g[i][col] = 1;
    }
    for(int i=row, j = col; i<g.size() && j < g.size(); i++, j++) g[i][j] = 1;
    for(int i=row, j = col; i<g.size() && j < g.size(); i++, j--) g[i][j] = 1;
    for(int i=row, j = col; i<g.size() && j < g.size(); i--, j++) g[i][j] = 1;
    for(int i=row, j = col; i<g.size() && j < g.size(); i--, j--) g[i][j] = 1;
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        if( i ) cout<<endl;
        int m, f = 1, t;
        cin>>m;
        vector<vector<int>> g(m+1,vector<int>(m+1,0));
        vector<int> info(m+1,0);
        for(int i=1; i<=m; i++ ){
            cin>>info[i];
            if( g[ info[i] ][i] == 0 ){
                set_val( g, info[i] , i );
            }else{
                f = 0;
                break;
            }
        }
        if( f ) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}