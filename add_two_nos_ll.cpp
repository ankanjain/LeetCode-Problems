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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode *head=new ListNode();
        ListNode *start=head;
        ListNode *temp=head;
        temp->next=NULL;
        while(l1 || l2)
        {   int sum=0;
            if(l1) {sum+=l1->val;l1=l1->next;}
            if(l2) {sum+=l2->val;l2=l2->next;}
            sum+=carry;
            carry=sum/10;
            ListNode *temp2=new ListNode(sum%10);
            temp->next=temp2;
            temp=temp2;
        }
        if(carry)
        {
         ListNode *temp2=new ListNode(carry);
            temp->next=temp2;
            temp2->next=NULL;
        }
        return start->next;
        
    }
};
