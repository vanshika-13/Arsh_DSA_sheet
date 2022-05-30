/*find number of subarrays with given sum k*/

#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> nums, int k)
{
    int sum = 0, ans = 0;
    unordered_map<int, int> m;
    m[0] =1;
    for (auto i : nums)
    {
        sum += i;
        int find = sum - k;
        if (m.find(find) != m.end())
        {
            ans += m[find];
        }
        m[sum]++;
    }
    return ans;
}
int main()
{
    vector<int> nums{1, 2, 3};
    cout << subarraySum(nums, 3) << endl;
    return 0;
}