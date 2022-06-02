/*given a string return words in reverse order
example : my name is vanshika
output : vanshika is name my*/

#include <bits/stdc++.h>
using namespace std;
string reverseWords(string s)
{
    stringstream ss(s);
    string word;
    stack<string> st;
    string ans = "";
    while (ss >> word)
    {
        st.push(word);
    }
    ans = st.top();
    st.pop();
    while (!st.empty())
    {
        ans = ans + " " + st.top();
        st.pop();
    }
    return ans;
}
int main()
{
    string s = "My name is Vanshika";
    string ans = reverseWords(s);
    cout << ans;
    return 0;
}