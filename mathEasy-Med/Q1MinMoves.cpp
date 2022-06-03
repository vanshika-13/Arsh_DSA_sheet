/*Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.



Example 1:

Input: nums = [1,2,3]
Output: 3
Explanation: Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Example 2:

Input: nums = [1,1,1]
Output: 0*/

#include <bits/stdc++.h>
using namespace std;
int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++)
        {
            sum += nums[i];
        }
        return (sum-n*nums[0]);
    }
int main()
{
    vector<int> nums{1, 2, 3};
    cout << minMoves(nums);
    return 0;
}
