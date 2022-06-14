/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:


The test cases are generated such that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Custom Judge:

The inputs to the judge are given as follows (your program is not given these inputs):

intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.



Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.*/

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *t1 = headA;
    ListNode *t2 = headB;
    int l1 = 1;
    int l2 = 1;
    while (t1->next)
    {
        l1 += 1;
        t1 = t1->next;
    }
    while (t2->next)
    {
        l2 += 1;
        t2 = t2->next;
    }
    if (t1 != t2)
    {
        return NULL;
    }
    int move1 = max(0, l1 - l2);
    int move2 = max(0, l2 - l1);
    while (move1 > 0)
    {
        headA = headA->next;
        move1--;
    }
    while (move2 > 0)
    {
        headB = headB->next;
        move2--;
    }
    while (headA != headB)
    {
        headB = headB->next;
        headA = headA->next;
    }
    return headA;
}
int main()
{
    return 0;
}