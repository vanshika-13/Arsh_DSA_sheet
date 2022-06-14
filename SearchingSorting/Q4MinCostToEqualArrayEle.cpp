/*Make all array elements equal with minimum cost

Difficulty Level : Medium
Last Updated : 31 May, 2022
Given an array which contains integer values, we need to make all values of this array equal to some integer value with minimum cost where the cost of changing an array value x to y is abs(x-y).

Examples :

Input  : arr[] = [1, 100, 101]
Output : 100
We can change all its values to 100 with minimum cost,
|1 - 100| + |100 - 100| + |101 - 100| = 100

Input  : arr[] = [4, 6]
Output : 2
We can change all its values to 5 with minimum cost,
|4 - 5| + |5 - 6| = 2*/

#include <bits/stdc++.h>
using namespace std;

// This function assumes that a[] is
// sorted. If a[] is not sorted, we need
// to sort it first.
int minCostToMakeElementEqual(int a[], int n)
{

    // If there are odd elements, we choose
    // middle element
    int y;
    if (n % 2 == 1)
        y = a[n / 2];

    // If there are even elements, then we choose
    // the average of middle two.
    else
        y = (a[n / 2] + a[(n - 2) / 2]) / 2;

    // After deciding the final value, find the
    // result.
    int s = 0;
    for (int i = 0; i < n; i++)
        s += abs(a[i] - y);

    return s;
}

// Driver code
int main()
{
    int a[] = {1, 100, 101};
    int n = sizeof(a) / sizeof(a[0]);

    cout << (minCostToMakeElementEqual(a, n));
}

// This code is contributed by chitranayal
