/*Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:

Input: columnNumber = 1
Output: "A"*/

#include <bits/stdc++.h>
using namespace std;
string convertToTitle(int columnNumber)
{
    string ans;
    stack<char> st;
    while (columnNumber > 26)
    {
        long long rem = columnNumber % 26;
        columnNumber /= 26;
        if (rem == 0)
        {
            st.push('Z');
            columnNumber -= 1;
        }
        else
        {
            st.push((rem - 1) + 'A');
        }
    }
    st.push(columnNumber - 1 + 'A');
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main()
{
    int x = 9999999;
    cout << convertToTitle(x);
    return 0;
}