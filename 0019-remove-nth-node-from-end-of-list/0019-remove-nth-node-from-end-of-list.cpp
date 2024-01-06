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
    void foo(ListNode** head, ListNode** prev, ListNode** cur, int n, int* cnt){
        if(*cur==NULL){
            return;
        }
        
        foo(head,cur,&((*cur)->next),n,cnt);
        *cnt= *cnt+1;
        if(n==*cnt){
            if(*prev==NULL){
                *head=(*cur)->next;
            }else{
                (*prev)->next=(*cur)->next;

            }
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        
        if(n==1 and head->next==NULL){
            return NULL;
        }
        int count=0;
        ListNode* prev=NULL;
        ListNode* cur=head;
        foo(&head,&prev,&cur,n,&count);
        return head;
    }
};