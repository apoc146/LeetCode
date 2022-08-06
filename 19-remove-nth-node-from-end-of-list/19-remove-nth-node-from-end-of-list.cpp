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

/**
* In the tail of the recursion, delete the element
*/

class Solution {
public:
    ListNode* foo(ListNode* head, int n, int* t, ListNode** prev, ListNode** cur){
        if(head==NULL){
            return NULL;
        }
        
        foo(head->next, n, t, cur, &((*cur)->next));
        //retracting starts here
        *t=*t+1;
        if(*t==n){
            if(*prev == NULL){
                head=head->next;
                //cant deallocate memeory in recursion stack
                // free(*cur);
            }else{
                (*prev)->next=(*cur)->next;
            }
        }
        return head;
    }
    
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        
        if(head->next==NULL && n==1){
            return NULL;
        }

        ListNode* prev=NULL;
        ListNode* cur=head;
        
        int t=0;
        head=foo(head,n,&t,&prev,&cur);
        return head;
    }
};