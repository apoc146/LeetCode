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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        if(list1==NULL && list2){
            return list2;
        }
        
        if(list1 && list2==NULL){
            return list1;
        }
        
        ListNode* head= new ListNode(0);
        ListNode* cur=head;
        while(list1 && list2){
            if(list1->val <= list2->val){
                cur->val=list1->val;
                list1=list1->next;
            }else{
                cur->val=list2->val;
                list2=list2->next;
            }
            cur->next=new ListNode(0);
            cur=cur->next;
        }
        
        if(list1==NULL){
            cur->val=list2->val;
            cur->next=list2->next;
        }else{
            cur->val=list1->val;
            cur->next=list1->next;
        }
        
        return head;
    }
};