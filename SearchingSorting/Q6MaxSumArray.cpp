/*Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.*/

#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &nums, int mid, int k)
{

    int curr = 1, sm = 0;

    for (int i = 0; i < nums.size(); i++)
    {

        if (sm + nums[i] > mid)
        {
            sm = nums[i];
            curr++;
            if (curr > k)
                return false;
        }
        else
            sm += nums[i];
    }
    return true;
}

int splitArray(vector<int> &nums, int m)
{

    int mn = *max_element(nums.begin(), nums.end()), mx = accumulate(nums.begin(), nums.end(), 0);
    int res;
    while (mn <= mx)
    {
        int mid = (mn + mx) / 2;
        if (isPossible(nums, mid, m))
        {
            res = mid;
            mx = mid - 1;
        }
        else
        {
            mn = mid + 1;
        }
    }
    return res;
}
int main()
{
    return 0;
}