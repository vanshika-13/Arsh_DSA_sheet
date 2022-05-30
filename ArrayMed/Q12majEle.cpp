/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3*/

#include <bits/stdc++.h>
using namespace std;
int majEle(vector<int> nums)
{
    int majority = nums[0];
    int count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == majority)
        {
            count++;
        }
        else
        {
            count--;
            if (count == 0)
            {
                majority = nums[i];
                count = 1;
            }
        }
    }
    return majority;
}
int main()
{
    vector<int> nums{3, 2, 2, 3, 3, 4,3};
    cout << majEle(nums);
    return 0;
}