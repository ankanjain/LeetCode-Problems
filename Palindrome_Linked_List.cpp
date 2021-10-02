/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL) slow=slow->next;
        ListNode* cur=slow;
        ListNode* prev=NULL;
        ListNode* temp=NULL;
        while(cur)
        {
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        temp=prev;
        ListNode* temp2=head;
        while(temp!=NULL)
        {
            if(temp2->val!=temp->val) return 0;
            temp2=temp2->next;
            temp=temp->next;
        }
        return 1;
        
    }
};
