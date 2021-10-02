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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur=head;
        ListNode* prev;
        ListNode* temp=NULL;
        int c=0;
        while(cur and c!=k)
        {
            cur=cur->next;
            c++;
        }
        if(c==k)
        {
            prev=reverseKGroup(cur,k);
            cur=head;
            while(c--)
            {
                temp=cur->next;
                cur->next=prev;
                prev=cur;
                cur=temp;
            }
            //This is important as last remain does not enter into loop
            head=prev;
        }
        return head;
    }
};
