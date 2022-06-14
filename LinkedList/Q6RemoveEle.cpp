/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:


Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]*/

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
ListNode *removeElements(ListNode *head, int val)
{
    if (!head || (!head->next && head->val != val))
    {
        return head;
    }
    else if (!head->next && head->val == val)
    {
        return NULL;
    }
    else
    {

        ListNode *prev = head;
        ListNode *temp = head;
        // temp = temp->next;
        while (temp != NULL)
        {
            if (temp->val == val)
            {
                prev->next = temp->next;
            }
            else
            {
                prev = temp;
            }
            temp = temp->next;
        }
    }
    if (head->val == val)
    {
        head = head->next;
    }
    return head;
}
int main()
{
    return 0;
}