/*Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 */

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
bool isPalindrome(ListNode *head)
{
    if (head->next == NULL)
    {
        return true;
    }
    ListNode *temp = head;
    string l;
    while (temp)
    {
        l.push_back(temp->val);
        temp = temp->next;
    }
    int n = l.length();
    for (int i = 0; i < n / 2; i++)
    {
        if (l[i] != l[n - i - 1])
        {
            return false;
        }
    }

    return true;
}

/*
bool isPalindrome(ListNode* head) {
       if(head==NULL || head->next==NULL)
            return true;
        
        ListNode* slow=head, *fast = head;
        ListNode* dummy=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        slow->next = reverseList(slow->next);
        slow= slow->next;
        
        while(slow!=NULL){
            if(head->val != slow->val)
                return false;
            head= head->next;
            slow = slow->next;   
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        if(head==NULL) return NULL;
        ListNode* newhead = NULL;
        while(head!=NULL){
            ListNode* next= head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
    }
*/
int main()
{
    return 0;
}