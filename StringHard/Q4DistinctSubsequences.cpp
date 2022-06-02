/*Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

The test cases are generated so that the answer fits on a 32-bit signed integer.



Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag*/

#include <bits/stdc++.h>
using namespace std;

/* approach with reccursion with time complexity exponential
gives tle with memoization therefore use tabulation
int f(int i, int j, string s, string t)
{
    if (j < 0) // if string t matches completely
    {
        return 1;
    }
    if (i < 0) // if string s traversal done completely and t remaining still
    {
        return 0;
    }
    if (s[i] == t[j]) // if ch of both are smae
    {
        return f(i - 1, j - 1, s, t) + f(i - 1, j, s, t); // considering current(i-1,j-1) and maybe past one(i-1,j)
    }
    return f(i - 1, j, s, t); // ch doesn't match
}
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    return f(n - 1, m - 1, s, t);
}*/

/*uses space
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}*/

// real sol
int numDistinct(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<double> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
    }
    return (int)dp[m];
}
int main()
{
    return 0;
}