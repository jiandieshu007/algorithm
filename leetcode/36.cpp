#include<iostream>
#include<vector>
using namespace std;

bool judge_row(vector<vector<char>> & board, int k){
    vector<int> Hash_table(10,0);
    for(int i=0; i<9; i++){
        if( board[k][i] != '.')
            if( Hash_table[ board[k][i] -'0'] == 0 ) Hash_table[ board[k][i] -'0'] = 1;
            else return false;
    }
    return true;
}
bool judge_column(vector<vector<char>> & board, int k){
    vector<int> Hash_table(10,0);
    for(int i=0; i<9; i++){
        if( board[k][i] != '.')
            if( Hash_table[ board[i][k] -'0'] == 0 ) Hash_table[ board[i][k] -'0'] = 1;
            else return false;
    }
    return true;
}
bool judge_Martix(vector<vector<char>> &board, int k1, int k2){
    vector<int> Hash_table(10,0);
    for(int i=k1 ; i<k1+3; i++){
        for(int j = k2; j < k2+3; j++){
            if( board[i][j] != '.')
                if( Hash_table[ board[i][j] - '0'] == 0 ) Hash_table[ board[i][j] - '0'] = 1;
                else return false;
        }
    }
    return true;
}
bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0; i<9; i++){
        if( judge_row(board, i ) == false) return false;
    }
    for(int i = 0; i < 9; i++){
        if( judge_column(board, i ) == false ) return false;
    }
    for(int i=0; i<9; i+=3 ){
        for(int j = 0; j<9; j+=3 ){
            if( judge_Martix(board, i, j) == false ) return false;
        }
    }
    return true;
}

int main(){
    vector<vector<char>> k(9, vector<char>(9, '.'));
    cout << isValidSudoku(k);
    return 0;
}