/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.*/

#include <bits/stdc++.h>
using namespace std;
bool validPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return (isValid(s, i + 1, j) || isValid(s, i, j - 1));
        }
        i++, j--;
    }
    return true;
}

bool isValid(string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}
int main()
{
    return 0;
}