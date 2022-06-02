/*Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7*/

#include <bits/stdc++.h>
using namespace std;
long operate(long val1, long val2, char op)
{
    if (op == '+')
        return val1 + val2;
    else if (op == '-')
        return val1 - val2;
    else if (op == '*')
        return val1 * val2;
    else
        return val1 / val2;
}

int calculate(string s)
{
    if (s[0] == '-')
        s = '0' + s;
    unordered_map<char, int> prec;
    // assigning precedence
    prec['+'] = 1;
    prec['-'] = 1;
    prec['*'] = 2;
    prec['/'] = 2;

    stack<long> nums;
    stack<char> opr;

    int i = 0;
    while (i < s.size())
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }

        if (isdigit(s[i]))
        {
            long val = 0;
            while (i < s.size() && isdigit(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            nums.push(val);
        }
        else
        {
            while (!opr.empty() && prec[s[i]] <= prec[opr.top()])
            {
                long val2 = nums.top();
                nums.pop();
                long val1 = nums.top();
                nums.pop();
                char op = opr.top();
                opr.pop();
                long ans = operate(val1, val2, op);
                nums.push(ans);
            }

            opr.push(s[i]);
            i++;
        }
    }

    // possibly some operator remain in stack
    while (!opr.empty() && prec[s[i]] <= prec[opr.top()])
    {
        long val2 = nums.top();
        nums.pop();
        long val1 = nums.top();
        nums.pop();
        char op = opr.top();
        opr.pop();
        long ans = operate(val1, val2, op);
        nums.push(ans);
    }

    long ans = nums.top();
    return (int)ans;
}
int main()
{
    string s = "3*4/2+6-1";
    cout << calculate(s);
    return 0;
}