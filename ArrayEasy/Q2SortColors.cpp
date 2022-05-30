/*Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.



Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]*/

#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, m = 0, r = n - 1;
    while (m <= r)
    {
        if (nums[m] == 0)
        {
            swap(nums[l++], nums[m++]);
        }
        else if (nums[m] == 2)
        {
            swap(nums[r--], nums[m]);
        }
        else
        {
            m++;
        }
    }
}
int main()
{
    vector<int> nums{1, 1, 0, 0, 2, 0, 1, 2};
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
