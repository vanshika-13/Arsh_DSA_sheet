/*Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3

link : https://youtu.be/S6rsAlj_iB4
*/

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void merge(vector<int> &nums, int l, int mid, int r)
{
    vector<int> v(r - l + 1);
    int k = l;
    for (int j = mid + 1; j <= r; j++)
    {
        while (k <= mid && nums[k] / 2.0 <= nums[j])
        {
            k++;
        }
        cnt += mid - k + 1;
    }

    int i = l, j = mid + 1, c = 0;
    while (i <= mid && j <= r)
    {
        if (nums[i] < nums[j])
            v[c++] = nums[i++];
        else
            v[c++] = nums[j++];
    }
    while (i <= mid)
        v[c++] = nums[i++];
    while (j <= r)
        v[c++] = nums[j++];
    for (int i = l; i <= r; i++)
        nums[i] = v[i - l];
}

void mergeSort(vector<int> &nums, int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int mid = l + (r - l) / 2;
    // sorting left and right half
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);

    // merging sorted halves
    merge(nums, l, mid, r);
}
int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    int l = 0;
    int r = n - 1;
    mergeSort(nums, l, r);
    return cnt;
}
int main()
{
    vector<int> nums{};
    cout << reversePairs(nums);
    return 0;
}