/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally 
or vertically neighboring. The same letter cell may not be used more than once.*/

#include <bits/stdc++.h>
using namespace std;
bool help(vector<vector<char>> &nums, string word, int i, int j, int k)
{
    if (word.size() == k)
    {
        return true;
    }
    if (i < 0 || i >= nums.size() || j < 0 || j >= nums[0].size())
    {
        return false;
    }
    bool ans = false;
    if (nums[i][j] == word[k])
    {
        char temp = nums[i][j];
        nums[i][j] = '0';
        ans = ans || help(nums, word, i + 1, j, k + 1);
        ans = ans || help(nums, word, i - 1, j, k + 1);
        ans = ans || help(nums, word, i, j + 1, k + 1);
        ans = ans || help(nums, word, i, j - 1, k + 1);
        nums[i][j] = temp;
    }
    return ans;
}

bool exist(vector<vector<char>> &nums, string word)
{

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums[0].size(); j++)
        {
            if (nums[i][j] == word[0])
            {
                bool x = help(nums, word, i, j, 0);
                if (x == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main()
{
    vector<vector<char>> boards{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(boards, word);
    return 0;
}