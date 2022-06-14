/*Given the head of a linked list, remove the nth node from the end of the list and return its head.



Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]*/

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
ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    count = count - n;
    temp = dummy;

    while (count > 0)
    {
        temp = temp->next;
        count--;
    }

    ListNode *d = temp->next;
    temp->next = d->next;
    delete (d);

    return dummy->next;
}

/*ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        ListNode* fast=head, *slow = head;
        for(int i=0;i<n;i++)
            fast = fast->next;
        if(!fast)
            return head->next;
        
        while(fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
    */
int main()
{
    return 0;
}