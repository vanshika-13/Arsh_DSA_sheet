/*Hard

5605

159

Add to List

Share
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.*/

#include <bits/stdc++.h>
using namespace std;
void merge(vector<pair<int, int>> &v, vector<int> &count, int left, int right, int mid)
{
    vector<pair<int, int>> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    // decending order merge sort

    while (i <= mid && j <= right)
    {
        if (v[i].first <= v[j].first)
        {
            temp[k] = v[j];
            k++, j++;
        }
        else
        {
            // main line
            count[v[i].second] += right - j + 1;
            temp[k] = v[i];
            k++, i++;
        }
    }
    while (i <= mid)
    {
        temp[k] = v[i];
        k++, i++;
    }
    while (j <= right)
    {
        temp[k] = v[j];
        k++, j++;
    }
    for (int i = left; i <= right; ++i)
    {
        v[i] = temp[i - left];
    }
}

void mergeSort(vector<pair<int, int>> &v, vector<int> &count, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(v, count, left, mid);
        mergeSort(v, count, mid + 1, right);
        merge(v, count, left, right, mid);
    }
}
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    vector<int> count(n, 0);
    for (int i = 0; i < n; ++i)
    {
        v[i] = {nums[i],i}; // {element, index}
    }
    mergeSort(v, count, 0, n - 1);
    return count;
}
int main()
{
    return 0;
}
