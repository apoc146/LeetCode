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
    ListNode* reverList(ListNode* head){
        if(head==NULL)return head;
        
        ListNode* temp=NULL;
        ListNode* prev=NULL;
        ListNode* cur=head;
        
        while(cur!=NULL){
            temp=prev;
            prev=cur;
            cur=cur->next;
            prev->next=temp;
        }
        
        return prev;
    }
    
    
    void reorderList(ListNode* head) {
    
        if(head->next==NULL)return ;
        //find middle element;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        
        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        
        ListNode* returnHead;
        ListNode* l1=head;
        ListNode* l2=reverList(slow);
        ListNode* t1=l1;
        ListNode* t2=l2;
        returnHead=head;
        
        // Merging two lists l1 and l2;
        
        while(l1!=NULL){
            t1=l1->next;
            l1->next=l2;
            l1=t1;
            
            if(l1==NULL){
                break;
            }
            
            t2=l2->next;
            l2->next=l1;
            l2=t2;
        }
    }
};