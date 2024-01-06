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
    ListNode* reverseList(ListNode* head){
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
    
    void merge(ListNode* l1, ListNode* l2){
        while (l2) {
          ListNode* next = l1->next;
          l1->next = l2;
          l1 = l2;
          l2 = next;
        }
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
        
        ListNode* l1=head;
        ListNode* l2=reverseList(slow);

        // Merging two lists l1 and l2;
        merge(l1,l2);
    }
};