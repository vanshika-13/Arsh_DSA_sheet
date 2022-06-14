/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]*/

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
ListNode *deleteDuplicates(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *dummy = new ListNode(-1);
    ListNode *curr = dummy;
    while (head)
    {
        int temp = head->val;
        if (head->next && head->next->val == head->val)
        {
            while (head && head->val == temp)
                head = head->next;
        }
        else
        {
            curr->next = head;
            curr = head;
            head = head->next;
        }
    }
    curr->next = NULL;
    return dummy->next;
}
int main()
{
    return 0;
}