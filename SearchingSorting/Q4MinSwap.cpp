/*Given an array of n distinct elements, find the minimum number of swaps required to sort the array.

Examples:

Input: {4, 3, 2, 1}
Output: 2
Explanation: Swap index 0 with 3 and 1 with 2 to
              form the sorted array {1, 2, 3, 4}.

Input: {1, 5, 4, 3, 2}
Output: 2*/

// C++ program to find
// minimum number of swaps
// required to sort an array
#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr,
          int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int> arr,
             int N)
{
    int ans = 0;
    vector<int> temp = arr;

    // Hashmap which stores the
    // indexes of the input array
    map<int, int> h;

    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++)
    {
        h[arr[i]] = i;
    }
    for (int i = 0; i < N; i++)
    {
        // This is checking whether
        // the current element is
        // at the right place or not
        if (arr[i] != temp[i])
        {
            ans++;
            int init = arr[i];

            // If not, swap this element
            // with the index of the
            // element which should come here
            swap(arr, i, h[temp[i]]);

            // Update the indexes in
            // the hashmap accordingly
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
}

// Driver class
int main()
{
    vector<int> a = {101, 758, 315,
                     730, 472, 619,
                     460, 479};
    int n = a.size();
    cout << minSwaps(a, n);
}
