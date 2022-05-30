/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/

#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int> nums, int target)
{
    int n = nums.size();
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++)
    {
        int ntf = target - nums[i];
        if (seen.find(ntf) != seen.end())
        {
            return {seen[ntf], i};
        }
        seen.insert({nums[i], i});
    }
    return {};
}
int main()
{
    vector<int> nums{2, 7, 11, 15};
    vector<int> ans = twoSum(nums, 9);
    cout << ans[0] << " " << ans[1];
}