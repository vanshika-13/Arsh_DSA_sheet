/*Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.

To maintain the order, keep swapping the adjacent nodes of the linked list (whenever required) to get the desired output.  

Example 1:

Input:
LinkedList: 1->2->3->4 
Output: 1 3 2 4
Example 2:

Input:
LinkedList: 11->15->20->5->10
Output: 11 20 5 15 10
Explanation: In the given linked list,
after arranging them as 11 < 20 > 5
< 15 > 10 in the pattern as asked above.*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *zigZag(Node *head)
{
    // your code goes here
    if (!head || head->next == NULL)
    {
        return head;
    }
    bool flag = 1;
    Node *temp = head;
    while (temp->next)
    {
        if (flag)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp->data, temp->next->data);
            }
            flag = 0;
        }
        else
        {
            if (temp->data < temp->next->data)
            {
                swap(temp->data, temp->next->data);
            }

            flag = 1;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    return 0;
}