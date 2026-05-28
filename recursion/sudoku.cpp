#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sudoku-solver/
class Solution {
private:
bool possible(char dig, int row, int col, vector<vector<char>>& board){
    for (int j = 0; j < 9; j++){
        if (board[row][j] == dig){
            return false;
        }
    }

    for (int i = 0; i < 9; i++){
        if (board[i][col] == dig){
            return false;
        }
    }

    int r = row / 3, c = col / 3;
    for (int i = 3 * r; i < 3 * r + 3; i++){
        for (int j = 3 * c; j < 3 * c + 3; j++){
            if (board[i][j] == dig){
                return false;
            }
        }
    }

    return true;

}

bool solve(vector<vector<char>>& board){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] == '.'){
                for (char dig = '1'; dig <= '9'; dig++){
                    if (possible(dig, i, j, board)){
                        board[i][j] = dig;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};