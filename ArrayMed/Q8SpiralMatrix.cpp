/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

*/

#include <bits/stdc++.h>
using namespace std;
vector<int> SpiralPrint(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<int> ans;
    int m = matrix[0].size();
    int fr = 0, fc = 0, lr = n - 1, lc = m - 1;
    while (fr <= lr && fc <= lc)
    {
        for (int i = fc; i <= lc; i++)
        {
            ans.push_back(matrix[fr][i]);
        }
        fr++;
        if (n * m == ans.size())
        {
            return ans;
        }
        for (int i = fr; i <= lr; i++)
        {
            ans.push_back(matrix[i][lc]);
        }
        lc--;
        if (n * m == ans.size())
        {
            return ans;
        }
        for (int i = lc; i >= fc; i--)
        {
            ans.push_back(matrix[lr][i]);
        }
        lr--;
        if (n * m == ans.size())
        {
            return ans;
        }
        for (int i = lr; i >= fr; i--)
        {
            ans.push_back(matrix[i][fc]);
        }
        fc++;
        if (n * m == ans.size())
        {
            return ans;
        }
    }

    return ans;
}
int main()
{
    vector<vector<int>> matrix{{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}};
    vector<int> ans = SpiralPrint(matrix);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}