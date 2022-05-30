/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in 
the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> nums)
{
    int n = nums.size();
    int l = n - 1;
    for (int i = l; i >= 0; i--)
    {
        if (nums[i] >= (l - i))
        {
            l = i;
        }
    }
    if (l == 0)
    {
        return true;
    }
    return false;
}
int main()
{
    vector<int> nums{3, 2, 1, 0, 4};
    cout << jump(nums);
    return 0;
}