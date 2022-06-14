/*Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]


Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]*/

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
ListNode *reverse(ListNode *head, int k)
{
    if (!head)
        return NULL;
    ListNode *prev = NULL;
    ListNode *nxt = head;
    ListNode *end = head;
    int K = k;
    while (K-- && head)
    {
        nxt = nxt->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }

    if (K != -1)
    {
        // last section reversed
        return reverse(prev, k - K - 1);
    }
    else
    {
        end->next = reverse(nxt, k);
    }

    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    return reverse(head, k);
}
int main()
{
    return 0;
}