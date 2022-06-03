/*You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.

Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
Example 1:

Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.
Example 2:

Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.*/

#include <bits/stdc++.h>
using namespace std;
int kthFactor(int n, int k)
{
    int count = 0;

    for (int i = 1; i <= n / 2; i++)
    {
        count += n % i == 0;
        if (count == k)
            return i;
    }

    return ++count == k ? n : -1;
}
int main()
{
    cout << kthFactor(69, 5);
    return 0;
}