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
    ListNode* reverse(ListNode* head, ListNode* cur){
        if(cur!=NULL and cur->next==NULL){
            return cur;
        }
        
        ListNode* last=reverse(head,cur->next);
        cur->next->next=cur;
        cur->next=NULL;
        return last;         
    }
    
    ListNode* foo(ListNode* head, int k){
        int trueK=k;
        ListNode* fast=head;
        ListNode* slow=fast;
        ListNode* prev=NULL;

        while(k>0 and fast!=NULL){
            --k;
            prev=fast;
            fast=fast->next;
        }
        
         if(k==0 and fast==NULL){
             return reverse(head, head);
         }

        if(fast==NULL){
            return head;
        }
        //lets cutt off that part of ll [1,2]
        ListNode* newhead=fast;
        ListNode* last=NULL;
        prev->next=NULL;
        last=reverse(slow,slow);
        head->next=foo(newhead,trueK);
        return last;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=foo(head,k);
        return ans;
    }
};
