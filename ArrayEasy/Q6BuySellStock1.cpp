/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

#include <bits/stdc++.h>
using namespace std;
int profit(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, pro = 0;
    int j = 1;
    while (j < n)
    {
        if (nums[i] < nums[j])
        {
            pro = max(pro, nums[j] - nums[i]);
        }
        else
        {
            i = j;
        }
        j++;
    }
    return pro;
}
int main()
{
    vector<int> nums{7, 1, 5, 3, 6, 4};
    cout << profit(nums) << " ";
    return 0;
}