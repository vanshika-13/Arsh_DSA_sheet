/*Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Example 2:

Input: nums = []
Output: []*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    // moves for a
    for (int i = 0; i < (int)(nums.size()) - 2; i++)
    {

        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {

            int lo = i + 1, hi = (int)(nums.size()) - 1, sum = 0 - nums[i];

            while (lo < hi)
            {
                if (nums[lo] + nums[hi] == sum)
                {

                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);

                    while (lo < hi && nums[lo] == nums[lo + 1])
                        lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1])
                        hi--;

                    lo++;
                    hi--;
                }
                else if (nums[lo] + nums[hi] < sum)
                    lo++;
                else
                    hi--;
            }
        }
    }
    return res;
}
int main()
{
    vector<int> nums;
    vector<vector<int>> ans = threeSum(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}