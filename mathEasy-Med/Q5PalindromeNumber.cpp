/*Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.
 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.*/

#include <bits/stdc++.h>
using namespace std;
/*S= O(n);
 bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        vector<int> help;
        while(x)
        {
            int r = x% 10;
            help.push_back(r);
            x = x/10;
        }
        int n = help.size();
        for(int i=0;i<n/2;i++)
        {
            if(help[i] != help[n-i-1])
            {
                return false;
            }
        }
        return true;
    }
*/

/*
SC O(1)
bool isPalindrome(int x) {
            int flag=0;
        if(x<0)
        {
            return 0;
        }
        else
        {
          string s= to_string(x);
            int i=0;
            int j=s.size()-1;
            while(i<j)
            {
                if(s[i]==s[j])
                {
                    i++;
                    j--;
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            return 0;
        }
        else
        {
            return 1;
        }

    }
*/

// space complexity - O(1)
bool isPalindrome(int x)
{
    int v = x;
    long long int num = 0;
    int rem;

    while (v > 0)
    {
        rem = v % 10;

        num = (num * 10) + rem;
        v = v / 10;
    }
    if (num == x)
    {
        return 1;
    }

    return 0;
}
int main()
{
    int x = -121;
    cout << isPalindrome(x);
    return 0;
}