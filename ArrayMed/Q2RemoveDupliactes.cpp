/*Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer 
appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.*/

#include <bits/stdc++.h>
using namespace std;
vector<int> findDuplicate(vector<int> &nums)
{
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        int val = abs(nums[i]);
        if (nums[val - 1] < 0)
            ans.push_back(val);
        else
            nums[val - 1] = -nums[val - 1];
    }

    return ans;
}
int main()
{
    vector<int> nums;
    vector<int> ans = findDuplicate(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
