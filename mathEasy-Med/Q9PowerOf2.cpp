/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16*/

#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    int ans;
    for (int i = 0; i <= 30; i++)
    {
        ans = pow(2, i);
        if (n == ans)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    cout << isPowerOfTwo(456);
    return 0;
}