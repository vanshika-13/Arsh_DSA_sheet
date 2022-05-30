/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false*/

#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<char> str)
{
    stack<char> paren;
    for (char &c : str)
    {
        switch (c)
        {
        case '(':
        case '{':
        case '[':
            paren.push(c);
            break;
        case ')':
            if (paren.empty() || paren.top() != '(')
                return false;
            else
                paren.pop();
            break;
        case '}':
            if (paren.empty() || paren.top() != '{')
                return false;
            else
                paren.pop();
            break;
        case ']':
            if (paren.empty() || paren.top() != '[')
                return false;
            else
                paren.pop();
            break;
        default:;
        }
    }
    return paren.empty();
}
int main()
{
    vector<char> str{'[', '{', '+', '}', ']'};
    cout << isValid(str);
    return 0;
}