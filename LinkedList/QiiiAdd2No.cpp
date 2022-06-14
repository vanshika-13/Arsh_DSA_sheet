/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:


Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]
Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]s*/

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
ListNode *reverseLL(ListNode *l1)
{
    ListNode *prev = NULL;
    ListNode *curr = l1;
    ListNode *nex = NULL;
    while (curr)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head1 = reverseLL(l1);
    ListNode *head2 = reverseLL(l2);
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;

    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry)
    {

        int sum = 0;

        if (head1 != NULL)
        {
            sum += head1->val;
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            sum += head2->val;
            head2 = head2->next;
        }

        sum += carry;
        carry = sum / 10;
        ListNode *node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return reverseLL(dummy->next);
}
int main()
{
    return 0;
}