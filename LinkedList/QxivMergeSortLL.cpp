/*Merge Sort in linked List*/

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
ListNode *getMid(ListNode *head)
{
    ListNode *fast, *slow, *prev = head;
    fast = slow = head;
    while (fast && fast->next)
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    prev->next = NULL;
    return slow;
}
ListNode *Merge(ListNode *list1, ListNode *list2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            curr->next = list1;
            list1 = list1->next;
        }
        else
        {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    if (list1)
    {
        curr->next = list1;
    }
    else
        curr->next = list2;
    return dummy->next;
}
ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *Mid = getMid(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(Mid);
    return Merge(left, right);
}
int main()
{
    return 0;
}