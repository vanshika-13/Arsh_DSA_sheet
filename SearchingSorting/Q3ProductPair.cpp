/*Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator in O(n) time.

Example :

Input: arr[]  = {10, 3, 5, 6, 2}
Output: prod[]  = {180, 600, 360, 300, 900}
3 * 5 * 6 * 2 product of other array
elements except 10 is 180
10 * 5 * 6 * 2 product of other array
elements except 3 is 600
10 * 3 * 6 * 2 product of other array
elements except 5 is 360
10 * 3 * 5 * 2 product of other array
elements except 6 is 300
10 * 3 * 6 * 5 product of other array
elements except 2 is 900*/



/*
#include <bits/stdc++.h>
using namespace std;
vector<long long int> prev(vector<long long int> &nums, int n)
{
    vector<long long int> ans(n + 1, 0);
    ans[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }
    return ans;
}
vector<long long int> next(vector<long long int> &nums, int n)
{
    vector<long long int> ans(n + 1, 0);
    ans[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = ans[i + 1] * nums[i];
    }
    return ans;
}
vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<long long int> ans(n, 0);
    vector<long long int> prevpro(n + 1, 0);
    prevpro = prev(nums, n);
    vector<long long int> nextpro(n + 1, 0);
    nextpro = next(nums, n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = prevpro[i] * nextpro[i + 1];
    }
    return ans;
}
int main()
{
    return 0;
}
*/

// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;

/* Function to print product array
for a given array arr[] of size n */
void productArray(int arr[], int n)
{

    // Base case
    if (n == 1)
    {
        cout << 0;
        return;
    }

    int i, temp = 1;

    /* Allocate memory for the product array */
    int *prod = new int[(sizeof(int) * n)];

    /* Initialize the product array as 1 */
    memset(prod, 1, n);

    /* In this loop, temp variable contains product of
    elements on left side excluding arr[i] */
    for (i = 0; i < n; i++)
    {
        prod[i] = temp;
        temp *= arr[i];
    }

    /* Initialize temp to 1
    for product on right side */
    temp = 1;

    /* In this loop, temp variable contains product of
    elements on right side excluding arr[i] */
    for (i = n - 1; i >= 0; i--)
    {
        prod[i] *= temp;
        temp *= arr[i];
    }

    /* print the constructed prod array */
    for (i = 0; i < n; i++)
        cout << prod[i] << " ";

    return;
}

// Driver Code
int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The product array is: \n";
    productArray(arr, n);
}

// This code is contributed by rathbhupendra
