/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.*/

#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    set<int> r;
    set<int> c;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                r.insert(i);
                c.insert(j);
            }
        }
    }
    for (auto i : r)
    {
        for (int j = 0; j < m; j++)
            matrix[i][j] = 0;
    }
    for (auto i : c)
    {
        for (int j = 0; j < n; j++)
            matrix[j][i] = 0;
    }
}
int main()
{
    vector<vector<int>> matri{{0, 1, 2}, {2, 3, 0}};
    setZeroes(matri);
    int n = matri.size();
    int m = matri[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matri[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}