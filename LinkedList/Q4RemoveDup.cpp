/*Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.*/

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
ListNode *middleNode(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    if ((fast->next->next) == NULL)
    {
        return fast->next;
    }
    else
    {
        while ((fast->next) != NULL && (fast->next->next) != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next != NULL)
        {
            return slow->next;
        }
        return slow;
    }
}
int main()
{
    return 0;
}