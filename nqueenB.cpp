#include <iostream>
#include <vector>
using namespace std;

bool foundSolution = false;

void printBoard(const vector<vector<bool>> &board)
{   
    for (const auto &row : board)
    {   cout <<"\t\t\t";
        for (bool cell : row)
        {
            cout << (cell ? "Q  " : ".  ");
        }
        cout <<"\t\t\t"<<endl;
    }
}

void nqueens(vector<vector<bool>> &board, int row, vector<bool> &cols, vector<bool> &nd, vector<bool> &rd, string asf)
{
    if (row == board.size())
    {
        cout << "Solution found:" << endl;
        printBoard(board);
        foundSolution = true; // Set flag to indicate solution found
        return;
    }

    if (foundSolution)
        return; // If a solution is found, stop further exploration

    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (!cols[i] && !nd[row + i] && !rd[row - i + n - 1])
        {
            cols[i] = nd[row + i] = rd[row - i + n - 1] = true;
            board[row][i] = true;

            nqueens(board, row + 1, cols, nd, rd, asf + to_string(row) + "-" + to_string(i) + ", ");

            board[row][i] = false;
            cols[i] = nd[row + i] = rd[row - i + n - 1] = false;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter board size: "; 
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<bool> cols(n, false); // Tracks whether a queen is placed in each column. It has n elements, one for each column.
    vector<bool> nd(2 * n - 1, false);
    vector<bool> rd(2 * n - 1, false);

    nqueens(board, 0, cols, nd, rd, "");

    if (!foundSolution)
    {
        cout << "No solution found for " << n << "-queens problem." << endl;
    }

    return 0;
}
