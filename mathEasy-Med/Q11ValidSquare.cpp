/*Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.

The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

A valid square has four equal sides with positive length and four equal angles (90-degree angles).



Example 1:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: true
Example 2:

Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
Output: false
Example 3:

Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
Output: true*/

#include <bits/stdc++.h>
using namespace std;
bool isSame(vector<int> &p1, vector<int> &p2)
{
    return p1[0] == p2[0] && p1[1] == p2[1];
}

float distance(vector<int> &p1, vector<int> &p2)
{
    return pow(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2), 0.5);
}

bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
{
    unordered_map<float, int> m;

    if (isSame(p1, p2) or isSame(p1, p3) or isSame(p1, p4) or isSame(p2, p3) or isSame(p3, p4) or isSame(p2, p4))
        return false;

    ++m[distance(p1, p2)], ++m[distance(p1, p3)], ++m[distance(p1, p4)];
    ++m[distance(p2, p1)], ++m[distance(p2, p3)], ++m[distance(p2, p4)];
    ++m[distance(p3, p1)], ++m[distance(p3, p2)], ++m[distance(p3, p4)];
    ++m[distance(p4, p1)], ++m[distance(p4, p2)], ++m[distance(p4, p3)];

    auto it = m.begin();

    if (m.size() == 2 and (it->second == 8 or (++it)->second == 8))
        return true;
    return false;
}
int main()
{
    vector<int> p1;
    vector<int> p2;
    vector<int> p3;
    vector<int> p4;
    cout << validSquare(p1, p2, p3, p4);
    return 0;
}