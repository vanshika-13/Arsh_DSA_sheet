/*A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
Node *copyRandomList(Node *head)
{

    if (!head)
        return NULL;

    //         Node* temp1 = head;
    //         Node* newhead = new Node(temp1->val);
    //         Node* temp = newhead;
    //         temp1 = temp1->next;
    //         unordered_map<Node*,Node*> map;
    //         map[head] = newhead;

    //         while(temp1)
    //         {
    //             temp->next = new Node(temp1->val);
    //             map[temp1] = temp->next;
    //             temp = temp->next;
    //             temp1 = temp1->next;
    //         }

    //         temp1 = head;
    //         temp = newhead;

    //         while(temp1)
    //         {
    //             temp->random = map[temp1->random];
    //             temp1 = temp1->next;
    //             temp = temp->next;
    //         }

    //         return newhead;

    Node *curr = head;
    Node *nxt = head->next;
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (curr)
    {
        Node *newnode = new Node(curr->val);
        temp->next = curr;
        curr->next = newnode;
        temp = newnode;
        curr = nxt;
        if (nxt)
            nxt = nxt->next;
    }

    curr = head;
    dummy->next = dummy->next->next;
    temp = dummy->next;
    while (curr)
    {
        temp->random = NULL;
        if (curr->random)
            temp->random = curr->random->next;
        curr = temp->next;
        if (curr)
            temp = curr->next;
    }

    curr = head;
    temp = dummy->next;
    while (curr)
    {
        curr->next = temp->next;
        if (temp->next)
            temp->next = temp->next->next;
        curr = curr->next;
        temp = temp->next;
    }
    return dummy->next;
}
// Commented code is using hashmap to solve this problem and the uncommented is the optimal approach without using space to save original nodes.First loop is used to modify the linked list.Second loop is used to setup the random pointers.Third loop is used to remodify the linked list to its original form.
int main()
{
    return 0;
}