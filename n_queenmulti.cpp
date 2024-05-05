#include<bits/stdc++.h>
using namespace std;

class N_Qin {
public:
    bool isSafe(int i, int j, int n, vector<string>& board) {
        int row = i, col = j;
        while (i >= 0 and j >= 0) {
            if (board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row;
        j = col;

        while (i>= 0) {
            if (board[i][j] == 'Q') return false;
            i--;
        }

        i = row;
        j = col;
        while (j < n and i >= 0) {
            if (board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& board, int i) {
        if (i == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (isSafe(i, j, board.size(), board)) {
                board[i][j] ='Q';
                solve(ans, board, i + 1);
                board[i][j] ='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(result, board, 0);

        return result;
    }
};

int main()
{  
    N_Qin S ; 
    int n = 8;
    vector<vector<string>> answerstored;
    answerstored = S.solveNQueens(n);
    
    // Printing the solutions
    for(const auto& solution : answerstored) {
        for(const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}