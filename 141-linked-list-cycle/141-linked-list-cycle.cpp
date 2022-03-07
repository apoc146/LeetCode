/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode* slow=NULL;
        ListNode* fast=NULL;
        
        if(head==NULL){
            return false;
        }
        
        slow=head;
        fast=head->next;
        
        bool res=false;
        while(fast!=NULL && fast->next!=NULL){
            if(slow==fast){
                res=true;
                break;
            }else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return res;
    }
};