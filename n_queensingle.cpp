#include <bits/stdc++.h>
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

        while (i >= 0) {
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

    bool solve(vector<string>& board, int i) {
        if (i == board.size()) {
            return true;
        }
        for (int j = 0; j < board.size(); j++) {
            if (isSafe(i, j, board.size(), board)) {
                board[i][j] = 'Q';
                if (solve(board, i + 1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    vector<string> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return board;
    }
};

int main()
{
    N_Qin S;
    int n = 10;
    vector<string> answer;
    answer = S.solveNQueens(n);

    // Printing the solution
    for (int i = 0; i < n; i++) {
         cout <<"\t\t\t";
        for (int j = 0; j < n; j++) {
            if (answer[i][j] == 'Q') {
                cout << "Q  ";
            } else {
                cout << ".  ";
            }
        }
        cout <<"\t\t\t"<<endl;
    }

    return 0;
}
