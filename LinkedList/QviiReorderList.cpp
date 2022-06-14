/*You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]*/

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
void f(ListNode *head, int n)
{
    if (n < 3)
    {
        return;
    }
    else
    {
        ListNode *temp = head;
        ListNode *secondFirst = head->next;
        ListNode *last;
        ListNode *seclast;
        int c = 1;
        while (temp)
        {
            if (c == n)
            {
                last = temp;
            }
            if (c == (n - 1))
            {
                seclast = temp;
            }
            c++;
            temp = temp->next;
        }

        temp = head;
        temp->next = last;
        seclast->next = NULL;
        last->next = secondFirst;
        f(secondFirst, n - 2);
    }
}
void reorderList(ListNode *head)
{
    int l = 0;
    ListNode *temp = head;
    while (temp)
    {
        l++;
        temp = temp->next;
    }
    f(head, l);
}
int main()
{
    return 0;
}