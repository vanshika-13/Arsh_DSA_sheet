/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include <bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int l = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            nums[l++] = nums[i];
        }
    }
    while (l < nums.size())
    {
        nums[l++] = 0;
    }
}
int main()
{
    vector<int> nums{0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
