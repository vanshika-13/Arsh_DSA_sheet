/*You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.*/

#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int pro = 0;
    int n = prices.size();
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            pro += (prices[i] - prices[i - 1]);
        }
    }
    return pro;
}
int main()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    int ans = maxProfit(prices);
    cout << ans;
    return 0;
}