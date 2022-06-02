/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> m;
    vector<vector<string>> ans;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(strs[i].begin(), strs[i].end());
        m[strs[i]].push_back(s);
    }
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}

int main()
{
    vector<string> strs{{"eat"}, {"tea"}, {"tan"}, {"ate"}, {"bat"}, {"nat"}};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); i++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}