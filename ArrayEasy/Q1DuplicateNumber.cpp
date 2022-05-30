/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.*/

// MY APPROACH

/*#include <bits/stdc++.h>
using namespace std;
int repeatedNumber(vector<int> nums)
{
    int n = nums.size();
    set<int> seen;
    for (auto i : nums)
    {
        if (seen.count(i))
        {
            return i;
        }
        seen.insert(i);
    }
    return -1;
}
int main()
{
    vector<int> nums{1, 2, 2, 3, 4, 5};
    cout << repeatedNumber(nums);
    return 0;
}*/

// optimal approach
#include <bits/stdc++.h>
using namespace std;
int repeatedNumber(vector<int> nums)
{
    int n = nums.size();
    int tortoise = nums[0];
    int hare = nums[0];

    do
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}
int main()
{
    vector<int> nums{1, 2, 3, 2, 4, 5};
    cout<< repeatedNumber(nums);
}