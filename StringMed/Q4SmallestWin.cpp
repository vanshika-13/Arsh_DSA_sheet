/*Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.

Example 1:

Input:
S = "timetopractice"
P = "toc"
Output:
toprac
Explanation: "toprac" is the smallest
substring in which "toc" can be found.*/
#include <bits/stdc++.h>
using namespace std;
string smallestWindow(string s, string p)
{
    int n = s.length();
    int n2 = p.length();
    if (n2 > n)
    {
        return "-1";
    }
    unordered_map<int, int> mps;
    for (int i = 0; i < n2; i++)
    {
        mps[p[i]]++;
    }
    unordered_map<int, int> mpf;
    string ans = "";
    string curr;
    int i = -1, j = -1;
    int cmp = 0, acmp = p.size();
    while (true)
    {
        // fill and check
        bool f1 = false;
        bool f2 = false;
        // acquire
        while (cmp < acmp and i < n - 1)
        {
            i++;
            mpf[s[i]]++;
            if (mpf[s[i]] <= mps[s[i]])
            {
                cmp++;
            }
            f1 = true;
        }
        // collect ans and release
        while (j < i and cmp == acmp)
        {
            string st = s.substr(j + 1, i - (j + 1) + 1);
            if (st.length() < ans.length() or ans.length() == 0)
            {
                ans = st;
            }
            j++;
            if (mpf[s[j]] == 1)
            {
                mpf.erase(s[j]);
            }
            else
            {
                mpf[s[j]]--;
            }
            if (mpf[s[j]] < mps[s[j]])
            {
                cmp--;
            }
            f2 = true;
        }
        if (!f1 and !f2)
        {
            break;
        }
    }
    if (ans.length() == 0)
    {
        return "-1";
    }
    return ans;
}
int main()
{
    string s = "timetopractice";
    string p = "toc";
    cout << smallestWindow(s, p);
    return 0;
}