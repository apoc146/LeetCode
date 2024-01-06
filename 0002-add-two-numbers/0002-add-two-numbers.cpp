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
        ListNode* head=new ListNode;
        ListNode* cur=head;
        
        int carryVal=0;
        while(l1!=NULL || l2!=NULL){
            int val1= l1? l1->val:0;
            int val2= l2? l2->val:0;
            int sumVal=val1+val2+carryVal;
            if(sumVal>=10){
                carryVal=1;
                sumVal=sumVal%10;
            }else{
                carryVal=0;
            }
            
            cur->next= new ListNode(sumVal);
            cur=cur-> next;
            if(l1){
                l1=l1->next;
            }
            if(l2){
                l2=l2->next;
            }
        }

        if(carryVal>0){
            cur->next = new ListNode(carryVal);
        }
        return head->next;
    }
};