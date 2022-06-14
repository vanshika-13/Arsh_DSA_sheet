/*Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]*/

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
/*Solution using merge-sort. This solution requires no extra space but its time complexity is O(n x logn) since it uses concepts of recursion merge-sort.

    ListNode* sortList(ListNode* head) {
        if(head==0 || head->next==0)return head;
        ListNode *slow=head,*fast=head,*temp=0;
        while(fast!=0 && fast->next!=0){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=0;
        ListNode *l1=sortList(head),*l2=sortList(slow);
        return mergeLists(l1,l2);
    }

    ListNode* mergeLists(ListNode *l1,ListNode *l2){
        ListNode *curr=new ListNode(0),*ptr=curr;
      while(l1!=0 && l2!=0){
            if(l1->val<=l2->val){
                ptr->next=l1;
                l1=l1->next;
            }else{
                ptr->next=l2;
                l2=l2->next;
            }
          ptr=ptr->next;
        }
        if(l1!=0){
            ptr->next=l1;l1=l1->next;
        }
        if(l2!=0){
            ptr->next=l2;l2=l2->next;
        }
        return curr->next;
    }
};*/

// In this solution, we use extra-space in the form of a vector. Push all the nodes of the linked-list onto that vector, sort the vector and make a new linked list and return the head of the new linked-list.
ListNode *sortList(ListNode *head)
{
    if (head == NULL)
        return NULL;
    vector<int> v;
    ListNode *curr = head;
    while (curr != NULL)
    {
        v.push_back(curr->val);
        curr = curr->next;
    }
    sort(v.begin(), v.end());
    ListNode *head1 = new ListNode(v[0]);
    ListNode *temp = head1;
    for (int i = 1; i < v.size(); i++)
    {
        head1->next = new ListNode(v[i]);
        head1 = head1->next;
    }
    return temp;
}
int main()
{
    return 0;
}