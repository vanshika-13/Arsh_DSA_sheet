/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []*/

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
ListNode *mergeList(ListNode *l1, ListNode *l2)
{
    if (!l1)
    {
        return l2;
    }

    if (!l2)
    {
        return l1;
    }
    ListNode *newList = new ListNode();
    ListNode *curr = newList;
    while (l1 and l2)
    {
        if (l1->val < l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    if (l1)
    {
        curr->next = l1;
    }
    if (l2)
    {
        curr->next = l2;
    }
    return newList->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int n = lists.size();
    if (n == 0)
    {
        return NULL;
    }
    if (n == 1)
    {
        return lists[0];
    }
    ListNode *head = lists[0];

    for (int i = 1; i < n; i++)
    {
        head = mergeList(head, lists[i]);
    }
    return head;
}
int main()
{
    return 0;
}