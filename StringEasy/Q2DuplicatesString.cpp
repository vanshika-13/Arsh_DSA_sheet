/*print duplicate in a string and their count*/
#include <bits/stdc++.h>
using namespace std;
void countDup(string s, unordered_map<char, int> &m)
{
    for (auto i : s)
    {
        m[i]++;
    }
}
int main()
{
    string s = "abcdaacdd";
    unordered_map<char, int> m;
    countDup(s, m);
    for (auto i : m)
    {
        if (i.second > 1)
        {
            cout << i.first << " " << i.second<<endl;
        }
    }
    return 0;
}
