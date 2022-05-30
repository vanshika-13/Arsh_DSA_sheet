/*Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 */

// approach - using map to store remainder and count of remainder. If same remainder left then number
// is divisible by given integer k.
#include <bits/stdc++.h>
using namespace std;
int subarraysDivByK(vector<int> &nums, int k)
{
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> m;
    m[0] = 1;
    int s = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        s += nums[i];
        r = s % k;
        if (r < 0)
            r += k;
        if (m.find(r) != m.end())
        {
            ans += m[r];
        }
        m[r]++;
    }
    return ans;
}
int main()
{
    vector<int> nums{4, 5, 0, -2, -3, 1};
    int k;
    cout << subarraysDivByK(nums, 5);
    return 0;
}