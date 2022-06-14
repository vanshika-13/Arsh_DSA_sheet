/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]*/

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
ListNode *partition(ListNode *head, int x)
{
    queue<ListNode *> s;
    ListNode *prev = new ListNode(0), *p = head, *dummy = prev;
    while (p)
    {
        if (p->val < x)
        {
            prev->next = p;
            prev = p;
        }
        else
        {
            s.push(p);
        }

        p = p->next;
    }
    while (!s.empty())
    {
        // cout<<s.front()->val<<s.size()<<endl;
        prev->next = s.front();
        prev = prev->next;
        s.pop();
    }
    prev->next = nullptr;
    return dummy->next;
}
int main()
{
    return 0;
}