#include<iostream>
#include<vector>
using namespace std;

bool dfs(const vector<vector<char>>& board, int x, int y, int j, const string & word, vector<vector<int>>& visit ){
    visit[x][y] = 1;    
    if( x>=0 && x < board.size() && y >=0 && y < board[0].size() && board[x][y] == word[j] ){

        if( j == word.size() -1 ) return true; //匹配成功
        
        if( x+1 < board.size() && visit[x+1][y] == 0 && board[x+1][y] == word[j+1] )  dfs(board, x+1, y, j+1, word, visit );
        if( x-1 >=0 && visit[x-1][y] == 0 && board[x-1][y] == word[j+1])  dfs( board, x-1, y, j+1, word, visit );
        if( y+1 < board[0].size() &&  visit[x][y+1] == 0 && board[x][y+1] == word[j+1])  dfs( board, x, y+1, j+1, word, visit );
        if( y-1>=0 && visit[x][y-1] == 0 && board[x][y-1] == word[j+1] ) dfs( board, x, y-1, j+1, word, visit);
    }
    visit[x][y] = 0;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n,0));
    for(int i=0; i<m; i++){
        for(int j=0;j<n; j++){
            if( dfs(board, i, j, 0, word, vis) ) 
                return true;
        }
    }
    return false;
}

int main(){
    int m, n;
    string s;
    cin >> m >> n >> s;
    vector<vector<char>> chk(m, vector<char>(n));
    for (int i = 0; i<m; i++ ){
        for (int j = 0; j < n; j ++ ){
            cin >> chk[i][j];
        }
    }
    cout << exist(chk, s);
    return 0;
}