/*Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]*/

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
ListNode *rev(ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    ListNode *prev = NULL;
    ListNode *next = NULL;
    ListNode *curr = head;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    int count = 1;
    while (count != left)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }
    ListNode *start = curr;
    while (count != right)
    {
        curr = curr->next;
        count++;
    }
    ListNode *rest = curr->next;
    curr->next = NULL;
    ListNode *newhead = rev(start);
    if (prev != NULL)
    {
        prev->next = newhead;
    }
    curr = newhead;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = rest;
    if (left == 1)
    {
        return newhead;
    }
    return head;
}


/*ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy_head = new ListNode(-1, head);
        ListNode* pre = dummy_head;
        ListNode* tail= NULL;
        ListNode* temp = NULL;
        for (int i = 0; i < left - 1; i++)
           { pre = pre->next;}
        tail = pre->next;
        for (int i = 0; i < right - left; i++) {
            ListNode* temp = prev->next;
            prev->next = tail->next;
            tail->next = tail->next->next;
            prev->next->next = temp;
        }
        return dummy_head->next;
    }*/
int main()
{
    return 0;
}