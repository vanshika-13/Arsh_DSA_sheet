/*Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21*/

#include<bits/stdc++.h>
using namespace std;
int reverse(int x) {
        long long int ans =0;
        while(x)
        {
            int rem = x%10;
            if ((ans > 0 && ans > (INT_MAX - rem)/10) | (ans < 0 && ans < (INT_MIN - rem)/10)) return 0;
            ans = (ans*10)+rem;
            x = x/10;
        }
        return (int)ans;
    }
int main()
{
    int n =456;
    cout<< reverse(n);
    return 0;
}