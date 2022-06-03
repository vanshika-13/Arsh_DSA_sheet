/*Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

 

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false*/

#include <bits/stdc++.h>
using namespace std;
/*As a beginner i kept calculating sqaures of digits and updating value of sq. initially sq was n and afterwards sq was the new number made by sum of squares.
Here i ahve used map but this increases the space complexity.


long long int calsq(int n)
    {
        long long int sum =0;
        while(n)
        {
            int rem = n%10;
            n=n/10;
            sum += (rem*rem);
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_map<long long int,int> m;
        long long int sq = n;
        while(true)
        {
            sq = calsq(sq);
            m[sq]++;
            if(sq == 1)
            {
                return true;
            }
            else if(m[sq]>1)
            {
                return false;
            }
            else
            {
                continue;
            }
        }
    }

Optimised Approach
As soon as we here cycle detection than the first thing taht comes to mind is hare and tortoise slow , fast approach.
*/
int square(int n)
{
    int sum = 0, temp;
    while (n)
    {
        temp = n % 10;
        sum += temp * temp;
        n /= 10;
    }
    return sum;
}
bool isHappy(int n)
{
    int slow, fast;
    slow = fast = n;
    do
    {
        slow = square(slow);
        fast = square(fast);
        fast = square(fast);

    } while (slow != fast);
    if (slow == 1)
        return 1;
    else
        return 0;
}
int main()
{
    int n = 19;
    int m = 2;
    cout << square(n) << endl;
    cout << square(m) << endl;
    return 0;
}