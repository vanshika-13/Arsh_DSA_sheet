/*Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.*/

#include <bits/stdc++.h>
using namespace std;
bool findPair(int arr[], int size, int n)
{
    // code
    unordered_map<int, int> mpp;
    for (int i = 0; i < size; i++)
    {
        mpp[arr[i]]++;

        // Check if any element whose frequency
        // is greater than 1 exist or not for n == 0
        if (n == 0 && mpp[arr[i]] > 1)
            return true;
    }

    // Check if difference is zero and
    // we are unable to find any duplicate or
    // element whose frequency is greater than 1
    // then no such pair found.
    if (n == 0)
        return false;

    for (int i = 0; i < size; i++)
    {
        if (mpp.find(n + arr[i]) != mpp.end())
        {

            return true;
        }
    }

    return false;
}
int main()
{
    int arr[5];
    cout << findPair(arr, 5, 78);
    return 0;
}