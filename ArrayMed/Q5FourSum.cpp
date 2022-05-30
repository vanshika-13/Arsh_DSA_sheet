/*Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;

    if (n == 0)
        return res;

    for (int i = 0; i < (n - 3); i++)
    {

        for (int j = i + 1; j < (n - 2); j++)
        {

            int find = target - nums[j] - nums[i];

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {

                int sum = nums[left] + nums[right];

                if (sum > find)
                {
                    right--;
                }
                else if (sum < find)
                {
                    left++;
                }
                else
                {

                    vector<int> quad(4, 0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[left];
                    quad[3] = nums[right];
                    res.push_back(quad);

                    while (left < right && nums[left] == quad[2])
                        ++left;

                    while (left < right && nums[right] == quad[3])
                        --right;
                }
            }

            while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
        }

        while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
    }

    return res;
}
int main()
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = fourSum(nums, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}