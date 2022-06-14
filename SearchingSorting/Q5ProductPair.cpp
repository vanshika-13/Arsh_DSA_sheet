/*Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i].
Example 1:
Input:
n = 5
nums[] = {10, 3, 5, 6, 2}
Output:
180 600 360 300 900
Explanation: 
For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.*/

#include<bits/stdc++.h>
using namespace std;
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       long long int real_product = 1;
        vector<long long int> ans(n,0);
        int count = 0, store;
        
        for(int i = 0; i < n; i++) {
            if(nums[i]) real_product *= nums[i];
            else ++count, store = i;
            if(count > 1) return ans;
        }
        
        if(count == 1) {
            ans[store] = real_product;
            return ans;
        }
        
        for(int i = 0; i < n; i++) ans[i] = real_product/nums[i];
        
        return ans;
    }
int main()
{
    return 0;
}