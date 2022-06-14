/*Given elements as nodes of the two linked lists. The task is to multiply these two linked lists, say L1 and L2. 

Note: The output could be large take modulo 109+7.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow, the first line of each test case contains an integer N denoting the size of the first linked list (L1). In the next line are the space separated values of the first linked list. The third line of each test case contains an integer M denoting the size of the second linked list (L2). In the forth line are space separated values of the second linked list.

Output:
For each test case output will be an integer denoting the product of the two linked list.

User Task:
The task is to complete the function multiplyTwoLists() which should multiply the given two linked lists and return the result.

Constraints:
1 <= T <= 100
1 <= N, M <= 100

Example:
Input:
2
2
3 2
1
2
3
1 0 0
2
1 0 

Output:
64
1000

Explanation:
Testcase 1: 32*2 = 64.

Testcase 2: 100*10 = 1000.*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
long long multiplyTwoLists(Node *l1, Node *l2)
{
    // Your code here
    if (l1 == NULL)
    {
        return l2->data;
    }
    else if (l2 == NULL)
    {
        return l1->data;
    }
    Node *t1 = l1;
    Node *t2 = l2;
    long long ans1 = 0, ans2 = 0;
    while (t1)
    {
        ans1 = (ans1 * 10) % (1000000007) + (t1->data);
        t1 = t1->next;
    }
    while (t2)
    {
        ans2 = (ans2 * 10) % (1000000007) + (t2->data);
        t2 = t2->next;
    }
    return ((ans1 % 1000000007) * (ans2 % 1000000007)) % (1000000007);
}
int main()
{
    return 0;
}