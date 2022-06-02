/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]*/

#include <bits/stdc++.h>
using namespace std;
void helper(int n, vector<string> &v, string s, int openN, int closedN)
{
    if (closedN == n && openN == n)
    {
        v.push_back(s);
        return;
    }

    if (openN < n)
    {
        s.push_back('(');
        helper(n, v, s, openN + 1, closedN);
        s.pop_back();
    }

    if (closedN < openN)
    {
        s.push_back(')');
        helper(n, v, s, openN, closedN + 1);
        s.pop_back();
    }
}
vector<string> genP(int n)
{
    vector<string> v;
    string s = "";
    helper(n, v, s, 0, 0);
    return v;
}
int main()
{
    return 0;
}