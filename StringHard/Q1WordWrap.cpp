/*Given an array nums[] of size n, where nums[i] denotes the number of characters in one word. Let K be the limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such that the lines are printed neatly.
Assume that the length of each word is smaller than the line width. When line breaks are inserted there is a possibility that extra spaces are present in each line. The extra spaces include spaces put at the end of every line except the last one.

You have to minimize the following total cost where total cost = Sum of cost of all lines, where cost of line is = (Number of extra spaces in the line)2.

Example 1:

Input: nums = {3,2,2,5}, k = 6
Output: 10
Explanation: Given a line can have 6
characters,
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4
So total cost = (6-3)2 + (6-2-2-1)2 = 32+12 = 10.
As in the first line word length = 3 thus
extra spaces = 6 - 3 = 3 and in the second line
there are two word of length 2 and there already
1 space between two word thus extra spaces
= 6 - 2 -2 -1 = 1. As mentioned in the problem
description there will be no extra spaces in
the last line. Placing first and second word
in first line and third word on second line
would take a cost of 02 + 42 = 16 (zero spaces
on first line and 6-2 = 4 spaces on second),
which isn't the minimum possible cost.*/

#include <bits/stdc++.h>
using namespace std;
int dp[505][2005];
int rec(int i, int rem, vector<int> &nums, int &k)
{
    if (i == nums.size())
    {
        return 0;
    }
    if (dp[i][rem] != -1)
    {
        return dp[i][rem];
    }
    int ans;
    if (nums[i] > rem)
    {
        ans = (rem + 1) * (rem + 1) + rec(i + 1, k - nums[i] - 1, nums, k);
    }
    else
    {
        int choice1 = (rem + 1) * (rem + 1) + rec(i + 1, k - nums[i] - 1, nums, k);
        ;
        int choice2 = rec(i + 1, rem - nums[i] - 1, nums, k);
        ans = min(choice1, choice2);
    }
    dp[i][rem] = ans;
    return dp[i][rem];
}
int solveWordWrap(vector<int> nums, int k)
{
    // Code here
    memset(dp, -1, sizeof(dp));
    return rec(0, k, nums, k);
}
int main()
{
    vector<int> nums{3, 2, 2, 5};
    cout << solveWordWrap(nums, 6);
    return 0;
}
