/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/
#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::multimap;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if((board.size() == 0)||(board.size() > 9)) {
            return false;
        }
        for(int row = 0; row < board.size(); row++) {
            if((board[row].size() == 0) || (board[row].size() > 9)) {
                return false;
            }
            for(int col = 0; col < board[row].size(); col++) {
                if((board[row][col] >= '1') && (board[row][col] <= '9')) {
                    vector<int> entry({row, col});
                    int count = digit_pos.count(board[row][col]);
                    if(count != 0) {
                        auto iter = digit_pos.find(board[row][col]); 
                        while(count) {
                            if(isDuplicate(iter->second, entry)) {
                                return false;
                            }
                            --count;
                            ++iter;
                        }
                    }
                    digit_pos.insert(make_pair(board[row][col], entry));
                }else if(board[row][col] != '.') {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isDuplicate(const vector<int> &a, const vector<int> &b) {
        if((a[0] == b[0])||(a[1] == b[1])) {
            return true;
        }
        if((a[0]/3 == b[0]/3)&&(a[1]/3 == b[1]/3)) {
            return true;
        }
        return false;
    }
    multimap<char, vector<int>> digit_pos;
};

int main() {
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution slt;
    cout<<slt.isValidSudoku(board)<<endl;
    return 0;
}