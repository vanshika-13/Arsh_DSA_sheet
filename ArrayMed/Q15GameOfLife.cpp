/*According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]*/

/*I have store the solution in 4 states.
0 0 -> 3 that means initially matrix contain 0 and now it contains 0 as well.
0 1 -> 4 that means initially matrix contain 0 and now it contains 1.
1 0 -> 5 that means initially matrix contain 1 and now it contains 1.
1 1 -> 6 that means initially matrix contain 1 and now it contains 1 as well.*/
#include <bits/stdc++.h>
using namespace std;

bool check(int i, int j, int n, int m)
{
    if (i < 0 || i == n || j < 0 || j == m)
        return 0;
    return 1;
}

void gameOfLife(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int move[8][2] = {{-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int res = 0;
            for (int k = 0; k < 8; k++)
            {
                if (check(i + move[k][0], j + move[k][1], n, m) && (matrix[i + move[k][0]][j + move[k][1]] == 1 || matrix[i + move[k][0]][j + move[k][1]] == 5 || matrix[i + move[k][0]][j + move[k][1]] == 6))
                {
                    res++;
                }
            }
            if (matrix[i][j] == 0)
            {
                if (res == 3)
                    matrix[i][j] = 4;
                else
                    matrix[i][j] = 3;
            }
            else
            {
                if (res < 2 || res > 3)
                    matrix[i][j] = 5;
                else
                    matrix[i][j] = 6;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 4 || matrix[i][j] == 6)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
}
int main()
{
    vector<vector<int>> matrix{{}, {}, {}};
    gameOfLife(matrix);
    int n = matrix.size(), m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}