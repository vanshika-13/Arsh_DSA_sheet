/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

/*Brute Force->sort the array and then compare first and last string
    Time Complexity->O(NlogN)
        Space Complexity->O(1)
    // Brute Force*/

#include <bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    if (n == 1)
        return strs[0];
    string ans = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        bool match = true;
        char s = strs[0][i];
        for (int j = 1; j < n; j++)
        {
            if (strs[j].size() < i || strs[j][i] != s)
            {
                match = false;
                break;
            }
        }
        if (match == false)
        {
            return ans;
            break;
        }
        else
        {
            ans.push_back(s);
        }
    }
    return ans;
}
int main()
{
    vector<string> strs{{"flow"},{"flower"},{"heiflow"}};
    string ans = longestCommonPrefix(strs);
    cout<<ans<<endl;
    return 0;
}
