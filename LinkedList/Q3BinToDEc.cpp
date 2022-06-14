/*Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10*/

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int bToD(string b)
{
    int n = b.length(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] == '0')
        {
            continue;
        }
        else
            ans += pow(2, (n - i - 1));
    }
    return ans;
}
int getDecimalValue(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head->val;
    }
    ListNode *temp = head;
    string num;
    while (temp != NULL)
    {
        num.push_back(temp->val + '0');
        temp = temp->next;
    }
    // cout<<num<<endl;
    return bToD(num);
}
int main()
{
    return 0;
}